# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evince
PORTVERSION=	3.36.0
CATEGORIES=	graphics print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GNOME multi-format document viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-builder:devel/appstream-glib \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libfribidi.so:converters/fribidi \
		libspectre.so:print/libspectre \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even
SLAVEPORT?=	no

USES=		compiler:c++11-lib desktop-file-utils gettext \
		gnome libarchive localbase meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dps=enabled

.if ${SLAVEPORT} == lite
MESON_ARGS+=-Dintrospection=false \
		-Dthumbnail_cache=false \
		-Dthumbnailer=false \
		-Dpreviewer=false
USE_GNOME+=	libxml2
.else
USE_GNOME+=	introspection:build
.endif

GLIB_SCHEMAS=	org.gnome.Evince.gschema.xml

PLIST_SUB=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	COMICS DBUS DJVU DVI KEYRING NAUTILUS GSPELL T1LIB XPS
OPTIONS_DEFAULT=COMICS DBUS DJVU KEYRING NAUTILUS GSPELL XPS

COMICS_DESC=			Comic book archives support
COMICS_MESON_ENABLED=	comics

DJVU_DESC=		DJVU support
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_ENABLED=	djvu

DBUS_MESON_TRUE=	dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

DVI_DESC=		DVI viewer support
DVI_USE=		tex=latex,kpathsea
DVI_MESON_ENABLED=	dvi

GSPELL_DESC=		Spell checking via gspell
GSPELL_MESON_ENABLED=	gspell
GSPELL_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
			libgspell-1.so:textproc/gspell

KEYRING_DESC=			Keyring support
KEYRING_LIB_DEPENDS=		libsecret-1.so:security/libsecret
KEYRING_MESON_ENABLED=		keyring

NAUTILUS_DESC=			Nautilus plugin
NAUTILUS_USE=			gnome=nautilus3
NAUTILUS_MESON_TRUE=	nautilus

T1LIB_DESC=		Support TYPE1 fonts to DVI (Enables DVI)
T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_ENABLED=	t1lib
T1LIB_IMPLIES=		DVI

XPS_DESC=	XPS support
XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_ENABLED=	xps

.include <bsd.port.mk>
