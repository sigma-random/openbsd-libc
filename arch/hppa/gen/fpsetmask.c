/*	$OpenBSD: fpsetmask.c,v 1.3 2002/10/21 18:41:05 mickey Exp $	*/

/*
 * Written by Miodrag Vallat.  Public domain
 */

#include <sys/types.h>
#include <ieeefp.h>

fp_except
fpsetmask(mask)
	fp_except mask;
{
	u_int64_t fpsr;
	fp_rnd old;

	__asm__ __volatile__("fstd %%fr0,0(%1)" : "=m"(fpsr) : "r"(&fpsr));
	old = (fpsr >> 32) & 0x1f;
	fpsr = (fpsr & 0xffffffe000000000LL) | ((u_int64_t)(mask & 0x1f) << 32);
	__asm__ __volatile__("fldd 0(%0),%%fr0" : : "r"(&fpsr));
	return (old);
}
