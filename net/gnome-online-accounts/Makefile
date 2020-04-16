# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.36.0
CATEGORIES=	net
# MASTER_SITES=	GNOME
# XXX: no meson in tarball
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interface provider to access the user's online accounts

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		valac:lang/vala
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		librest-0.7.so:devel/librest \
		libp11-kit.so:security/p11-kit \
		libgck-1.so:security/gcr

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome \
		localbase meson pkgconfig python:3.5+ tar:xz
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	a0931a8253e09e18768270f97b5e093e9df82fa8
USE_GNOME=	cairo gtk30 introspection:build libxml2 libxslt:build
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
MESON_ARGS=	-Dlastfm=true \
		-Dkerberos=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.online-accounts.gschema.xml

.include <bsd.port.mk>
