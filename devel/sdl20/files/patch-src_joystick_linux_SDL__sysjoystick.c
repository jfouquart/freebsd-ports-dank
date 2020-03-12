--- src/joystick/linux/SDL_sysjoystick.c.orig	2020-03-09 22:15:34 UTC
+++ src/joystick/linux/SDL_sysjoystick.c
@@ -26,6 +26,8 @@
 #error SDL now requires a Linux 2.4+ kernel with /dev/input/event support.
 #endif
 
+#define DEBUG_INPUT_EVENTS 1
+#define DEBUG_JOYSTICK 1
 /* This is the Linux implementation of the SDL joystick API */
 
 #include <sys/stat.h>
