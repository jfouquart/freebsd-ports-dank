# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cogl
PORTVERSION=	1.22.6
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	clutter-1.6.[0-9]*

LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

USES=		gettext gl gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 pango introspection:build
USE_GL=		egl gbm
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	\
		 --enable-kms-egl-platform=yes \
		 --enable-wayland-egl-platform=yes \
		 --enable-wayland-egl-server=no
# server broken: no member named 'pf_eglQueryWaylandBuffer' in 'struct _CoglRendererEGL'
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xdamage,xext,xfixes,xrandr
X11_CONFIGURE_ENABLE=	glx xlib-egl-platform
X11_CONFIGURE_WITH=	x

PLIST_SUB=	LIBVER=20 LIBVERSION=20.4.2

.include <bsd.port.mk>
