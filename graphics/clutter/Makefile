# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter
PORTVERSION=	1.26.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS+=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcogl.so:graphics/cogl \
		libgdk-3.so:x11-toolkits/gtk30 \
		libinput.so:x11/libinput

PORTSCOUT=	limit:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 pango introspection:build
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--enable-egl-backend=yes \
		--enable-x11-backend=yes \
		--enable-wayland-compositor=yes \
		--enable-gdk-backend=yes \
		--enable-evdev-input=yes
INSTALL_TARGET=	install-strip

PLIST_FILES+=	include/clutter-1.0/clutter/wayland/clutter-wayland.h \
		include/clutter-1.0/clutter/wayland/clutter-wayland-compositor.h \
		include/clutter-1.0/clutter/wayland/clutter-wayland-surface.h \
		include/clutter-1.0/clutter/evdev/clutter-evdev.h \
		include/clutter-1.0/clutter/gdk/clutter-gdk.h \
		lib/girepository-1.0/ClutterGdk-1.0.typelib \
		libdata/pkgconfig/clutter-wayland-1.0.pc \
		libdata/pkgconfig/clutter-wayland-compositor-1.0.pc \
		libdata/pkgconfig/clutter-gdk-1.0.pc

.include <bsd.port.mk>
