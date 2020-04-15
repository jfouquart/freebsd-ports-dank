# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$

PORTNAME=	seahorse
PORTVERSION=	3.36
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3
LICENSE=	GPLv2+

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gnupg>=2.1.4:security/gnupg \
		valac:lang/vala \
		openssh-portable>0:security/openssh-portable \
		itstool:textproc/itstool
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libhandy-0.0.so:x11-toolkits/libhandy \
		libpwquality.so:security/libpwquality \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnupg>=2.1.4:security/gnupg

PORTSCOUT=	limitw:1,even

USE_XORG=	sm
USE_LDCONFIG=	yes
USES=		gettext gnome localbase meson \
		pkgconfig python:3.5+ tar:xz xorg
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP AVAHI
OPTIONS_DEFAULT=LDAP AVAHI
LDAP_MESON_TRUE=	ldap-support
LDAP_USE=	OPENLDAP=yes
LDAP_DESC=	LDAP keyserver support (for gpg)
AVAHI_DESC=	DNS-SD key sharing
AVAHI_MESON_TRUE=	key-sharing
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-patch:
	${REINPLACE_CMD} "s@\(cc.find_library(.*\))@\1,dirs:'${PREFIX}/lib')@" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
