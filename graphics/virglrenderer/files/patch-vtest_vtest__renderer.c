--- vtest/vtest_renderer.c.orig	2019-09-05 12:10:54 UTC
+++ vtest/vtest_renderer.c
@@ -34,6 +34,7 @@
 
 #include <sys/uio.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <sys/mman.h>
 
 #include "vtest.h"
@@ -140,7 +141,7 @@ int vtest_block_read(struct vtest_input *input, void *
    if (getenv("VTEST_SAVE")) {
       if (savefd == -1) {
          savefd = open(getenv("VTEST_SAVE"),
-                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_DSYNC, S_IRUSR|S_IWUSR);
+                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_SYNC, S_IRUSR|S_IWUSR);
          if (savefd == -1) {
             perror("error opening save file");
             exit(1);
