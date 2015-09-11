/*	$OpenBSD$	*/
/*
 * Copyright (c) 2015 Philip Guenther <guenther@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef  _LIBC_RMD160_H
#define  _LIBC_RMD160_H

#include_next <rmd160.h>

PROTO_NORMAL(RMD160Data);
PROTO_NORMAL(RMD160End);
PROTO_NORMAL(RMD160File);
PROTO_NORMAL(RMD160FileChunk);
PROTO_NORMAL(RMD160Final);
PROTO_NORMAL(RMD160Init);
PROTO_NORMAL(RMD160Pad);
PROTO_NORMAL(RMD160Transform);
PROTO_NORMAL(RMD160Update);

#endif  /* _LIBC_RMD160_H */
