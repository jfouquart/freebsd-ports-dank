--- src/libical/icaltz-util.c.orig	2020-04-13 20:05:50 UTC
+++ src/libical/icaltz-util.c
@@ -37,6 +37,7 @@
 #endif
 #if defined(HAVE_ENDIAN_H)
 #include <endian.h>
+#define bswap_32 bswap32
 #else
 #if defined(HAVE_SYS_ENDIAN_H)
 #include <sys/endian.h>
