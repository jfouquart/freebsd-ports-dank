--- etc/runit/core-services/41-entropy.sh.orig	2020-04-15 16:42:58 UTC
+++ etc/runit/core-services/41-entropy.sh
@@ -4,7 +4,7 @@ save_dev_random() {
 	oumask=$(umask)
 	umask 077
 	for f; do
-		dd if=/dev/random of="$f" bs=4096 count=1 status=none &&
+		dd if=/dev/random of="$f" bs=4096 count=1 status=none 2>/dev/null &&
 			chmod 600 "$f"
 	done
 	umask "${oumask}"
