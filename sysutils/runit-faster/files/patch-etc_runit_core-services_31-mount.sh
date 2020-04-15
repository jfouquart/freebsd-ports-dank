--- etc/runit/core-services/31-mount.sh.orig	2020-04-15 16:34:38 UTC
+++ etc/runit/core-services/31-mount.sh
@@ -1,7 +1,7 @@
 [ -n "${JAILED}" ] && return 0
 
-echo "=> Mounting / read-write"
-mount -uw / || emergency_shell
+# echo "=> Mounting / read-write"
+# mount -uw / || emergency_shell
 
 echo "=> Mounting all non-network filesystems"
 mount -a || emergency_shell
