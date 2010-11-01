/* c/zx-sec-enc.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** enc-templ.c  -  XML encoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: enc-templ.c,v 1.27 2007-10-05 22:24:28 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006,  factored data structure walking to aux-templ.c --Sampo
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 26.8.2006, some CSE --Sampo
 ** 23.9.2006, added WO logic --Sampo
 ** 30.9.2007, improvements to WO encoding --Sampo
 ** 8.2.2010,  better handling of schema order encoding of unknown namespace prefixes --Sampo
 ** 27.10.2010, re-engineered namespace handling --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** N.B2: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-sec-data.h"
#include "c/zx-ns.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   sec_Token
#define EL_STRUCT zx_sec_Token_s
#define EL_NS     sec
#define EL_TAG    Token

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_sec_Token) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec:Token")-1 + 1 + sizeof("</sec:Token>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  len += zx_attr_so_len(c, x->id, sizeof("id")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ref, sizeof("ref")-1, &pop_seen);
  len += zx_attr_so_len(c, x->usage, sizeof("usage")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = &x->Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_Assertion(c, (struct zx_sa_Assertion_s*)se);
  for (se = &x->EncryptedAssertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)se);
  for (se = &x->sa11_Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)se);
  for (se = &x->ff12_Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)se);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec:Token", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec_Token) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec:Token");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);
  p = zx_attr_so_enc(p, x->usage, " usage=\"", sizeof(" usage=\"")-1);

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  
  for (se = &x->Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_Assertion(c, (struct zx_sa_Assertion_s*)se, p);
  for (se = &x->EncryptedAssertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)se, p);
  for (se = &x->sa11_Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)se, p);
  for (se = &x->ff12_Assertion->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)se, p);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec:Token>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec:Token", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec_Token) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec_Token(struct zx_ctx* c, struct zx_sec_Token_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec_Token(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec_Token(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   sec_TokenPolicy
#define EL_STRUCT zx_sec_TokenPolicy_s
#define EL_NS     sec
#define EL_TAG    TokenPolicy

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_sec_TokenPolicy) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec:TokenPolicy")-1 + 1 + sizeof("</sec:TokenPolicy>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  len += zx_attr_so_len(c, x->issueTo, sizeof("issueTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->type, sizeof("type")-1, &pop_seen);
  len += zx_attr_so_len(c, x->validUntil, sizeof("validUntil")-1, &pop_seen);
  len += zx_attr_so_len(c, x->wantDSEPR, sizeof("wantDSEPR")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = &x->NameIDPolicy->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_NameIDPolicy(c, (struct zx_sp_NameIDPolicy_s*)se);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec:TokenPolicy", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec_TokenPolicy) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec:TokenPolicy");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->issueTo, " issueTo=\"", sizeof(" issueTo=\"")-1);
  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);
  p = zx_attr_so_enc(p, x->wantDSEPR, " wantDSEPR=\"", sizeof(" wantDSEPR=\"")-1);

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  
  for (se = &x->NameIDPolicy->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_NameIDPolicy(c, (struct zx_sp_NameIDPolicy_s*)se, p);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec:TokenPolicy>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec:TokenPolicy", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec_TokenPolicy) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec_TokenPolicy(struct zx_ctx* c, struct zx_sec_TokenPolicy_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec_TokenPolicy(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec_TokenPolicy(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   sec_TransitedProvider
#define EL_STRUCT zx_sec_TransitedProvider_s
#define EL_NS     sec
#define EL_TAG    TransitedProvider

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_sec_TransitedProvider) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec:TransitedProvider")-1 + 1 + sizeof("</sec:TransitedProvider>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  len += zx_attr_so_len(c, x->confirmationURI, sizeof("confirmationURI")-1, &pop_seen);
  len += zx_attr_so_len(c, x->timeStamp, sizeof("timeStamp")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec:TransitedProvider", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec_TransitedProvider) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec:TransitedProvider");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->confirmationURI, " confirmationURI=\"", sizeof(" confirmationURI=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec:TransitedProvider>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec:TransitedProvider", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec_TransitedProvider) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec_TransitedProvider(struct zx_ctx* c, struct zx_sec_TransitedProvider_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec_TransitedProvider(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec_TransitedProvider(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   sec_TransitedProviderPath
#define EL_STRUCT zx_sec_TransitedProviderPath_s
#define EL_NS     sec
#define EL_TAG    TransitedProviderPath

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_sec_TransitedProviderPath) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec:TransitedProviderPath")-1 + 1 + sizeof("</sec:TransitedProviderPath>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = &x->TransitedProvider->gg; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sec_TransitedProvider(c, (struct zx_sec_TransitedProvider_s*)se);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec:TransitedProviderPath", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec_TransitedProviderPath) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec:TransitedProviderPath");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_sec_NS, &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  
  for (se = &x->TransitedProvider->gg; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sec_TransitedProvider(c, (struct zx_sec_TransitedProvider_s*)se, p);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec:TransitedProviderPath>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec:TransitedProviderPath", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec_TransitedProviderPath) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec_TransitedProviderPath(struct zx_ctx* c, struct zx_sec_TransitedProviderPath_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec_TransitedProviderPath(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec_TransitedProviderPath(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif


/* EOF -- c/zx-sec-enc.c */
