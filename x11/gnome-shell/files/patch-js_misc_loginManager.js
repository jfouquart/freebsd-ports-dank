$OpenBSD: patch-js_misc_loginManager_js,v 1.4 2017/11/04 16:44:50 jasper Exp $

REVERT:
From ddea54a5398c123a4711243e55811c8ba26f8b85 Mon Sep 17 00:00:00 2001
From: Victor Toso <victortoso@redhat.com>
Date: Thu, 12 May 2016 09:25:49 +0200
Subject: ScreenShield: set LockedHint property from systemd

REVERT:
From a244c1e987502e359c45c0a9bc0012b5bc635553 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Florian=20M=C3=BCllner?= <fmuellner@gnome.org>
Date: Thu, 24 Apr 2014 17:55:56 +0200
Subject: loginManager: Kill ConsoleKit support


--- js/misc/loginManager.js.orig	2019-02-07 02:45:13.000000000 +0100
+++ js/misc/loginManager.js	2019-02-28 09:38:47.821649000 +0100
@@ -2,6 +2,7 @@
 
 const GLib = imports.gi.GLib;
 const Gio = imports.gi.Gio;
+const Lang = imports.lang;
 const Mainloop = imports.mainloop;
 const Shell = imports.gi.Shell;
 const Signals = imports.signals;
@@ -16,6 +17,34 @@
 const SystemdLoginSession = Gio.DBusProxy.makeProxyWrapper(SystemdLoginSessionIface);
 const SystemdLoginUser = Gio.DBusProxy.makeProxyWrapper(SystemdLoginUserIface);
 
+const ConsoleKitManagerIface = `
+<node>
+<interface name="org.freedesktop.ConsoleKit.Manager">
+<method name="CanRestart">
+    <arg type="b" direction="out"/>
+</method>
+<method name="CanStop">
+    <arg type="b" direction="out"/>
+</method>
+<method name="Restart" />
+<method name="Stop" />
+<method name="GetCurrentSession">
+    <arg type="o" direction="out" />
+</method>
+</interface>
+</node>`;
+
+const ConsoleKitSessionIface = `
+<node>
+<interface name="org.freedesktop.ConsoleKit.Session">
+<signal name="Lock" />
+<signal name="Unlock" />
+</interface>
+</node>`;
+
+const ConsoleKitSession = Gio.DBusProxy.makeProxyWrapper(ConsoleKitSessionIface);
+const ConsoleKitManager = Gio.DBusProxy.makeProxyWrapper(ConsoleKitManagerIface);
+
 function haveSystemd() {
     return GLib.access("/run/systemd/seats", 0) >= 0;
 }
@@ -45,7 +74,7 @@
                                                -1, null);
 
         let version = result.deep_unpack()[0].deep_unpack();
-        return haveSystemd() && versionCompare('3.5.91', version);
+        return versionCompare('3.5.91', version);
     } catch(e) {
         return false;
     }
@@ -63,7 +92,7 @@
         if (haveSystemd())
             _loginManager = new LoginManagerSystemd();
         else
-            _loginManager = new LoginManagerDummy();
+            _loginManager = new LoginManagerConsoleKit();
     }
 
     return _loginManager;
@@ -81,6 +110,9 @@
                                   this._prepareForSleep.bind(this));
     }
 
+    // Having this function is a bit of a hack since the Systemd and ConsoleKit
+    // session objects have different interfaces - but in both cases there are
+    // Lock/Unlock signals, and that's all we count upon at the moment.
     getCurrentSessionProxy(callback) {
         if (this._currentSession) {
             callback (this._currentSession);
@@ -179,11 +211,33 @@
 };
 Signals.addSignalMethods(LoginManagerSystemd.prototype);
 
-var LoginManagerDummy = class {
+var LoginManagerConsoleKit = class {
+    constructor() {
+        this._proxy = new ConsoleKitManager(Gio.DBus.system,
+                                            'org.freedesktop.ConsoleKit',
+                                            '/org/freedesktop/ConsoleKit/Manager');
+    }
+
+    // Having this function is a bit of a hack since the Systemd and ConsoleKit
+    // session objects have different interfaces - but in both cases there are
+    // Lock/Unlock signals, and that's all we count upon at the moment.
     getCurrentSessionProxy(callback) {
-        // we could return a DummySession object that fakes whatever callers
-        // expect (at the time of writing: connect() and connectSignal()
-        // methods), but just never calling the callback should be safer
+        if (this._currentSession) {
+            callback (this._currentSession);
+            return;
+        }
+
+        this._proxy.GetCurrentSessionRemote(Lang.bind(this,
+            function(result, error) {
+                if (error) {
+                    logError(error, 'Could not get a proxy for the current session');
+                } else {
+                    this._currentSession = new ConsoleKitSession(Gio.DBus.system,
+                                                                 'org.freedesktop.ConsoleKit',
+                                                                 result[0]);
+                    callback(this._currentSession);
+                }
+            }));
     }
 
     canSuspend(asyncCallback) {
@@ -203,4 +257,4 @@
         callback(null);
     }
 };
-Signals.addSignalMethods(LoginManagerDummy.prototype);
+Signals.addSignalMethods(LoginManagerConsoleKit.prototype);
