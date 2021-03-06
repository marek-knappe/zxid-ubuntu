/* c/zx-sec12-aux.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** aux-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: aux-templ.c,v 1.12 2008-10-04 23:42:14 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-sec12-data.h"



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

#define EL_NAME   sec12_ProxyInfoConfirmationData
#define EL_STRUCT zx_sec12_ProxyInfoConfirmationData_s
#define EL_NS     sec12
#define EL_TAG    ProxyInfoConfirmationData

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  zx_dup_strs_simple_elems(c, x->AssertionIDReference);
  zx_dup_strs_simple_elems(c, x->Issuer);
  zx_dup_strs_simple_elems(c, x->IssueInstant);
  for (se = &x->Signature->gg;
       se && se->g.tok == zx_ds_Signature_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_ds_Signature(c, (struct zx_ds_Signature_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxyInfoConfirmationData_s* zx_DEEP_CLONE_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_ProxyInfoConfirmationData_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxyInfoConfirmationData_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  x->AssertionIDReference = zx_deep_clone_simple_elems(c,x->AssertionIDReference, dup_strs);
  x->Issuer = zx_deep_clone_simple_elems(c,x->Issuer, dup_strs);
  x->IssueInstant = zx_deep_clone_simple_elems(c,x->IssueInstant, dup_strs);
  for (enn = 0, e = &x->Signature->gg;
       e && e->g.tok == zx_ds_Signature_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_ds_Signature(c,(struct zx_ds_Signature_s*)e,dup_strs);
  	  if (!enn)
  	      x->Signature = (struct zx_ds_Signature_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ProxyInfoConfirmationData) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->AssertionIDReference, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Issuer, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->IssueInstant, ctx, callback);
  if (ret)
    return ret;
  for (e = &x->Signature->gg;
       e && e->g.tok == zx_ds_Signature_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_ds_Signature(c, (struct zx_ds_Signature_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ProxyInfoConfirmationData) */

int zx_WALK_WO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_ProxySubject
#define EL_STRUCT zx_sec12_ProxySubject_s
#define EL_NS     sec12
#define EL_TAG    ProxySubject

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxySubject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  for (se = &x->NameIdentifier->gg;
       se && se->g.tok == zx_sa11_NameIdentifier_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)se);
  for (se = &x->SubjectConfirmation->gg;
       se && se->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_ProxySubject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxySubject_s* zx_DEEP_CLONE_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_ProxySubject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxySubject_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  for (enn = 0, e = &x->NameIdentifier->gg;
       e && e->g.tok == zx_sa11_NameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_NameIdentifier(c,(struct zx_sa11_NameIdentifier_s*)e,dup_strs);
  	  if (!enn)
  	      x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->SubjectConfirmation->gg;
       e && e->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_SubjectConfirmation(c,(struct zx_sa11_SubjectConfirmation_s*)e,dup_strs);
  	  if (!enn)
  	      x->SubjectConfirmation = (struct zx_sa11_SubjectConfirmation_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ProxySubject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->NameIdentifier->gg;
       e && e->g.tok == zx_sa11_NameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->SubjectConfirmation->gg;
       e && e->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ProxySubject) */

int zx_WALK_WO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_ProxyTransitedStatement
#define EL_STRUCT zx_sec12_ProxyTransitedStatement_s
#define EL_NS     sec12
#define EL_TAG    ProxyTransitedStatement

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ProxyTransitedStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  for (se = &x->Subject->gg;
       se && se->g.tok == zx_sa11_Subject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_Subject(c, (struct zx_sa11_Subject_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_ProxyTransitedStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ProxyTransitedStatement_s* zx_DEEP_CLONE_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_ProxyTransitedStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ProxyTransitedStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  for (enn = 0, e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_Subject(c,(struct zx_sa11_Subject_s*)e,dup_strs);
  	  if (!enn)
  	      x->Subject = (struct zx_sa11_Subject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ProxyTransitedStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_Subject(c, (struct zx_sa11_Subject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ProxyTransitedStatement) */

int zx_WALK_WO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_ResourceAccessStatement
#define EL_STRUCT zx_sec12_ResourceAccessStatement_s
#define EL_NS     sec12
#define EL_TAG    ResourceAccessStatement

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ResourceAccessStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  for (se = &x->Subject->gg;
       se && se->g.tok == zx_sa11_Subject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_Subject(c, (struct zx_sa11_Subject_s*)se);
  for (se = &x->ResourceID->gg;
       se && se->g.tok == zx_di12_ResourceID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_di12_ResourceID(c, (struct zx_di12_ResourceID_s*)se);
  for (se = &x->EncryptedResourceID->gg;
       se && se->g.tok == zx_di12_EncryptedResourceID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_di12_EncryptedResourceID(c, (struct zx_di12_EncryptedResourceID_s*)se);
  for (se = &x->ProxySubject->gg;
       se && se->g.tok == zx_sec12_ProxySubject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)se);
  for (se = &x->SessionContext->gg;
       se && se->g.tok == zx_sec12_SessionContext_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_ResourceAccessStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ResourceAccessStatement_s* zx_DEEP_CLONE_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_ResourceAccessStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ResourceAccessStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  for (enn = 0, e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_Subject(c,(struct zx_sa11_Subject_s*)e,dup_strs);
  	  if (!enn)
  	      x->Subject = (struct zx_sa11_Subject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->ResourceID->gg;
       e && e->g.tok == zx_di12_ResourceID_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_di12_ResourceID(c,(struct zx_di12_ResourceID_s*)e,dup_strs);
  	  if (!enn)
  	      x->ResourceID = (struct zx_di12_ResourceID_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->EncryptedResourceID->gg;
       e && e->g.tok == zx_di12_EncryptedResourceID_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_di12_EncryptedResourceID(c,(struct zx_di12_EncryptedResourceID_s*)e,dup_strs);
  	  if (!enn)
  	      x->EncryptedResourceID = (struct zx_di12_EncryptedResourceID_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->ProxySubject->gg;
       e && e->g.tok == zx_sec12_ProxySubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sec12_ProxySubject(c,(struct zx_sec12_ProxySubject_s*)e,dup_strs);
  	  if (!enn)
  	      x->ProxySubject = (struct zx_sec12_ProxySubject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->SessionContext->gg;
       e && e->g.tok == zx_sec12_SessionContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sec12_SessionContext(c,(struct zx_sec12_SessionContext_s*)e,dup_strs);
  	  if (!enn)
  	      x->SessionContext = (struct zx_sec12_SessionContext_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ResourceAccessStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_Subject(c, (struct zx_sa11_Subject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->ResourceID->gg;
       e && e->g.tok == zx_di12_ResourceID_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_di12_ResourceID(c, (struct zx_di12_ResourceID_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->EncryptedResourceID->gg;
       e && e->g.tok == zx_di12_EncryptedResourceID_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_di12_EncryptedResourceID(c, (struct zx_di12_EncryptedResourceID_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->ProxySubject->gg;
       e && e->g.tok == zx_sec12_ProxySubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->SessionContext->gg;
       e && e->g.tok == zx_sec12_SessionContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ResourceAccessStatement) */

int zx_WALK_WO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_SessionContext
#define EL_STRUCT zx_sec12_SessionContext_s
#define EL_NS     sec12
#define EL_TAG    SessionContext

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionContext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AssertionIssueInstant);
  zx_dup_attr(c, x->AuthenticationInstant);
  zx_dup_attr(c, x->SessionIndex);

  for (se = &x->SessionSubject->gg;
       se && se->g.tok == zx_sec12_SessionSubject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sec12_SessionSubject(c, (struct zx_sec12_SessionSubject_s*)se);
  zx_dup_strs_simple_elems(c, x->ProviderID);
  for (se = &x->RequestAuthnContext->gg;
       se && se->g.tok == zx_ff12_RequestAuthnContext_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_ff12_RequestAuthnContext(c, (struct zx_ff12_RequestAuthnContext_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_SessionContext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionContext_s* zx_DEEP_CLONE_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_SessionContext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionContext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AssertionIssueInstant = zx_clone_attr(c, x->AssertionIssueInstant);
  x->AuthenticationInstant = zx_clone_attr(c, x->AuthenticationInstant);
  x->SessionIndex = zx_clone_attr(c, x->SessionIndex);

  for (enn = 0, e = &x->SessionSubject->gg;
       e && e->g.tok == zx_sec12_SessionSubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sec12_SessionSubject(c,(struct zx_sec12_SessionSubject_s*)e,dup_strs);
  	  if (!enn)
  	      x->SessionSubject = (struct zx_sec12_SessionSubject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);
  for (enn = 0, e = &x->RequestAuthnContext->gg;
       e && e->g.tok == zx_ff12_RequestAuthnContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_ff12_RequestAuthnContext(c,(struct zx_ff12_RequestAuthnContext_s*)e,dup_strs);
  	  if (!enn)
  	      x->RequestAuthnContext = (struct zx_ff12_RequestAuthnContext_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_SessionContext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->SessionSubject->gg;
       e && e->g.tok == zx_sec12_SessionSubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sec12_SessionSubject(c, (struct zx_sec12_SessionSubject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;
  for (e = &x->RequestAuthnContext->gg;
       e && e->g.tok == zx_ff12_RequestAuthnContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_ff12_RequestAuthnContext(c, (struct zx_ff12_RequestAuthnContext_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_SessionContext) */

int zx_WALK_WO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_SessionContextStatement
#define EL_STRUCT zx_sec12_SessionContextStatement_s
#define EL_NS     sec12
#define EL_TAG    SessionContextStatement

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionContextStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  for (se = &x->Subject->gg;
       se && se->g.tok == zx_sa11_Subject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_Subject(c, (struct zx_sa11_Subject_s*)se);
  for (se = &x->ProxySubject->gg;
       se && se->g.tok == zx_sec12_ProxySubject_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)se);
  for (se = &x->SessionContext->gg;
       se && se->g.tok == zx_sec12_SessionContext_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_SessionContextStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionContextStatement_s* zx_DEEP_CLONE_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_SessionContextStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionContextStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  for (enn = 0, e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_Subject(c,(struct zx_sa11_Subject_s*)e,dup_strs);
  	  if (!enn)
  	      x->Subject = (struct zx_sa11_Subject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->ProxySubject->gg;
       e && e->g.tok == zx_sec12_ProxySubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sec12_ProxySubject(c,(struct zx_sec12_ProxySubject_s*)e,dup_strs);
  	  if (!enn)
  	      x->ProxySubject = (struct zx_sec12_ProxySubject_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->SessionContext->gg;
       e && e->g.tok == zx_sec12_SessionContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sec12_SessionContext(c,(struct zx_sec12_SessionContext_s*)e,dup_strs);
  	  if (!enn)
  	      x->SessionContext = (struct zx_sec12_SessionContext_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_SessionContextStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->Subject->gg;
       e && e->g.tok == zx_sa11_Subject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_Subject(c, (struct zx_sa11_Subject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->ProxySubject->gg;
       e && e->g.tok == zx_sec12_ProxySubject_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->SessionContext->gg;
       e && e->g.tok == zx_sec12_SessionContext_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_SessionContextStatement) */

int zx_WALK_WO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_SessionSubject
#define EL_STRUCT zx_sec12_SessionSubject_s
#define EL_NS     sec12
#define EL_TAG    SessionSubject

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_SessionSubject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  for (se = &x->NameIdentifier->gg;
       se && se->g.tok == zx_sa11_NameIdentifier_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)se);
  for (se = &x->SubjectConfirmation->gg;
       se && se->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)se);
  for (se = &x->IDPProvidedNameIdentifier->gg;
       se && se->g.tok == zx_ff12_IDPProvidedNameIdentifier_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_ff12_IDPProvidedNameIdentifier(c, (struct zx_ff12_IDPProvidedNameIdentifier_s*)se);

}

/* FUNC(zx_DEEP_CLONE_sec12_SessionSubject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_SessionSubject_s* zx_DEEP_CLONE_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_SessionSubject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_SessionSubject_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  for (enn = 0, e = &x->NameIdentifier->gg;
       e && e->g.tok == zx_sa11_NameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_NameIdentifier(c,(struct zx_sa11_NameIdentifier_s*)e,dup_strs);
  	  if (!enn)
  	      x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->SubjectConfirmation->gg;
       e && e->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_sa11_SubjectConfirmation(c,(struct zx_sa11_SubjectConfirmation_s*)e,dup_strs);
  	  if (!enn)
  	      x->SubjectConfirmation = (struct zx_sa11_SubjectConfirmation_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }
  for (enn = 0, e = &x->IDPProvidedNameIdentifier->gg;
       e && e->g.tok == zx_ff12_IDPProvidedNameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
  	  en=(struct zx_elem_s*)zx_DEEP_CLONE_ff12_IDPProvidedNameIdentifier(c,(struct zx_ff12_IDPProvidedNameIdentifier_s*)e,dup_strs);
  	  if (!enn)
  	      x->IDPProvidedNameIdentifier = (struct zx_ff12_IDPProvidedNameIdentifier_s*)en;
  	  else
  	      enn->g.n = &en->g;
  	  enn = en;
  }

  return x;
}

/* FUNC(zx_WALK_SO_sec12_SessionSubject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  for (e = &x->NameIdentifier->gg;
       e && e->g.tok == zx_sa11_NameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->SubjectConfirmation->gg;
       e && e->g.tok == zx_sa11_SubjectConfirmation_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)e, ctx, callback);
    if (ret)
      return ret;
  }
  for (e = &x->IDPProvidedNameIdentifier->gg;
       e && e->g.tok == zx_ff12_IDPProvidedNameIdentifier_ELEM;
       e = (struct zx_elem_s*)e->g.n) {
    ret = zx_WALK_SO_ff12_IDPProvidedNameIdentifier(c, (struct zx_ff12_IDPProvidedNameIdentifier_s*)e, ctx, callback);
    if (ret)
      return ret;
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_SessionSubject) */

int zx_WALK_WO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

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

#define EL_NAME   sec12_ValidityRestrictionCondition
#define EL_STRUCT zx_sec12_ValidityRestrictionCondition_s
#define EL_NS     sec12
#define EL_TAG    ValidityRestrictionCondition

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x)
{
  struct zx_elem_s* se  MAYBE_UNUSED;
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->NumberOfUses);

}

/* FUNC(zx_DEEP_CLONE_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_sec12_ValidityRestrictionCondition_s* zx_DEEP_CLONE_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, int dup_strs)
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  struct zx_elem_s* en  MAYBE_UNUSED;
  struct zx_elem_s* enn MAYBE_UNUSED;

  x = (struct zx_sec12_ValidityRestrictionCondition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_sec12_ValidityRestrictionCondition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->NumberOfUses = zx_deep_clone_simple_elems(c,x->NumberOfUses, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_sec12_ValidityRestrictionCondition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* e   MAYBE_UNUSED;
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->NumberOfUses, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_sec12_ValidityRestrictionCondition) */

int zx_WALK_WO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-sec12-aux.c */
