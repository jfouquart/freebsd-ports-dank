--- src/widgets/temp_freebsd.go.orig	2019-09-26 07:02:54 UTC
+++ src/widgets/temp_freebsd.go
@@ -11,8 +11,8 @@ import (
 )
 
 var sensorOIDS = map[string]string{
-	"dev.cpu.0.temperature":           "CPU 0 ",
 	"hw.acpi.thermal.tz0.temperature": "Thermal zone 0",
+	"hw.acpi.thermal.tz1.temperature": "Thermal zone 1",
 }
 
 type sensorMeasurement struct {
