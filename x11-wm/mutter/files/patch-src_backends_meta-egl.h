--- src/backends/meta-egl.h.orig	2019-12-19 08:50:07 UTC
+++ src/backends/meta-egl.h
@@ -27,6 +27,8 @@
 
 #include <EGL/egl.h>
 #include <EGL/eglext.h>
+#include <EGL/eglmesaext.h>
+#include <EGL/eglextchromium.h>
 #include <glib-object.h>
 
 #define META_EGL_ERROR meta_egl_error_quark ()
