--- utils/encoderassistant.cpp.orig	2019-09-25 13:07:26 UTC
+++ utils/encoderassistant.cpp
@@ -88,7 +88,7 @@ bool EncoderAssistant::available(const EncoderAssistan
     case EncoderAssistant::OGGENC : return (KProcess::execute(ENCODER_OGGENC_BIN, QStringList() << ENCODER_OGGENC_VERSION_PARA)==0);
     case EncoderAssistant::FLAC : return (KProcess::execute(ENCODER_FLAC_BIN, QStringList() << ENCODER_FLAC_VERSION_PARA)==0);
     case EncoderAssistant::FAAC : return (KProcess::execute(ENCODER_FAAC_BIN, QStringList() << ENCODER_FAAC_VERSION_PARA)==1);
-    case EncoderAssistant::WAVE : return (KProcess::execute(ENCODER_WAVE_BIN, QStringList() << ENCODER_WAVE_VERSION_PARA)==0);
+    case EncoderAssistant::WAVE : return true;
     case EncoderAssistant::CUSTOM : return true;
     default : return false;
 
