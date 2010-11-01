/* c/zx-is-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** dec-templ.c  -  XML decoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: dec-templ.c,v 1.30 2008-10-04 23:42:14 sampo Exp $
 **
 ** 28.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 12.8.2006, added special scanning of xmlns to avoid backtracking elem recognition --Sampo
 ** 23.9.2006, added collection of WO information --Sampo
 ** 21.6.2007, improved handling of undeclared namespace prefixes --Sampo
 ** 27.10.2010, CSE refactoring, re-engineered namespace handling --Sampo
 **
 ** N.B: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-is-data.h"
#define TPF zx_
#include "zx_ext_pt.h"




/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Confirm
#define EL_STRUCT zx_is_Confirm_s
#define EL_NS     is
#define EL_TAG    Confirm

/* FUNC(zx_DEC_is_Confirm) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Confirm_s* zx_DEC_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_name_ATTR:  x->name = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Help_ELEM:
            zx_DEC_is_Help(c, (struct zx_is_Help_s*)el);
            if (!x->Help)
              x->Help = (struct zx_is_Help_s*)el;
            break;
          case zx_is_Hint_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Hint)
              x->Hint = el;
            break;
          case zx_is_Label_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Label)
              x->Label = el;
            break;
          case zx_is_Value_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Value)
              x->Value = el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Help
#define EL_STRUCT zx_is_Help_s
#define EL_NS     is
#define EL_TAG    Help

/* FUNC(zx_DEC_is_Help) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Help_s* zx_DEC_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_label_ATTR:  x->label = x->gg.attr; break;
    case zx_link_ATTR:  x->link = x->gg.attr; break;
    case zx_moreLink_ATTR:  x->moreLink = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Inquiry
#define EL_STRUCT zx_is_Inquiry_s
#define EL_NS     is
#define EL_TAG    Inquiry

/* FUNC(zx_DEC_is_Inquiry) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Inquiry_s* zx_DEC_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; break;
    case zx_title_ATTR:  x->title = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Help_ELEM:
            zx_DEC_is_Help(c, (struct zx_is_Help_s*)el);
            if (!x->Help)
              x->Help = (struct zx_is_Help_s*)el;
            break;
          case zx_is_Select_ELEM:
            zx_DEC_is_Select(c, (struct zx_is_Select_s*)el);
            if (!x->Select)
              x->Select = (struct zx_is_Select_s*)el;
            break;
          case zx_is_Confirm_ELEM:
            zx_DEC_is_Confirm(c, (struct zx_is_Confirm_s*)el);
            if (!x->Confirm)
              x->Confirm = (struct zx_is_Confirm_s*)el;
            break;
          case zx_is_Text_ELEM:
            zx_DEC_is_Text(c, (struct zx_is_Text_s*)el);
            if (!x->Text)
              x->Text = (struct zx_is_Text_s*)el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_InteractionRequest
#define EL_STRUCT zx_is_InteractionRequest_s
#define EL_NS     is
#define EL_TAG    InteractionRequest

/* FUNC(zx_DEC_is_InteractionRequest) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_InteractionRequest_s* zx_DEC_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_id_ATTR:  x->id = x->gg.attr; break;
    case zx_language_ATTR:  x->language = x->gg.attr; break;
    case zx_maxInteractTime_ATTR:  x->maxInteractTime = x->gg.attr; break;
    case zx_signed_ATTR:  x->signed_is_c_keyword = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Inquiry_ELEM:
            zx_DEC_is_Inquiry(c, (struct zx_is_Inquiry_s*)el);
            if (!x->Inquiry)
              x->Inquiry = (struct zx_is_Inquiry_s*)el;
            break;
          case zx_ds_KeyInfo_ELEM:
            zx_DEC_ds_KeyInfo(c, (struct zx_ds_KeyInfo_s*)el);
            if (!x->KeyInfo)
              x->KeyInfo = (struct zx_ds_KeyInfo_s*)el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_InteractionResponse
#define EL_STRUCT zx_is_InteractionResponse_s
#define EL_NS     is
#define EL_TAG    InteractionResponse

/* FUNC(zx_DEC_is_InteractionResponse) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_InteractionResponse_s* zx_DEC_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_lu_Status_ELEM:
            zx_DEC_lu_Status(c, (struct zx_lu_Status_s*)el);
            if (!x->Status)
              x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_is_InteractionStatement_ELEM:
            zx_DEC_is_InteractionStatement(c, (struct zx_is_InteractionStatement_s*)el);
            if (!x->InteractionStatement)
              x->InteractionStatement = (struct zx_is_InteractionStatement_s*)el;
            break;
          case zx_is_Parameter_ELEM:
            zx_DEC_is_Parameter(c, (struct zx_is_Parameter_s*)el);
            if (!x->Parameter)
              x->Parameter = (struct zx_is_Parameter_s*)el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_InteractionStatement
#define EL_STRUCT zx_is_InteractionStatement_s
#define EL_NS     is
#define EL_TAG    InteractionStatement

/* FUNC(zx_DEC_is_InteractionStatement) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_InteractionStatement_s* zx_DEC_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Inquiry_ELEM:
            zx_DEC_is_Inquiry(c, (struct zx_is_Inquiry_s*)el);
            if (!x->Inquiry)
              x->Inquiry = (struct zx_is_Inquiry_s*)el;
            break;
          case zx_ds_Signature_ELEM:
            zx_DEC_ds_Signature(c, (struct zx_ds_Signature_s*)el);
            if (!x->Signature)
              x->Signature = (struct zx_ds_Signature_s*)el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Item
#define EL_STRUCT zx_is_Item_s
#define EL_NS     is
#define EL_TAG    Item

/* FUNC(zx_DEC_is_Item) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Item_s* zx_DEC_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_label_ATTR:  x->label = x->gg.attr; break;
    case zx_value_ATTR:  x->value = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Hint_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Hint)
              x->Hint = el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Parameter
#define EL_STRUCT zx_is_Parameter_s
#define EL_NS     is
#define EL_TAG    Parameter

/* FUNC(zx_DEC_is_Parameter) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Parameter_s* zx_DEC_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_name_ATTR:  x->name = x->gg.attr; break;
    case zx_value_ATTR:  x->value = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Select
#define EL_STRUCT zx_is_Select_s
#define EL_NS     is
#define EL_TAG    Select

/* FUNC(zx_DEC_is_Select) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Select_s* zx_DEC_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_multiple_ATTR:  x->multiple = x->gg.attr; break;
    case zx_name_ATTR:  x->name = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Help_ELEM:
            zx_DEC_is_Help(c, (struct zx_is_Help_s*)el);
            if (!x->Help)
              x->Help = (struct zx_is_Help_s*)el;
            break;
          case zx_is_Hint_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Hint)
              x->Hint = el;
            break;
          case zx_is_Label_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Label)
              x->Label = el;
            break;
          case zx_is_Value_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Value)
              x->Value = el;
            break;
          case zx_is_Item_ELEM:
            zx_DEC_is_Item(c, (struct zx_is_Item_s*)el);
            if (!x->Item)
              x->Item = (struct zx_is_Item_s*)el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG







/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   is_Text
#define EL_STRUCT zx_is_Text_s
#define EL_NS     is
#define EL_TAG    Text

/* FUNC(zx_DEC_is_Text) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_is_Text_s* zx_DEC_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x )
{
  int tok MAYBE_UNUSED;  /* Unused in zx_DEC_root() */
  struct zx_elem_s* el;
  struct zx_ns_s* pop_seen;

  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = zx_attr_lookup(c, (struct zx_elem_s*)x, (const char*)__FUNCTION__);
    switch (tok) {
    case zx_format_ATTR:  x->format = x->gg.attr; break;
    case zx_maxChars_ATTR:  x->maxChars = x->gg.attr; break;
    case zx_minChars_ATTR:  x->minChars = x->gg.attr; break;
    case zx_name_ATTR:  x->name = x->gg.attr; break;

    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, (struct zx_elem_s*)x);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
      ++c->p;
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	if (!zx_scan_elem_end(c, ((struct zx_elem_s*)x)->g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = zx_elem_lookup(c, (struct zx_elem_s*)x, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
          case zx_is_Help_ELEM:
            zx_DEC_is_Help(c, (struct zx_is_Help_s*)el);
            if (!x->Help)
              x->Help = (struct zx_is_Help_s*)el;
            break;
          case zx_is_Hint_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Hint)
              x->Hint = el;
            break;
          case zx_is_Label_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Label)
              x->Label = el;
            break;
          case zx_is_Value_ELEM:
            zx_DEC_simple_elem(c, el);
            if (!x->Value)
              x->Value = el;
            break;

	  default:
	    zx_known_elem_wrong_context(c, (struct zx_elem_s*)x);
	    break;
	  }
	  zx_pop_seen(pop_seen);
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, (struct zx_elem_s*)x))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists((struct zx_elem_s*)x);
  ZX_END_DEC_EXT(x);
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG




/* EOF -- c/zx-is-dec.c */
