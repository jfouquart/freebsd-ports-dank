--- src/backends/meta-egl-ext.h.orig	2019-12-19 08:50:21 UTC
+++ src/backends/meta-egl-ext.h
@@ -29,6 +29,8 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
+#include <EGL/eglextchromium.h>
 
 /*
  * This is a little different to the tests shipped with EGL implementations,
