--- variety/VarietyWindow.py.orig	2019-08-11 21:29:19 UTC
+++ variety/VarietyWindow.py
@@ -2588,7 +2588,7 @@ class VarietyWindow(Gtk.Window):
             )
             try:
                 subprocess.check_call(
-                    ["timeout", "--kill-after=5", "10", script, wallpaper, auto, original_file]
+                    ["gtimeout", "--kill-after=5", "10", script, wallpaper, auto, original_file]
                 )
             except subprocess.CalledProcessError as e:
                 if e.returncode == 124:
