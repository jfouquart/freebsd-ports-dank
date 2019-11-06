$OpenBSD: patch-js_ui_screenShield_js,v 1.3 2017/11/04 16:44:50 jasper Exp $

REVERT:
From ddea54a5398c123a4711243e55811c8ba26f8b85 Mon Sep 17 00:00:00 2001
From: Victor Toso <victortoso@redhat.com>
Date: Thu, 12 May 2016 09:25:49 +0200
Subject: ScreenShield: set LockedHint property from systemd

--- js/ui/screenShield.js.orig	2019-03-12 00:04:59.000000000 +0100
+++ js/ui/screenShield.js	2019-03-19 14:31:42.880201000 +0100
@@ -528,6 +528,12 @@ var ScreenShield = class {
         this._loginManager.connect('prepare-for-sleep',
                                    this._prepareForSleep.bind(this));
 
+        this._settings = new Gio.Settings({ schema_id: SCREENSAVER_SCHEMA });
+        this._settings.connect('changed::' + LOCK_ENABLED_KEY, this._syncInhibitor.bind(this));
+
+        this._lockSettings = new Gio.Settings({ schema_id: LOCKDOWN_SCHEMA });
+        this._lockSettings.connect('changed::' + DISABLE_LOCK_KEY, this._syncInhibitor.bind(this));
+
         this._loginSession = null;
         this._loginManager.getCurrentSessionProxy(sessionProxy => {
             this._loginSession = sessionProxy;
@@ -539,12 +545,6 @@ var ScreenShield = class {
             this._syncInhibitor();
         });
 
-        this._settings = new Gio.Settings({ schema_id: SCREENSAVER_SCHEMA });
-        this._settings.connect('changed::' + LOCK_ENABLED_KEY, this._syncInhibitor.bind(this));
-
-        this._lockSettings = new Gio.Settings({ schema_id: LOCKDOWN_SCHEMA });
-        this._lockSettings.connect('changed::' + DISABLE_LOCK_KEY, this._syncInhibitor.bind(this));
-
         this._isModal = false;
         this._hasLockScreen = false;
         this._isGreeter = false;
@@ -579,9 +579,6 @@ var ScreenShield = class {
 
         if (prevIsActive != this._isActive)
             this.emit('active-changed');
-
-        if (this._loginSession)
-            this._loginSession.SetLockedHintRemote(active);
 
         this._syncInhibitor();
     }
