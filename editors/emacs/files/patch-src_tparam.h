--- src/tparam.h.orig
+++ src/tparam.h
@@ -38,6 +38,7 @@ extern char *UP;
 
 #ifdef TERMINFO
 char *tigetstr(const char *);
+int tigetnum (const char *);
 #endif
 
 #endif /* EMACS_TPARAM_H */
