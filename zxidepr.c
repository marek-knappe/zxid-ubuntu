/* zxidepr.c  -  Handwritten functions for client side EPR and bootstrap handling
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidepr.c,v 1.19 2009-11-29 12:23:06 sampo Exp $
 *
 * 5.2.2007, created --Sampo
 * 7.10.2008, added documentation --Sampo
 *
 * See also: zxidsimp.c (attributes to LDIF), and zxida7n.c (general attribute querying)
 *
 * N.B. Like session storage, the epr cache makes case preserving assumption about
 * underlying filesystem. Case insensitive filesystem will insignificantly increase
 * chances of naming collitions.
 *
 * See also zxiddi.c for discovery server code.
 */

#include "platform.h"  /* for dirent.h */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-ns.h"
#include "c/zx-a-data.h"

/*() Fold service type (or any URN or URL) to file name. */

/* Called by:  zxid_di_query, zxid_find_epr, zxid_nice_sha1, zxid_reg_svc */
void zxid_fold_svc(char* p, int len)
{
  for (; *p && len; ++p, --len)
    if (ONE_OF_6(*p, ':','/',',','?','&','='))
      *p = '_';
}

/*() Compute (and fold) unique nice sha1 name according to NAME,SHA1
 *
 * This name format is designed to ensure unique name, while
 * maintainting human readability. This is
 * useful in the common case where WSC wants to call a specific type of web service.
 *
 * cf::  ZXID configuration object, also used for memory allocation
 * buf:: result parameter. The buffer, which must have been allocated, will be
 *     modified to have the path. The path will be nul terminated.
 * buf_len:: The length of the buf (including nul termination), usually sizeof(buf)
 * name:: Often Service name or SP Entity ID
 * cont:: content of EPR or the SP EntityID, used to compute sha1 hash that becomes part
 *     of the file name
 * ign_prefix:: How many characters to ignore from beginning of name: 0 or 7 (http://)
 * return:: 0 on success (the real return value is returned via ~buf~ result parameter) */

/* Called by:  zxid_add_fed_tok2epr, zxid_epr_path, zxid_idp_map_nid2uid, zxid_imreq, zxid_nidmap_do x2, zxid_sso_issue_a7n */
int zxid_nice_sha1(zxid_conf* cf, char* buf, int buf_len,
		   struct zx_str* name, struct zx_str* cont, int ign_prefix)
{
  char* p;
  char* q;
  int len;
  char sha1_cont[28];
  sha1_safe_base64(sha1_cont, cont->len, cont->s);
  sha1_cont[27] = 0;
  len = snprintf(buf, buf_len, "%.*s,%s",
		 MAX(name->len-ign_prefix,0), name->s+ign_prefix, sha1_cont);
  buf[buf_len-1] = 0; /* must terminate manually as on win32 termination is not guaranteed */
  
  /* 012345678
   * http://
   * https://   */

  /* Sanity scan the name part (svc or eid), folding dangerous chars to _. */

  p = buf;
  q = MIN(p + MAX(name->len-7,0), buf + buf_len);
  zxid_fold_svc(p, q-p);
  return 0;
}

/*() Compute (and fold) unique EPR name according to /var/zxid/ses/SESID/SVC,SHA1
 *
 * This name format is designed to ensure unique name for each EPR, while
 * also making it easy to determine the service type from the name. This is
 * useful in the common case where WSC wants to call a specific type of web service.
 *
 * cf::  ZXID configuration object, also used for memory allocation
 * dir:: Directory, such as "ses/"
 * sid:: Session ID whose EPR cache the file is/will be located
 * buf:: result parameter. The buffer, which must have been allocated, will be
 *     modified to have the path. The path will be nul terminated.
 * buf_len:: The length of the buf (including nul termination), usually sizeof(buf)
 * svc:: Service name
 * cont:: content of EPR, used to compute sha1 hash that becomes part of the file name
 * return:: 0 on success (the real return value is returned via ~buf~ result parameter)
 *
 * N.B. This function relies on specific, ANSI documented, functioning
 * of snprintf(3) library function. Unfortunately, it has been found that
 * on some platforms this function only works correctly in the 'C' locale. If
 * you suspect this to be the case, you may want to try
 *
 *    export LANG=C
 *
 * especially if you get errors about multibyte characters. */

/* Called by:  zxid_cache_epr, zxid_snarf_eprs_from_ses */
int zxid_epr_path(zxid_conf* cf, char* dir, char* sid,
		  char* buf, int buf_len, struct zx_str* svc, struct zx_str* cont)
{
  int len = snprintf(buf, buf_len, "%s%s%s/", cf->path, dir, sid);
  buf[buf_len-1] = 0; /* must terminate manually as on win32 termination is not guaranteed */
  if (len <= 0) {
    perror("snprintf");
    ERR("Broken snprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", len);
    if (buf && buf_len > 0)
      buf[0] = 0;
    return 1;
  }
  return zxid_nice_sha1(cf, buf+len, buf_len - len, svc, cont, 0);
}

/*() Serialize EPR data structure to XML and write it to session's EPR cache under
 * file name that is both unique and indicates the service type.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file will be located
 * epr:: XML data structure representing the EPR
 * return:: 1 on success, 0 on failure */

/* Called by:  main, zxid_get_epr, zxid_snarf_eprs */
int zxid_cache_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr)
{
  fdtype fd;
  struct zx_str* ss;
  char path[ZXID_MAX_BUF];
  
  if (!ses || !ses->sid || !ses->sid[0]) {
    ERR("Valid session required %p", ses);
    return 0;
  }
  if (!epr || !epr->Metadata || !epr->Metadata->ServiceType) {
    ERR("EPR is not a ID-WSF 2.0 Bootstrap: no Metadata %p", epr);
    return 0;
  }
  ss = zx_EASY_ENC_elem(cf->ctx, &epr->gg);
  if (!ss) {
    ERR("Encoding EndpointReference failed %p", epr);
    return 0;
  }
  zxid_epr_path(cf, ZXID_SES_DIR, ses->sid, path, sizeof(path),
		ZX_GET_CONTENT(epr->Metadata->ServiceType), ss);
  //fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
  fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "zxid_cache_epr", 1, "%s", path);
  if (fd == BADFD) {
    perror("open for write cache_epr");
    ERR("EPR path(%s) creation failed", path);
  } else if (write_all_fd(fd, ss->s, ss->len) == -1) {
    perror("Trouble writing EPR");
  }
  close_file(fd, (const char*)__FUNCTION__);
  zx_str_free(cf->ctx, ss);
  return 1;
}

/*() Look into attribute statements of a SSO assertion and extract anything
 * that looks like EPR, storing results in the session for later reference.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache will be populated
 *
 * N.B. This approach ignores the official attribute names totally. Anything
 * that looks like an EPR and that is strcturally in right place will work.
 * Typical name /var/zxid/ses/SESID/SVCTYPE,SHA1 */

/* Called by:  zxid_as_call_ses, zxid_snarf_eprs_from_ses */
void zxid_snarf_eprs(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr)
{
  struct zx_str* ss;
  struct zx_str* urlss;
  int wsf20 = 0;
  for (; epr && epr->gg.g.tok == zx_a_EndpointReference_ELEM; epr = (zxid_epr*)epr->gg.g.n) {
    ss = ZX_GET_CONTENT(epr->Metadata->ServiceType);
    urlss = ZX_GET_CONTENT(epr->Address);
    D("%d: EPR svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
    if (zxid_cache_epr(cf, ses, epr)) {
      ++wsf20;
      D("%d: EPR cached svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
    }
  }
  D("TOTAL wsf20 EPRs snarfed: %d", wsf20);
}

/*() Look into attribute statements of a SSO assertion and extract anything
 * that looks like EPR, storing results in the session for later reference.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache will be populated
 *
 * N.B. This approach ignores the official attribute names totally. Anything
 * that looks like an EPR and that is strcturally in right place will work.
 * Typical name /var/zxid/ses/SESID/SVCTYPE,SHA1 */

/* Called by:  zxid_sp_anon_finalize, zxid_sp_sso_finalize, zxid_wsc_validate_resp_env, zxid_wsp_validate */
void zxid_snarf_eprs_from_ses(zxid_conf* cf, zxid_ses* ses)
{
  struct zx_sa_AttributeStatement_s* as;
  struct zx_sa_Attribute_s* at;
  struct zx_sa_AttributeValue_s* av;
  int wsf11 = 0;
  
  D_INDENT("snarf_eprs: ");
  zxid_get_ses_sso_a7n(cf, ses);
  if (ses->a7n)
    for (as = ses->a7n->AttributeStatement;
	 as && as->gg.g.tok == zx_sa_AttributeStatement_ELEM;
	 as = (struct zx_sa_AttributeStatement_s*)as->gg.g.n)
      for (at = as->Attribute;
	   at && at->gg.g.tok == zx_sa_Attribute_ELEM;
	   at = (struct zx_sa_Attribute_s*)at->gg.g.n)
	for (av = at->AttributeValue;
	     av && av->gg.g.tok == zx_sa_AttributeValue_ELEM;
	     av = (struct zx_sa_AttributeValue_s*)av->gg.g.n) {
	  zxid_snarf_eprs(cf, ses, av->EndpointReference);
	  if (av->ResourceOffering) {
	    ++wsf11;
	    D("Detected wsf11 resource offering. %d", wsf11);
#if 0	    
	    ss = zx_EASY_ENC_elem(cf->ctx, &av->ResourceOffering->gg);
	    
	    zxid_epr_path(cf, ZXID_SES_DIR, ses->sid, path, sizeof(path),
			  ZX_GET_CONTENT(av->EndpointReference->Metadata->ServiceType), ss);
	    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	    if (fd == -1) {
	      perror("open for write epr");
	      ERR("EPR path(%s) creation failed", path);
	    } else if (write_all_fd(fd, ss->s, ss->len) == -1) {
	      perror("Trouble writing EPR");
	      close__file(fd, __FUNCTION__);
	    }
	    zx_str_free(cf->ctx, ss);
#endif
	  }
	}
#if 0
  if (ses->a7n12)
    for (as = ses->a7n->AttributeStatement;
	 as && as->gg.g.tok == zx_sa11_AttributeStatement_ELEM;
	 as = (struct zx_sa11_AttributeStatement_s*)as->gg.g.n)
      for (at = as->Attribute;
	   at && at->gg.g.tok == zx_sa11_Attribute_ELEM;
	   at = (struct zx_sa11_Attribute_s*)at->gg.g.n)
	for (av = at->AttributeValue;
	     av && av->gg.g.tok == zx_sa11_AttributeValue_ELEM;
	     av = (struct zx_sa11_AttributeValue_s*)av->gg.g.n) {
	}
#endif
  D_DEDENT("snarf_eprs: ");
}

/*() Search the EPRs cached under the session for a match. First directory is searched
 * for files whose name starts by service type. These files are opened and parsed
 * as EPR and further checks are made. The nth match is returned. 1 means first.
 * Typical name: /var/zxid/ses/SESID/SVCTYPE,SHA1
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file is searched
 * svc:: Service type (usually a URN)
 * url:: (Optional) If provided, this argument has to match either
 *     the ProviderID, EntityID, or actual service endpoint URL.
 * di_opt:: (Optional) Additional discovery options for selecting the service, query string format
 * action:: (Optional) The action, or method, that must be invocable on the service
 * n:: How manieth matching instance is returned. 1 means first
 * return:: EPR data structure (or linked list of EPRs) on success, 0 on failure
 *
 * See also: zxid_print_session() in zxcall.c */

/* Called by:  main x2, zxid_get_epr x2 */
zxid_epr* zxid_find_epr(zxid_conf* cf, zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n)
{
  struct zx_root_s* r;
  struct zx_str* ss;
  struct zx_str* pi;
  int len, epr_len;
  char path[ZXID_MAX_BUF];
  char* epr_buf;  /* MUST NOT come from stack. */
  DIR* dir;
  struct dirent * de;
  zxid_epr* epr = 0;
  struct zx_a_Metadata_s* md = 0;  
  D_INDENT("find_epr: ");

#if 1
  if (!svc || !*svc) {
    /* *** Relax this to allow discovery of multiple or all service types */
    ERR("Must supply service type %p", svc);
    D_DEDENT("find_epr: ");
    return 0;
  }
#endif
  
  if (!name_from_path(path, sizeof(path), "%s" ZXID_SES_DIR "%s", cf->path, ses->sid)) {
    D_DEDENT("find_epr: ");
    return 0;
  }
  
  D("Looking in session dir(%s) svc(%s) pses=%p", path, svc, ses);
  dir = opendir(path);
  if (!dir) {
    perror("opendir to find epr in session");
    ERR("Opening session for find epr by opendir failed path(%s) sesptr=%p", path, ses);
    D_DEDENT("find_epr: ");
    return 0;
  }

  len = strlen(svc);
  len = MIN(len, sizeof(path)-1);
  memcpy(path, svc, len);
  path[len] = 0;
  zxid_fold_svc(path, len);
  D("Folded path prefix(%.*s) len=%d n=%d", len, path, len, n);
  
  while (de = readdir(dir)) {
    D("%d Considering file(%s)", n, de->d_name);
    if (de->d_name[0] == '.')  /* . .. and "hidden" files */
      continue;
    if (de->d_name[strlen(de->d_name)-1] == '~')  /* Ignore backups from hand edited EPRs. */
      continue;
    if (memcmp(de->d_name, path, len) || de->d_name[len] != ',')
      continue;
    D("%d Checking EPR content file(%s)", n, de->d_name);
    epr_buf = read_all_alloc(cf->ctx, "find_epr", 1, &epr_len,
			     "%s" ZXID_SES_DIR "%s/%s", cf->path, ses->sid, de->d_name);
    if (!epr_buf)
      continue;
    
    r = zx_dec_zx_root(cf->ctx, epr_len, epr_buf, "find epr");
    if (!r || !r->EndpointReference) {
      ERR("No EPR found. Failed to parse epr_buf(%.*s)", epr_len, epr_buf);
      continue;
    }
    epr = r->EndpointReference;
    ZX_FREE(cf->ctx, r);
    if (!ZX_SIMPLE_ELEM_CHK(epr->Address)) {
      ERR("The EPR does not have <Address> element. Rejected. %p", epr->Address);
      continue;
    }
    /* *** add ID-WSF 1.1 handling */
    md = epr->Metadata;
    if (svc &&
	(!md || !ZX_SIMPLE_ELEM_CHK(md->ServiceType))) {
      ERR("No Metadata %p or ServiceType. Failed to parse epr_buf(%.*s)", md, epr_len, epr_buf);
      continue;
    }
    ss = ZX_GET_CONTENT(md->ServiceType);
    if (svc && (!ss || len != ss->len || memcmp(svc, ss->s, len))) {
      D("%d Internal svctype(%.*s) does not match desired(%s). Reject.", n, ss?ss->len:0, ss?ss->s:"", svc);
      continue;
    }
    
    ss = ZX_GET_CONTENT(epr->Address);
    if (url && (!ss || strlen(url) != ss->len || memcmp(url, ss->s, ss->len))) {
      pi = md?ZX_GET_CONTENT(md->ProviderID):0;
      if (pi && (strlen(url) != pi->len || memcmp(url, pi->s, pi->len))) {
	D("%d ProviderID(%.*s) or endpoint URL(%.*s) does not match desired url(%s). Reject.", n, pi->len, pi->s, ss?ss->len:0, ss?ss->s:"", url);
	continue;
      }
    }

    /* *** Evaluate di_opt */

    /* *** Evaluate action */
    
    if (--n)
      continue;
    
    D("%d Found svc(%s) url(%.*s)", n, STRNULLCHK(svc), ZX_GET_CONTENT_LEN(epr->Address), ZX_GET_CONTENT_S(epr->Address));
    closedir(dir);
    D_DEDENT("find_epr: ");
    return epr;
  }
  closedir(dir);
  D_DEDENT("find_epr: ");
  return 0;
}

/*(i) First search epr cache, and if miss, go discover an EPR over the net.
 * This is the main work horse for WSCs wishing to call WSPs via EPR.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file will be searched
 * svc:: Service type (usually the namespace URN)
 * url:: (Optional) If provided, this argument has to match either
 *     the ProviderID, EntityID, or actual service endpoint URL.
 * di_opt:: (Optional) Additional discovery options for selecting the service, query string format
 * action:: (Optional) The action, or method, that must be invocable on the service
 * n:: How manieth matching instance is returned. 1 means first
 * return:: EPR data structure on success, 0 on failure (no discovery EPR in cache, or
 *     not found by the discovery service). If more than one were found, a linked list
 *     of EPRs is returned.
 */

/* Called by:  main x5, zxcall_main, zxid_call, zxid_map_identity_token */
zxid_epr* zxid_get_epr(zxid_conf* cf, zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n)
{
  int wsf20 = 0;
  struct zx_str* ss;
  struct zx_str* urlss;
  struct zx_e_Envelope_s* env;
  zxid_epr* epr;
  epr = zxid_find_epr(cf, ses, svc, url, di_opt, action, n);
  if (epr)
    return epr;
  if (n > 1)
    return 0;  /* Do not discover any more */
  
  INFO("%d Discovering svc(%s)...", n, STRNULLCHK(svc));
  env = zx_NEW_e_Envelope(cf->ctx,0);
  env->Body = zx_NEW_e_Body(cf->ctx, &env->gg);
  env->Body->Query = zxid_mk_di_query(cf, &env->Body->gg, svc, url, di_opt, 0);
  if (ses->deleg_di_epr) {
    epr = ses->deleg_di_epr;
    D("%d: Using delegated discovery EPR", n);
  } else {
    epr = zxid_find_epr(cf, ses, zx_xmlns_di, 0, 0, 0, n);
    if (!epr) {
      ERR("EPR for svc(%s) not found in cache and no discovery EPR in cache, thus no way to discover the svc.", STRNULLCHK(svc));
      return 0;
    }
  }
  env->Header = zx_NEW_e_Header(cf->ctx, &env->gg);
  env = zxid_wsc_call(cf, ses, epr, env, 0);
  if (env && env->Body) {
    if (env->Body->QueryResponse) {
      for (epr = env->Body->QueryResponse->EndpointReference;
	   epr && epr->gg.g.tok == zx_a_EndpointReference_ELEM;
	   epr = (zxid_epr*)ZX_NEXT(epr)) {
	ss = ZX_GET_CONTENT(epr->Metadata->ServiceType);
	urlss = ZX_GET_CONTENT(epr->Address);
	D("%d: EPR svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
	if (zxid_cache_epr(cf, ses, epr)) {
	  ++wsf20;
	  D("%d: EPR cached svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
	}
      }
      epr = env->Body->QueryResponse->EndpointReference;
    } else {
      epr = 0;
    }
    if (!epr)
      ERR("No end point discovered for svc(%s)", STRNULLCHK(svc));
    D("TOTAL wsf20 EPRs discovered: %d", wsf20);
    return epr;
  }
  ERR("discovery call failed envelope=%p", env);
  return 0;
}

/*() Accessor function for extracting endpoint address URL. */

/* Called by:  zxcall_main, zxid_print_session */
struct zx_str* zxid_get_epr_address(zxid_conf* cf, zxid_epr* epr) {
  if (!epr)
    return 0;
  return ZX_GET_CONTENT(epr->Address);
}

/*() Accessor function for extracting endpoint ProviderID. */

/* Called by:  zxcall_main, zxid_print_session */
struct zx_str* zxid_get_epr_entid(zxid_conf* cf, zxid_epr* epr) {
  if (!epr || !epr->Metadata)
    return 0;
  return ZX_GET_CONTENT(epr->Metadata->ProviderID);
}

/*() Accessor function for extracting endpoint Description (Abstract). */

/* Called by:  zxcall_main, zxid_print_session */
struct zx_str* zxid_get_epr_desc(zxid_conf* cf, zxid_epr* epr) {
  if (!epr || !epr->Metadata)
    return 0;
  return ZX_GET_CONTENT(epr->Metadata->Abstract);
}

/*() Accessor function for extracting security mechanism ID. */

/* Called by: */
struct zx_str* zxid_get_epr_secmech(zxid_conf* cf, zxid_epr* epr) {
  struct zx_elem_s* secmech;
  if (!epr || !epr->Metadata)
    return 0;
  if (!epr->Metadata->SecurityContext
      || (secmech = epr->Metadata->SecurityContext->SecurityMechID)) {
    ERR("Null EPR or EPR is missing Metadata, SecurityContext or SecurityMechID. %p", epr);
    return 0;
  }
  return ZX_GET_CONTENT(secmech);
}

/*() Set security mechanism ID.
 *
 * WARNING! Usually security mechanism ID is set by the
 * discovery process. Do not manipulate it unless you
 * know what you are doing. If security mechanism requires
 * a token, you need to arrange it separately, either via
 * discovery (recommended) or using zxid_set_epr_token() (if
 * you know what you are doing). */

/* Called by: */
void zxid_set_epr_secmech(zxid_conf* cf, zxid_epr* epr, const char* secmec) {
  if (!epr) {
    ERR("Null EPR. %p", epr);
    return;
  }
  if (!epr->Metadata)
    epr->Metadata = zx_NEW_a_Metadata(cf->ctx, &epr->gg);
  if (!epr->Metadata->SecurityContext)
    epr->Metadata->SecurityContext = zx_NEW_di_SecurityContext(cf->ctx, &epr->Metadata->gg);
  if (secmec) {
    epr->Metadata->SecurityContext->SecurityMechID
      = zx_dup_elem(cf->ctx, &epr->Metadata->SecurityContext->gg, zx_di_SecurityMechID_ELEM, secmec);
    INFO("SecurityMechID set to(%s)", secmec);
  } else {
    epr->Metadata->SecurityContext->SecurityMechID
      = zx_dup_elem(cf->ctx, &epr->Metadata->SecurityContext->gg, zx_di_SecurityMechID_ELEM, 0);
    INFO("SecurityMechID set null %d", 0);
  }
}

/*() Accessor function for extracting endpoint's (SAML2 assertion) token. */

/* Called by: */
zxid_tok* zxid_get_epr_token(zxid_conf* cf, zxid_epr* epr) {
  if (!epr || !epr->Metadata || !epr->Metadata->SecurityContext) {
    ERR("Null EPR or EPR is missing Metadata or SecurityContext. %p", epr);
    return 0;
  }
  return epr->Metadata->SecurityContext->Token;
}

/*() Set endpoint's (SAML2 assertion) token.
 *
 * WARNING! Generally you should not call this function. Instead
 * you should use discovery to obtain a token properly targeted
 * to the destination of the EPR. This includes correct audience
 * restriction, correct name id, and possible encryption of the
 * token so that only destination can open it. Perticular things
 * you should NOT do: just copy SSO token and pass it to web service
 * call (the audience restriction will be wrong); just copy
 * token that was received on WSP interface and use it on WSC interface. */

/* Called by: */
void zxid_set_epr_token(zxid_conf* cf, zxid_epr* epr, zxid_tok* tok) {
  if (!epr) {
    ERR("Null EPR. %p", epr);
    return;
  }
  if (!epr->Metadata)
    epr->Metadata = zx_NEW_a_Metadata(cf->ctx, &epr->gg);
  if (!epr->Metadata->SecurityContext)
    epr->Metadata->SecurityContext = zx_NEW_di_SecurityContext(cf->ctx, &epr->Metadata->gg);
  epr->Metadata->SecurityContext->Token = tok;
  INFO("EPR token set %p", tok);
}

/*() Constructor for "blank" EPR. Such EPR lacks security context so it is
 * not directly usable for identity web service calls. However, it could
 * be useful as a building block, or for non-idenity web service.
 * Also id, actor, and mustUnderstand fields need to be filled in by
 * other means (we may eventually have defaults for some of these). */

/* Called by: */
zxid_epr* zxid_new_epr(zxid_conf* cf, char* address, char* desc, char* entid, char* svctype)
{
  zxid_epr* epr = zx_NEW_a_EndpointReference(cf->ctx,0);
  if (address) {
    epr->Address = zx_NEW_a_Address(cf->ctx, &epr->gg);
    zx_add_content(cf->ctx, &epr->Address->gg, zx_dup_str(cf->ctx, address));
  }
  if (desc || entid || svctype) {
    epr->Metadata = zx_NEW_a_Metadata(cf->ctx, &epr->gg);
    if (desc)
      epr->Metadata->Abstract
	= zx_dup_elem(cf->ctx, &epr->Metadata->gg, zx_di_Abstract_ELEM, desc);
    if (entid)
      epr->Metadata->ProviderID
	= zx_dup_elem(cf->ctx, &epr->Metadata->gg, zx_di_ProviderID_ELEM, entid);
    if (svctype)
      epr->Metadata->ServiceType
	= zx_dup_elem(cf->ctx, &epr->Metadata->gg, zx_di_ServiceType_ELEM, svctype);
  }
  return epr;
}

/* Called by: */
zxid_epr* zxid_get_delegated_discovery_epr(zxid_conf* cf, zxid_ses* ses)
{
  return ses->deleg_di_epr;
}

/*(i) Allows explicit control over which Discovery Service is used, such
 * as selecting somebody else's Discovery Service. This allows delegated
 * access. */

/* Called by: */
void zxid_set_delegated_discovery_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr)
{
  ses->deleg_di_epr = epr;
}

/*() Get session's call invokation token. */

/* Called by: */
zxid_tok* zxid_get_call_invoktok(zxid_conf* cf, zxid_ses* ses) {
  if (!ses) {
    ERR("Null session. %p", ses);
    return 0;
  }
  return ses->call_invoktok;
}

/*() Set session's call invokation token. */

/* Called by: */
void zxid_set_call_invoktok(zxid_conf* cf, zxid_ses* ses, zxid_tok* tok) {
  if (!ses) {
    ERR("Null session. %p", ses);
    return;
  }
  ses->call_invoktok = tok;
}

/*() Get session's call target token. */

/* Called by: */
zxid_tok* zxid_get_call_tgttok(zxid_conf* cf, zxid_ses* ses) {
  if (!ses) {
    ERR("Null session. %p", ses);
    return 0;
  }
  return ses->call_tgttok;
}

/*() Set session's call target token. */

/* Called by: */
void zxid_set_call_tgttok(zxid_conf* cf, zxid_ses* ses, zxid_tok* tok) {
  if (!ses) {
    ERR("Null session. %p", ses);
    return;
  }
  ses->call_tgttok = tok;
}

/*() Serialize a token. */

/* Called by: */
struct zx_str* zxid_token2str(zxid_conf* cf, zxid_tok* tok) {
  if (!tok)
    return 0;
  return zx_EASY_ENC_elem(cf->ctx, &tok->gg);
}

/*() Parse string into token. */

/* Called by: */
zxid_tok* zxid_str2token(zxid_conf* cf, struct zx_str* ss) {
  struct zx_root_s* r;
  zxid_tok* tok;

  if (!ss || !ss->len || !ss->s)
    return 0;
  
  r = zx_dec_zx_root(cf->ctx, ss->len, ss->s, "decode token");
  if (!r) {
    ERR("Failed to parse token buf(%.*s)", ss->len, ss->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "BADXML", 0, "bad token");
    return 0;
  }
  if (r->Token)
    return r->Token;
  tok = zx_NEW_sec_Token(cf->ctx,0);
  tok->Assertion = r->Assertion;
  tok->EncryptedAssertion = r->EncryptedAssertion;
  tok->sa11_Assertion = r->sa11_Assertion;
  tok->ff12_Assertion = r->ff12_Assertion;
  return tok;
}

/*() Serialize an assertion. */

/* Called by: */
struct zx_str* zxid_a7n2str(zxid_conf* cf, zxid_a7n* a7n) {
  if (!a7n)
    return 0;
  return zx_EASY_ENC_elem(cf->ctx, &a7n->gg);
}

/*() Parse string into assertion. */

/* Called by: */
zxid_a7n* zxid_str2a7n(zxid_conf* cf, struct zx_str* ss) {
  struct zx_root_s* r;

  if (!ss || !ss->len || !ss->s)
    return 0;
  
  r = zx_dec_zx_root(cf->ctx, ss->len, ss->s, "decode a7n");
  if (!r) {
    ERR("Failed to parse assertion buf(%.*s)", ss->len, ss->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "BADXML", 0, "bad a7n");
    return 0;
  }
  return r->Assertion;
}

/*() Serialize a NameID. */

/* Called by: */
struct zx_str* zxid_nid2str(zxid_conf* cf, zxid_nid* nid) {
  if (!nid)
    return 0;
  return zx_EASY_ENC_elem(cf->ctx, &nid->gg);
}

/*() Parse string into NameID. */

/* Called by: */
zxid_nid* zxid_str2nid(zxid_conf* cf, struct zx_str* ss) {
  struct zx_root_s* r;

  if (!ss || !ss->len || !ss->s)
    return 0;
  
  r = zx_dec_zx_root(cf->ctx, ss->len, ss->s, "decode nid");
  if (!r) {
    ERR("Failed to parse NameID buf(%.*s)", ss->len, ss->s);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "BADXML", 0, "bad nid");
    return 0;
  }
  return r->NameID;
}

/*() Get session's invoker nameid. */

/* Called by: */
zxid_nid* zxid_get_nameid(zxid_conf* cf, zxid_ses* ses) {
  if (!ses)
    return 0;
  return ses->nameid;
}

/*() Set session's invoker nameid. */

/* Called by: */
void zxid_set_nameid(zxid_conf* cf, zxid_ses* ses, zxid_nid* nid) {
  if (!ses)
    return;
  ses->nameid = nid;
}

/*() Get session's target nameid. */

/* Called by: */
zxid_nid* zxid_get_tgtnameid(zxid_conf* cf, zxid_ses* ses) {
  if (!ses)
    return 0;
  return ses->tgtnameid;
}

/*() Set session's target nameid. */

/* Called by: */
void zxid_set_tgtnameid(zxid_conf* cf, zxid_ses* ses, zxid_nid* nid) {
  if (!ses)
    return;
  ses->tgtnameid = nid;
}

/*() Get session's invoker assertion. */

/* Called by: */
zxid_a7n* zxid_get_a7n(zxid_conf* cf, zxid_ses* ses) {
  if (!ses)
    return 0;
  return ses->a7n;
}

/*() Set session's invoker assertion. */

/* Called by: */
void zxid_set_a7n(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n) {
  if (!ses)
    return;
  ses->a7n = a7n;
}

/*() Get session's target assertion. */

/* Called by: */
zxid_a7n* zxid_get_tgta7n(zxid_conf* cf, zxid_ses* ses) {
  if (!ses)
    return 0;
  return ses->tgta7n;
}

/*() Set session's target assertion. */

/* Called by: */
void zxid_set_tgta7n(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n) {
  if (!ses)
    return;
  ses->tgta7n = a7n;
}

/* EOF  --  zxidepr.c */
