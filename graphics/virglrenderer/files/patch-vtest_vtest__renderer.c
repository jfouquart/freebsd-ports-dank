--- vtest/vtest_renderer.c.orig
+++ vtest/vtest_renderer.c
@@ -31,6 +31,7 @@
 #include "virglrenderer.h"

 #include <sys/uio.h>
+#include <sys/stat.h>
 #include "vtest.h"
 #include "vtest_protocol.h"
 #include "util.h"
@@ -96,7 +97,7 @@ int vtest_block_read(int fd, void *buf, int size)
    if (getenv("VTEST_SAVE")) {
       if (savefd == -1) {
          savefd = open(getenv("VTEST_SAVE"),
-                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_DSYNC, S_IRUSR|S_IWUSR);
+                       O_CLOEXEC|O_CREAT|O_WRONLY|O_TRUNC|O_SYNC, S_IRUSR|S_IWUSR);
          if (savefd == -1) {
             perror("error opening save file");
             exit(1);
