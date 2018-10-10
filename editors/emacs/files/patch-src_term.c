--- src/term.c.orig
+++ src/term.c
@@ -4156,6 +4156,12 @@ use the Bourne shell command 'TERM=...; export TERM' (C-shell:\n\
 	    tty->TS_set_background = bg;
 	    tty->TN_max_colors = 16777216;
 	  }
+	else if (tigetnum ("Tc"))
+	  {
+	    tty->TS_set_foreground = "\E[38;2;%p1%{65536}%/%d;%p1%{256}%/%{255}%&%d;%p1%{255}%&%dm";
+	    tty->TS_set_background = "\E[48;2;%p1%{65536}%/%d;%p1%{256}%/%{255}%&%d;%p1%{255}%&%dm";
+	    tty->TN_max_colors = 16777216;
+	  }
       }
 #endif
 
