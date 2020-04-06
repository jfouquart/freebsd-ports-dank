# $FreeBSD$

PORTNAME=	amtk
PORTVERSION=	5.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Actions, Menus and Toolbars Kit for GTK applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	glib20 gtk30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
