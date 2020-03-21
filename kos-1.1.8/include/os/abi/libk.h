/* KallistiOS 1.1.8

   os/abi/libk.h
   (c)2000-2001 Dan Potter

   libk.h,v 1.1.1.1 2002/10/09 13:59:15 tekezo Exp

*/

#ifndef __LIBK_H
#define __LIBK_H

#include <sys/cdefs.h>
__BEGIN_DECLS

/* Kernel get-service call */
extern void* (*ko_get_svc)(char *name);

/* Provide a nicer looking alternative */
#define lib_open ko_get_svc

/* For now this does nothing (bad!) */
#define lib_close(lib)

/* Convienence macros for opening and closing libs */
#ifndef __cplusplus
#define OPEN_LIB(var, ident) \
	var = lib_open(ident); \
	if (!var) { printf("can't open '%s' abi\r\n", ident); return -1; }
#else
#define OPEN_LIB(var, type, ident) \
	var = (type)lib_open(ident); \
	if (!var) { printf("can't open '%s' abi\r\n", ident); return -1; }
#endif

__END_DECLS

#endif	/* __LIBK_H */

