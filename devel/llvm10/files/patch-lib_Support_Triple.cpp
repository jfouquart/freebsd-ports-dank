--- lib/Support/Triple.cpp.orig	2020-04-10 20:51:46 UTC
+++ lib/Support/Triple.cpp
@@ -14,6 +14,9 @@
 #include "llvm/Support/Host.h"
 #include "llvm/Support/TargetParser.h"
 #include <cstring>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 using namespace llvm;
 
 StringRef Triple::getArchTypeName(ArchType Kind) {
@@ -1073,6 +1076,13 @@ void Triple::getOSVersion(unsigned &Major, unsigned &M
     OSName.consume_front("macos");
 
   parseVersionFromName(OSName, Major, Minor, Micro);
+
+  if (getOS() == FreeBSD && Major == 0)
+#ifdef __FreeBSD__
+	  Major = __FreeBSD_version / 100000;
+#else
+	  Major = 12;
+#endif
 }
 
 bool Triple::getMacOSXVersion(unsigned &Major, unsigned &Minor,
