/*	$OpenBSD: mbrtowc_sb.c,v 1.1 2005/07/24 09:50:49 espie Exp $	*/
/*	$NetBSD: multibyte_sb.c,v 1.4 2003/08/07 16:43:04 agc Exp $	*/

/*
 * Copyright (c) 1991 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char rcsid[] = "$OpenBSD: mbrtowc_sb.c,v 1.1 2005/07/24 09:50:49 espie Exp $";
#endif /* LIBC_SCCS and not lint */

#include <errno.h>
#include <stdlib.h>
#include <wchar.h>

/*ARGSUSED*/
size_t
mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps)
{

	/* pwc may be NULL */
	/* s may be NULL */
	/* ps appears to be unused */

	if (s == NULL)
		return 0;
	if (n == 0)
		return -1;
	if (pwc)
		*pwc = (wchar_t) *s;
	return (*s != '\0');
}

int
mbtowc(wchar_t *pwc, const char *s, size_t n)
{

	/* pwc may be NULL */
	/* s may be NULL */

	return mbrtowc(pwc, s, n, NULL);
}
