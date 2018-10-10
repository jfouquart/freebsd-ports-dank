--- vtest/vtest_server.c.orig
+++ vtest/vtest_server.c
@@ -31,6 +31,7 @@
 #include <netinet/in.h>
 #include <sys/un.h>
 #include <fcntl.h>
+#include <string.h>

 #include "util.h"
 #include "vtest.h"

