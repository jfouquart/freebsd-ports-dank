# $FreeBSD$

PORTNAME=	audex
PORTVERSION=	0.95
CATEGORIES=	audio kde

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Audex is an audio grabber tool for CD-ROM drives built with KDE Frameworks

LICENSE=	GPLv3

LIB_DEPENDS=	libcdda_paranoia.so:audio/cdparanoia

USES=		cmake desktop-file-utils kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config coreaddons libkcddb libkcompactdisc kcmutils \
		kio solid xmlgui textwidgets sonnet completion \
		iconthemes configwidgets jobwidgets widgetsaddons \
		crash service i18n
USE_QT=		buildtools core gui dbus network svg xml concurrent \
		qmake_build script widgets x11extras

USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	f84b6c9670c0ac017e5a42715ea1305790bd4cbf

OPTIONS_DEFINE=		EYED3 FAAC FLAC LAME VORBIS
OPTIONS_DEFAULT=	FLAC VORBIS
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

EYED3_DESC=		Unicode MP3 tag support via audio/py-eyed3
EYED3_RUN_DEPENDS=	eyeD3:audio/py-eyed3

FAAC_RUN_DEPENDS=	faac:audio/faac

FLAC_RUN_DEPENDS=	flac:audio/flac

LAME_RUN_DEPENDS=	lame:audio/lame

VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools

.include <bsd.port.mk>
