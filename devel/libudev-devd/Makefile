# $FreeBSD$

PORTNAME=	libudev-devd
PORTVERSION=	0.4.0.1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	libudev-compatible interface for devd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USE_GITHUB=	yes
GH_ACCOUNT=	myfreeweb
GH_TAGNAME=	ab8313d68d6939

USES=		autoreconf gmake libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	include/libudev.h \
		lib/libudev.so \
		lib/libudev.so.0 \
		lib/libudev.so.0.0.0 \
		libdata/pkgconfig/libudev.pc

.include <bsd.port.mk>
