/* c/zx-cb-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-cb-data.h"
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

#define EL_NAME   cb_By
#define EL_STRUCT zx_cb_By_s
#define EL_NS     cb
#define EL_TAG    By

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

/* FUNC(zx_LEN_SO_cb_By) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:By")-1 + 1 + sizeof("</cb:By>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->sortAlg || x->sortWeight)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->sortAlg, sizeof("cb:sortAlg")-1);
  len += zx_attr_so_len(x->sortWeight, sizeof("cb:sortWeight")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:By", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_By) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("By")-1 + 1 + 2 + sizeof("By")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->sortAlg)
    len += zx_len_xmlns_if_not_seen(c, x->sortAlg->g.ns, &pop_seen);
  if (x->sortWeight)
    len += zx_len_xmlns_if_not_seen(c, x->sortWeight->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->sortAlg, sizeof("sortAlg")-1);
  len += zx_attr_wo_len(x->sortWeight, sizeof("sortWeight")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:By", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_By) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:By");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->sortAlg || x->sortWeight)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->sortAlg, " cb:sortAlg=\"", sizeof(" cb:sortAlg=\"")-1);
  p = zx_attr_so_enc(p, x->sortWeight, " cb:sortWeight=\"", sizeof(" cb:sortWeight=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:By>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:By", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_By) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "By", sizeof("By")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->sortAlg)
    zx_add_xmlns_if_not_seen(c, x->sortAlg->g.ns, &pop_seen);
  if (x->sortWeight)
    zx_add_xmlns_if_not_seen(c, x->sortWeight->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->sortAlg, "sortAlg=\"", sizeof("sortAlg=\"")-1);
  p = zx_attr_wo_enc(p, x->sortWeight, "sortWeight=\"", sizeof("sortWeight=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:By", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_By) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_By(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_By(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_By) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_By(struct zx_ctx* c, struct zx_cb_By_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_By(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_By(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Create
#define EL_STRUCT zx_cb_Create_s
#define EL_NS     cb
#define EL_TAG    Create

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

/* FUNC(zx_LEN_SO_cb_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Create")-1 + 1 + sizeof("</cb:Create>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_cb_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_CreateItem(c, e);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Create", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Create")-1 + 1 + 2 + sizeof("Create")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_cb_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_CreateItem(c, e);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Create", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Create");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ResourceID(c, e, p);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Subscription(c, e, p);
  }
  {
      struct zx_cb_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_cb_CreateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_CreateItem(c, e, p);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemSelection(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Create>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Create", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Create", sizeof("Create")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Create", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Create(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Create(struct zx_ctx* c, struct zx_cb_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Create(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_CreateItem
#define EL_STRUCT zx_cb_CreateItem_s
#define EL_NS     cb
#define EL_TAG    CreateItem

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

/* FUNC(zx_LEN_SO_cb_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:CreateItem")-1 + 1 + sizeof("</cb:CreateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:CreateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreateItem")-1 + 1 + 2 + sizeof("CreateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:CreateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:CreateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:CreateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CreateItem", sizeof("CreateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_CreateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_CreateItem(struct zx_ctx* c, struct zx_cb_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_CreateItem(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_CreateResponse
#define EL_STRUCT zx_cb_CreateResponse_s
#define EL_NS     cb
#define EL_TAG    CreateResponse

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

/* FUNC(zx_LEN_SO_cb_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:CreateResponse")-1 + 1 + sizeof("</cb:CreateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemData(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:CreateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreateResponse")-1 + 1 + 2 + sizeof("CreateResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemData(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:CreateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:CreateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemData(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:CreateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CreateResponse", sizeof("CreateResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_CreateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_CreateResponse(struct zx_ctx* c, struct zx_cb_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_CreateResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Credential
#define EL_STRUCT zx_cb_Credential_s
#define EL_NS     cb
#define EL_TAG    Credential

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

/* FUNC(zx_LEN_SO_cb_Credential) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Credential")-1 + 1 + sizeof("</cb:Credential>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Assertion(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Credential", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Credential) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Credential")-1 + 1 + 2 + sizeof("Credential")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Assertion(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Credential", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Credential) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Credential");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->notOnOrAfter, " notOnOrAfter=\"", sizeof(" notOnOrAfter=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Assertion(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Credential>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Credential", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Credential) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Credential", sizeof("Credential")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->notOnOrAfter, "notOnOrAfter=\"", sizeof("notOnOrAfter=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Credential", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Credential) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Credential(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Credential(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Credential) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Credential(struct zx_ctx* c, struct zx_cb_Credential_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Credential(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Credential(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Data
#define EL_STRUCT zx_cb_Data_s
#define EL_NS     cb
#define EL_TAG    Data

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

/* FUNC(zx_LEN_SO_cb_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Data")-1 + 1 + sizeof("</cb:Data>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("cb:changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Data", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Data")-1 + 1 + 2 + sizeof("Data")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Card")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Data", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Data");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->changeFormat)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->nextOffset, " nextOffset=\"", sizeof(" nextOffset=\"")-1);
  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->remaining, " remaining=\"", sizeof(" remaining=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " cb:changeFormat=\"", sizeof(" cb:changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Card", sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Data>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Data", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Data", sizeof("Data")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->nextOffset, "nextOffset=\"", sizeof("nextOffset=\"")-1);
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->remaining, "remaining=\"", sizeof("remaining=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Data", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Data(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Data(struct zx_ctx* c, struct zx_cb_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Data(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Delete
#define EL_STRUCT zx_cb_Delete_s
#define EL_NS     cb
#define EL_TAG    Delete

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

/* FUNC(zx_LEN_SO_cb_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Delete")-1 + 1 + sizeof("</cb:Delete>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_cb_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_DeleteItem(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Delete", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Delete")-1 + 1 + 2 + sizeof("Delete")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_cb_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_DeleteItem(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Delete", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Delete");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ResourceID(c, e, p);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_cb_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_cb_DeleteItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_DeleteItem(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Delete>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Delete", sizeof("Delete")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Delete(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Delete(struct zx_ctx* c, struct zx_cb_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Delete(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_DeleteItem
#define EL_STRUCT zx_cb_DeleteItem_s
#define EL_NS     cb
#define EL_TAG    DeleteItem

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

/* FUNC(zx_LEN_SO_cb_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:DeleteItem")-1 + 1 + sizeof("</cb:DeleteItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Select")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:DeleteItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeleteItem")-1 + 1 + 2 + sizeof("DeleteItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Select")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:DeleteItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:DeleteItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " predefined=\"", sizeof(" predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Select", sizeof("cb:Select")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:DeleteItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "DeleteItem", sizeof("DeleteItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_DeleteItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_DeleteItem(struct zx_ctx* c, struct zx_cb_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_DeleteItem(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_DeleteResponse
#define EL_STRUCT zx_cb_DeleteResponse_s
#define EL_NS     cb
#define EL_TAG    DeleteResponse

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

/* FUNC(zx_LEN_SO_cb_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:DeleteResponse")-1 + 1 + sizeof("</cb:DeleteResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:DeleteResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeleteResponse")-1 + 1 + 2 + sizeof("DeleteResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:DeleteResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:DeleteResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:DeleteResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "DeleteResponse", sizeof("DeleteResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_DeleteResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_DeleteResponse(struct zx_ctx* c, struct zx_cb_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_DeleteResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_EncryptedResourceID
#define EL_STRUCT zx_cb_EncryptedResourceID_s
#define EL_NS     cb
#define EL_TAG    EncryptedResourceID

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

/* FUNC(zx_LEN_SO_cb_EncryptedResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:EncryptedResourceID")-1 + 1 + sizeof("</cb:EncryptedResourceID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  len += zx_LEN_SO_xenc_EncryptedData(c, e);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_SO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:EncryptedResourceID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_EncryptedResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EncryptedResourceID")-1 + 1 + 2 + sizeof("EncryptedResourceID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  len += zx_LEN_WO_xenc_EncryptedData(c, e);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_WO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:EncryptedResourceID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_EncryptedResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:EncryptedResourceID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  p = zx_ENC_SO_xenc_EncryptedData(c, e, p);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  p = zx_ENC_SO_xenc_EncryptedKey(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:EncryptedResourceID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:EncryptedResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_EncryptedResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "EncryptedResourceID", sizeof("EncryptedResourceID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:EncryptedResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_EncryptedResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_EncryptedResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_EncryptedResourceID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_EncryptedResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_EncryptedResourceID(struct zx_ctx* c, struct zx_cb_EncryptedResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_EncryptedResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_EncryptedResourceID(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Extension
#define EL_STRUCT zx_cb_Extension_s
#define EL_NS     cb
#define EL_TAG    Extension

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

/* FUNC(zx_LEN_SO_cb_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Extension")-1 + 1 + sizeof("</cb:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Extension")-1 + 1 + 2 + sizeof("Extension")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Extension");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Extension", sizeof("Extension")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Extension(struct zx_ctx* c, struct zx_cb_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Extension(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ItemData
#define EL_STRUCT zx_cb_ItemData_s
#define EL_NS     cb
#define EL_TAG    ItemData

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

/* FUNC(zx_LEN_SO_cb_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ItemData")-1 + 1 + sizeof("</cb:ItemData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("cb:changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ItemData", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ItemData")-1 + 1 + 2 + sizeof("ItemData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Card")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ItemData", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ItemData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->changeFormat)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " cb:changeFormat=\"", sizeof(" cb:changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Card", sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ItemData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ItemData", sizeof("ItemData")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ItemData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ItemData(struct zx_ctx* c, struct zx_cb_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ItemData(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ItemSelection
#define EL_STRUCT zx_cb_ItemSelection_s
#define EL_NS     cb
#define EL_TAG    ItemSelection

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

/* FUNC(zx_LEN_SO_cb_ItemSelection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ItemSelection")-1 + 1 + sizeof("</cb:ItemSelection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->format)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->format, sizeof("cb:format")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ItemSelection", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ItemSelection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ItemSelection")-1 + 1 + 2 + sizeof("ItemSelection")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->format)
    len += zx_len_xmlns_if_not_seen(c, x->format->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->format, sizeof("format")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ItemSelection", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ItemSelection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ItemSelection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->format)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->format, " cb:format=\"", sizeof(" cb:format=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ItemSelection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ItemSelection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ItemSelection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ItemSelection", sizeof("ItemSelection")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->format)
    zx_add_xmlns_if_not_seen(c, x->format->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->format, "format=\"", sizeof("format=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ItemSelection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ItemSelection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ItemSelection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ItemSelection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ItemSelection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ItemSelection(struct zx_ctx* c, struct zx_cb_ItemSelection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ItemSelection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ItemSelection(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Modification
#define EL_STRUCT zx_cb_Modification_s
#define EL_NS     cb
#define EL_TAG    Modification

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

/* FUNC(zx_LEN_SO_cb_Modification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Modification")-1 + 1 + sizeof("</cb:Modification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_so_len(x->overrideAllowed, sizeof("overrideAllowed")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Select")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Modification", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Modification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Modification")-1 + 1 + 2 + sizeof("Modification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->overrideAllowed, sizeof("overrideAllowed")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Select")-1);
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Modification", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Modification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Modification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);
  p = zx_attr_so_enc(p, x->overrideAllowed, " overrideAllowed=\"", sizeof(" overrideAllowed=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Select", sizeof("cb:Select")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_cb_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Modification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Modification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Modification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Modification", sizeof("Modification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->overrideAllowed, "overrideAllowed=\"", sizeof("overrideAllowed=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Modification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Modification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Modification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Modification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Modification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Modification(struct zx_ctx* c, struct zx_cb_Modification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Modification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Modification(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Modify
#define EL_STRUCT zx_cb_Modify_s
#define EL_NS     cb
#define EL_TAG    Modify

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

/* FUNC(zx_LEN_SO_cb_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Modify")-1 + 1 + sizeof("</cb:Modify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_cb_Modification_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Modification(c, e);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Modify", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Modify")-1 + 1 + 2 + sizeof("Modify")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_cb_Modification_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Modification(c, e);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Modify", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Modify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ResourceID(c, e, p);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Subscription(c, e, p);
  }
  {
      struct zx_cb_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_cb_Modification_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Modification(c, e, p);
  }
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemSelection(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Modify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Modify", sizeof("Modify")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Modify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Modify(struct zx_ctx* c, struct zx_cb_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Modify(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ModifyResponse
#define EL_STRUCT zx_cb_ModifyResponse_s
#define EL_NS     cb
#define EL_TAG    ModifyResponse

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

/* FUNC(zx_LEN_SO_cb_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ModifyResponse")-1 + 1 + sizeof("</cb:ModifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemData(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ModifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ModifyResponse")-1 + 1 + 2 + sizeof("ModifyResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemData(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ModifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ModifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemData(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ModifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ModifyResponse", sizeof("ModifyResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ModifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ModifyResponse(struct zx_ctx* c, struct zx_cb_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ModifyResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_NewData
#define EL_STRUCT zx_cb_NewData_s
#define EL_NS     cb
#define EL_TAG    NewData

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

/* FUNC(zx_LEN_SO_cb_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:NewData")-1 + 1 + sizeof("</cb:NewData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NewData", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NewData")-1 + 1 + 2 + sizeof("NewData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Card")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NewData", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:NewData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Card; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Card", sizeof("cb:Card")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:NewData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NewData", sizeof("NewData")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_NewData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_NewData(struct zx_ctx* c, struct zx_cb_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_NewData(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Notification
#define EL_STRUCT zx_cb_Notification_s
#define EL_NS     cb
#define EL_TAG    Notification

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

/* FUNC(zx_LEN_SO_cb_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Notification")-1 + 1 + sizeof("</cb:Notification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->endReason, sizeof("endReason")-1);
  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Notification", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Notification")-1 + 1 + 2 + sizeof("Notification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->endReason, sizeof("endReason")-1);
  len += zx_attr_wo_len(x->expires, sizeof("expires")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Notification", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Notification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->endReason, " endReason=\"", sizeof(" endReason=\"")-1);
  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_cb_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Notification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Notification", sizeof("Notification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->endReason, "endReason=\"", sizeof("endReason=\"")-1);
  p = zx_attr_wo_enc(p, x->expires, "expires=\"", sizeof("expires=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->subscriptionID, "subscriptionID=\"", sizeof("subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Notification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Notification(struct zx_ctx* c, struct zx_cb_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Notification(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Notify
#define EL_STRUCT zx_cb_Notify_s
#define EL_NS     cb
#define EL_TAG    Notify

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

/* FUNC(zx_LEN_SO_cb_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Notify")-1 + 1 + sizeof("</cb:Notify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_cb_Notification_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Notification(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Notify", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Notify")-1 + 1 + 2 + sizeof("Notify")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_cb_Notification_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Notification(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Notify", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Notify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_cb_Notification_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Notification(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Notify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Notify", sizeof("Notify")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Notify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Notify(struct zx_ctx* c, struct zx_cb_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Notify(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_NotifyAdminTo
#define EL_STRUCT zx_cb_NotifyAdminTo_s
#define EL_NS     cb
#define EL_TAG    NotifyAdminTo

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

/* FUNC(zx_LEN_SO_cb_NotifyAdminTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:NotifyAdminTo")-1 + 1 + sizeof("</cb:NotifyAdminTo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyAdminTo", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_NotifyAdminTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyAdminTo")-1 + 1 + 2 + sizeof("NotifyAdminTo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SecurityMechID")-1);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Endpoint")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyAdminTo", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_NotifyAdminTo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:NotifyAdminTo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:SecurityMechID", sizeof("cb:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Credential(c, e, p);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Endpoint", sizeof("cb:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:NotifyAdminTo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyAdminTo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_NotifyAdminTo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NotifyAdminTo", sizeof("NotifyAdminTo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyAdminTo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_NotifyAdminTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_NotifyAdminTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_NotifyAdminTo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_NotifyAdminTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_NotifyAdminTo(struct zx_ctx* c, struct zx_cb_NotifyAdminTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_NotifyAdminTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_NotifyAdminTo(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_NotifyResponse
#define EL_STRUCT zx_cb_NotifyResponse_s
#define EL_NS     cb
#define EL_TAG    NotifyResponse

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

/* FUNC(zx_LEN_SO_cb_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:NotifyResponse")-1 + 1 + sizeof("</cb:NotifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyResponse")-1 + 1 + 2 + sizeof("NotifyResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:NotifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:NotifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NotifyResponse", sizeof("NotifyResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_NotifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_NotifyResponse(struct zx_ctx* c, struct zx_cb_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_NotifyResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_NotifyTo
#define EL_STRUCT zx_cb_NotifyTo_s
#define EL_NS     cb
#define EL_TAG    NotifyTo

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

/* FUNC(zx_LEN_SO_cb_NotifyTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:NotifyTo")-1 + 1 + sizeof("</cb:NotifyTo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_cb);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyTo", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_NotifyTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyTo")-1 + 1 + 2 + sizeof("NotifyTo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SecurityMechID")-1);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Endpoint")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:NotifyTo", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_NotifyTo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:NotifyTo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:SecurityMechID", sizeof("cb:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_cb_Credential_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Credential(c, e, p);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Endpoint", sizeof("cb:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_cb);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:NotifyTo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyTo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_NotifyTo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NotifyTo", sizeof("NotifyTo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:NotifyTo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_NotifyTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_NotifyTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_NotifyTo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_NotifyTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_NotifyTo(struct zx_ctx* c, struct zx_cb_NotifyTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_NotifyTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_NotifyTo(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Query
#define EL_STRUCT zx_cb_Query_s
#define EL_NS     cb
#define EL_TAG    Query

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

/* FUNC(zx_LEN_SO_cb_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Query")-1 + 1 + sizeof("</cb:Query>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_cb_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_QueryItem(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Query", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Query")-1 + 1 + 2 + sizeof("Query")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_EncryptedResourceID(c, e);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Subscription(c, e);
  }
  {
      struct zx_cb_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_cb_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_QueryItem(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Query", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Query");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ResourceID(c, e, p);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_cb_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_cb_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Subscription(c, e, p);
  }
  {
      struct zx_cb_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_cb_QueryItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_QueryItem(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Query>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Query", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Query", sizeof("Query")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Query", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Query(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Query(struct zx_ctx* c, struct zx_cb_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Query(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_QueryItem
#define EL_STRUCT zx_cb_QueryItem_s
#define EL_NS     cb
#define EL_TAG    QueryItem

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

/* FUNC(zx_LEN_SO_cb_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:QueryItem")-1 + 1 + sizeof("</cb:QueryItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->format)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->count, sizeof("count")-1);
  len += zx_attr_so_len(x->offset, sizeof("offset")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->setReq, sizeof("setReq")-1);
  len += zx_attr_so_len(x->format, sizeof("cb:format")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:QueryItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryItem")-1 + 1 + 2 + sizeof("QueryItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->format)
    len += zx_len_xmlns_if_not_seen(c, x->format->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->count, sizeof("count")-1);
  len += zx_attr_wo_len(x->offset, sizeof("offset")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->setReq, sizeof("setReq")-1);
  len += zx_attr_wo_len(x->format, sizeof("format")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:QueryItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:QueryItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->format)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->count, " count=\"", sizeof(" count=\"")-1);
  p = zx_attr_so_enc(p, x->offset, " offset=\"", sizeof(" offset=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->setReq, " setReq=\"", sizeof(" setReq=\"")-1);
  p = zx_attr_so_enc(p, x->format, " cb:format=\"", sizeof(" cb:format=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:QueryItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "QueryItem", sizeof("QueryItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->format)
    zx_add_xmlns_if_not_seen(c, x->format->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->count, "count=\"", sizeof("count=\"")-1);
  p = zx_attr_wo_enc(p, x->offset, "offset=\"", sizeof("offset=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->setReq, "setReq=\"", sizeof("setReq=\"")-1);
  p = zx_attr_wo_enc(p, x->format, "format=\"", sizeof("format=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_QueryItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_QueryItem(struct zx_ctx* c, struct zx_cb_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_QueryItem(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_QueryResponse
#define EL_STRUCT zx_cb_QueryResponse_s
#define EL_NS     cb
#define EL_TAG    QueryResponse

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

/* FUNC(zx_LEN_SO_cb_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:QueryResponse")-1 + 1 + sizeof("</cb:QueryResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }
  {
      struct zx_cb_Data_s* e;
      for (e = x->Data; e; e = (struct zx_cb_Data_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Data(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:QueryResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryResponse")-1 + 1 + 2 + sizeof("QueryResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }
  {
      struct zx_cb_Data_s* e;
      for (e = x->Data; e; e = (struct zx_cb_Data_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Data(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:QueryResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:QueryResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }
  {
      struct zx_cb_Data_s* e;
      for (e = x->Data; e; e = (struct zx_cb_Data_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Data(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:QueryResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "QueryResponse", sizeof("QueryResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_QueryResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_QueryResponse(struct zx_ctx* c, struct zx_cb_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_QueryResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_RefItem
#define EL_STRUCT zx_cb_RefItem_s
#define EL_NS     cb
#define EL_TAG    RefItem

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

/* FUNC(zx_LEN_SO_cb_RefItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:RefItem")-1 + 1 + sizeof("</cb:RefItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->ItemIDRef, sizeof("ItemIDRef")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:RefItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_RefItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RefItem")-1 + 1 + 2 + sizeof("RefItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ItemIDRef, sizeof("ItemIDRef")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:RefItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_RefItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:RefItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->ItemIDRef, " ItemIDRef=\"", sizeof(" ItemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:RefItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:RefItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_RefItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "RefItem", sizeof("RefItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ItemIDRef, "ItemIDRef=\"", sizeof("ItemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->subscriptionID, "subscriptionID=\"", sizeof("subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:RefItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_RefItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_RefItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_RefItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_RefItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_RefItem(struct zx_ctx* c, struct zx_cb_RefItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_RefItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_RefItem(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ReportUsage
#define EL_STRUCT zx_cb_ReportUsage_s
#define EL_NS     cb
#define EL_TAG    ReportUsage

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

/* FUNC(zx_LEN_SO_cb_ReportUsage) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ReportUsage")-1 + 1 + sizeof("</cb:ReportUsage>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_EncryptedResourceID(c, e);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:CARDID")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cb_UsageType_s* e;
      for (e = x->UsageType; e; e = (struct zx_cb_UsageType_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_UsageType(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ReportUsage", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ReportUsage) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReportUsage")-1 + 1 + 2 + sizeof("ReportUsage")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ResourceID(c, e);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_EncryptedResourceID(c, e);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CARDID")-1);
  {
      struct zx_cb_UsageType_s* e;
      for (e = x->UsageType; e; e = (struct zx_cb_UsageType_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_UsageType(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ReportUsage", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ReportUsage) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ReportUsage");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_cb_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ResourceID(c, e, p);
  }
  {
      struct zx_cb_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_cb_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_EncryptedResourceID(c, e, p);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:CARDID", sizeof("cdm:CARDID")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cb_UsageType_s* e;
      for (e = x->UsageType; e; e = (struct zx_cb_UsageType_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_UsageType(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ReportUsage>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ReportUsage", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ReportUsage) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ReportUsage", sizeof("ReportUsage")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ReportUsage", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ReportUsage) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ReportUsage(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ReportUsage(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ReportUsage) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ReportUsage(struct zx_ctx* c, struct zx_cb_ReportUsage_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ReportUsage(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ReportUsage(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ReportUsageResponse
#define EL_STRUCT zx_cb_ReportUsageResponse_s
#define EL_NS     cb
#define EL_TAG    ReportUsageResponse

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

/* FUNC(zx_LEN_SO_cb_ReportUsageResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ReportUsageResponse")-1 + 1 + sizeof("</cb:ReportUsageResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ReportUsageResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ReportUsageResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReportUsageResponse")-1 + 1 + 2 + sizeof("ReportUsageResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ReportUsageResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ReportUsageResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ReportUsageResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ReportUsageResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ReportUsageResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ReportUsageResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ReportUsageResponse", sizeof("ReportUsageResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ReportUsageResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ReportUsageResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ReportUsageResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ReportUsageResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ReportUsageResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ReportUsageResponse(struct zx_ctx* c, struct zx_cb_ReportUsageResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ReportUsageResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ReportUsageResponse(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_ResourceID
#define EL_STRUCT zx_cb_ResourceID_s
#define EL_NS     cb
#define EL_TAG    ResourceID

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

/* FUNC(zx_LEN_SO_cb_ResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:ResourceID")-1 + 1 + sizeof("</cb:ResourceID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ResourceID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_ResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceID")-1 + 1 + 2 + sizeof("ResourceID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:ResourceID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_ResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:ResourceID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:ResourceID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_ResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ResourceID", sizeof("ResourceID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:ResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_ResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_ResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_ResourceID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_ResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_ResourceID(struct zx_ctx* c, struct zx_cb_ResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_ResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_ResourceID(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Status
#define EL_STRUCT zx_cb_Status_s
#define EL_NS     cb
#define EL_TAG    Status

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

/* FUNC(zx_LEN_SO_cb_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Status")-1 + 1 + sizeof("</cb:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->code, sizeof("code")-1);
  len += zx_attr_so_len(x->comment, sizeof("comment")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Status")-1 + 1 + 2 + sizeof("Status")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->code, sizeof("code")-1);
  len += zx_attr_wo_len(x->comment, sizeof("comment")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->code, " code=\"", sizeof(" code=\"")-1);
  p = zx_attr_so_enc(p, x->comment, " comment=\"", sizeof(" comment=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_Status_s* e;
      for (e = x->Status; e; e = (struct zx_cb_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Status", sizeof("Status")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->code, "code=\"", sizeof("code=\"")-1);
  p = zx_attr_wo_enc(p, x->comment, "comment=\"", sizeof("comment=\"")-1);
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Status(struct zx_ctx* c, struct zx_cb_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Status(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_Subscription
#define EL_STRUCT zx_cb_Subscription_s
#define EL_NS     cb
#define EL_TAG    Subscription

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

/* FUNC(zx_LEN_SO_cb_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:Subscription")-1 + 1 + sizeof("</cb:Subscription>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_so_len(x->starts, sizeof("starts")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_cb_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_RefItem(c, e);
  }
  {
      struct zx_cb_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_cb_NotifyTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_NotifyTo(c, e);
  }
  {
      struct zx_cb_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_cb_NotifyAdminTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_NotifyAdminTo(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_cb);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cb:Trigger")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Subscription", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Subscription")-1 + 1 + 2 + sizeof("Subscription")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->expires, sizeof("expires")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_wo_len(x->starts, sizeof("starts")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ItemSelection(c, e);
  }
  {
      struct zx_cb_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_cb_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_RefItem(c, e);
  }
  {
      struct zx_cb_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_cb_NotifyTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_NotifyTo(c, e);
  }
  {
      struct zx_cb_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_cb_NotifyAdminTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_NotifyAdminTo(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Aggregation")-1);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Trigger")-1);
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:Subscription", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:Subscription");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->includeData, " includeData=\"", sizeof(" includeData=\"")-1);
  p = zx_attr_so_enc(p, x->starts, " starts=\"", sizeof(" starts=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cb_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_cb_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ItemSelection(c, e, p);
  }
  {
      struct zx_cb_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_cb_RefItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_RefItem(c, e, p);
  }
  {
      struct zx_cb_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_cb_NotifyTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_NotifyTo(c, e, p);
  }
  {
      struct zx_cb_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_cb_NotifyAdminTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_NotifyAdminTo(c, e, p);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Aggregation", sizeof("cb:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_cb);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cb:Trigger", sizeof("cb:Trigger")-1, zx_ns_tab+zx_xmlns_ix_cb);
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:Subscription>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Subscription", sizeof("Subscription")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->expires, "expires=\"", sizeof("expires=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->includeData, "includeData=\"", sizeof("includeData=\"")-1);
  p = zx_attr_wo_enc(p, x->starts, "starts=\"", sizeof("starts=\"")-1);
  p = zx_attr_wo_enc(p, x->subscriptionID, "subscriptionID=\"", sizeof("subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_Subscription(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_Subscription(struct zx_ctx* c, struct zx_cb_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_Subscription(c, x, buf ), buf, len);
}






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

#define EL_NAME   cb_UsageType
#define EL_STRUCT zx_cb_UsageType_s
#define EL_NS     cb
#define EL_TAG    UsageType

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

/* FUNC(zx_LEN_SO_cb_UsageType) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cb:UsageType")-1 + 1 + sizeof("</cb:UsageType>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  len += zx_attr_so_len(x->success, sizeof("success")-1);
  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:UsageType", len);
  return len;
}

/* FUNC(zx_LEN_WO_cb_UsageType) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UsageType")-1 + 1 + 2 + sizeof("UsageType")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC)
    len += zx_len_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);
  if (x->ACCTime)
    len += zx_len_xmlns_if_not_seen(c, x->ACCTime->g.ns, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  if (x->modifier)
    len += zx_len_xmlns_if_not_seen(c, x->modifier->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->success, sizeof("success")-1);
  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cb:UsageType", len);
  return len;
}

/* FUNC(zx_ENC_SO_cb_UsageType) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cb:UsageType");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);

  p = zx_attr_so_enc(p, x->success, " success=\"", sizeof(" success=\"")-1);
  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cb:UsageType>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:UsageType", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cb_UsageType) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "UsageType", sizeof("UsageType")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->ACC)
    zx_add_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);
  if (x->ACCTime)
    zx_add_xmlns_if_not_seen(c, x->ACCTime->g.ns, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  if (x->modifier)
    zx_add_xmlns_if_not_seen(c, x->modifier->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->success, "success=\"", sizeof("success=\"")-1);
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cb:UsageType", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cb_UsageType) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cb_UsageType(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cb_UsageType(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cb_UsageType) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cb_UsageType(struct zx_ctx* c, struct zx_cb_UsageType_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cb_UsageType(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cb_UsageType(c, x, buf ), buf, len);
}




/* EOF -- c/zx-cb-enc.c */
