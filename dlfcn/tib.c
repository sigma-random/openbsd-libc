/*	$OpenBSD$ */
/*
 * Copyright (c) 2016 Philip Guenther <guenther@openbsd.org>
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

#include <tib.h>

#ifndef PIC
# include <stdlib.h>		/* malloc and free */
#endif

#define ELF_ROUND(x,malign)	(((x) + (malign)-1) & ~((malign)-1))


/*
 * The functions here are weak so that the ld.so versions are used
 * in dynamic links, whether or not libc is static
 */
void	*_dl_allocate_tib(size_t _extra) __attribute__((weak));
void	_dl_free_tib(void *_tib, size_t _extra) __attribute__((weak));

/*
 * Allocate a TIB for passing to __tfork for a new thread.  'extra'
 * is the amount of space to allocate on the side of the TIB opposite
 * of the TLS data: before the TIB for variant 1 and after the TIB
 * for variant 2.  If non-zero, tib_thread is set to point to that area.
 */
void *
_dl_allocate_tib(size_t extra)
{
#ifdef PIC
	return NULL;			/* overriden by ld.so */
#else
	char *base;
	char *thread;
	struct tib *tib;

# if TLS_VARIANT == 1
	/* round up the extra size to align the tib after it */
	extra = ELF_ROUND(extra, sizeof(void *));
	base = malloc(extra + sizeof(struct tib) + _static_tls_size);
	tib = (struct tib *)(base + extra);
	thread = base;

# elif TLS_VARIANT == 2
	/* round up the tib size to align the extra area after it */
	base = malloc(ELF_ROUND(sizeof(struct tib), TIB_EXTRA_ALIGN) +
	    extra + _static_tls_size);
	tib = (struct tib *)(base + _static_tls_size);
	thread = (char *)tib + ELF_ROUND(sizeof(struct tib), TIB_EXTRA_ALIGN);
# endif

	_static_tls_init(base);
	TIB_INIT(tib, NULL, thread);

	return (tib);
#endif /* !PIC */
}

void
_dl_free_tib(void *tib, size_t extra)
{
#ifndef PIC
	size_t tib_offset;

# if TLS_VARIANT == 1
	tib_offset = ELF_ROUND(extra, sizeof(void *));
# elif TLS_VARIANT == 2
	tib_offset = _static_tls_size;
# endif

	free((char *)tib - tib_offset);
#endif /* !PIC */
}
