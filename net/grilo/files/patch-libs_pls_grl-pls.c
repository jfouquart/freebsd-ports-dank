From 60d135ef64f16671bb0ab4079ecbc59bdc32cbc7 Mon Sep 17 00:00:00 2001
From: Bastien Nocera <hadess@hadess.net>
Date: Tue, 12 Nov 2019 19:44:04 +0100
Subject: [PATCH] pls: Support totem-pl-parser 3.26.4

---
 libs/pls/grl-pls.c | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/libs/pls/grl-pls.c b/libs/pls/grl-pls.c
index 62c578b..f6121cc 100644
--- libs/pls/grl-pls.c
+++ libs/pls/grl-pls.c
@@ -47,6 +47,10 @@
 #include <totem-pl-parser.h>
 #include <totem-pl-parser-mini.h>
 
+#ifndef TOTEM_PL_IS_PARSER(x)
+#define TOTEM_PL_IS_PARSER(x) TOTEM_IS_PL_PARSER(x)
+#endif /* TOTEM_PL_IS_PARSER */
+
 /* --------- Constants -------- */
 
 #define GRL_DATA_PRIV_PLS_IS_PLAYLIST   "priv:pls:is_playlist"
@@ -465,7 +469,7 @@ grl_pls_playlist_entry_parsed_cb (TotemPlParser *parser,
   GRL_DEBUG ("%s (parser=%p, uri=\"%s\", metadata=%p, user_data=%p)",
       __FUNCTION__, parser, uri, metadata, user_data);
 
-  g_return_if_fail (TOTEM_IS_PL_PARSER (parser));
+  g_return_if_fail (TOTEM_PL_IS_PARSER (parser));
   g_return_if_fail (uri);
   g_return_if_fail (metadata);
   g_return_if_fail (user_data);
-- 
2.24.1

