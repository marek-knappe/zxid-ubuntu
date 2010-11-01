/* c/zx-dst-dec.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-dst-data.h"
#define TPF zx_
#include "zx_ext_pt.h"




/* These macros allow extension macros such as ZX_START_DEC_EXT(x) to be parametrised. */

#define EL_NAME   dst_TestResult
#define EL_STRUCT zx_dst_TestResult_s
#define EL_NS     dst
#define EL_TAG    TestResult

/* FUNC(zx_DEC_dst_TestResult) */

/*() Element Decoder. When per element decoder is called, the c->p
 * will point to just past the element name. The element has already
 * been allocated to the correct size and the namespace prescan has
 * already been done. */

/* Called by: */
struct zx_dst_TestResult_s* zx_DEC_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x )
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
    case zx_dst_itemIDRef_ATTR:  x->itemIDRef = x->gg.attr; break;

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




/* EOF -- c/zx-dst-dec.c */
