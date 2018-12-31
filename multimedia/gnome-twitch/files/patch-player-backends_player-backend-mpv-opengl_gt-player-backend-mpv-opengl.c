Issue also noticed at: https://aur.tuna.tsinghua.edu.cn/packages/gnome-twitch-player-backend-mpv-opengl-git/
--- player-backends/player-backend-mpv-opengl/gt-player-backend-mpv-opengl.c.orig	2018-12-31 18:21:45 UTC
+++ player-backends/player-backend-mpv-opengl/gt-player-backend-mpv-opengl.c
@@ -120,7 +120,7 @@ check_mpv_error(int status)
         ERRORF("Mpv error %s\n", mpv_error_string(status));
 }

-G_DEFINE_AUTOPTR_CLEANUP_FUNC(GParamSpec, g_param_spec_unref);
+//G_DEFINE_AUTOPTR_CLEANUP_FUNC(GParamSpec, g_param_spec_unref);

 /* NOTE: This is so that we notify properies on the GLib main thread,
   * otherwise bad things can happen */
