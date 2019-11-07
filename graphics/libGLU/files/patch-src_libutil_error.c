--- src/libutil/error.c.orig	2019-08-14 07:07:37 UTC
+++ src/libutil/error.c
@@ -31,7 +31,7 @@
 #include "gluos.h"
 #include "gluint.h"
 #include <GL/glu.h>
-
+#include <stddef.h>
 
 struct token_string
 {
