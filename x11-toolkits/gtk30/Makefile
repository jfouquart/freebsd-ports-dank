# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.24.18
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/commit/
PATCHFILES+=	6893f59aa10f7c711de653ce023b136f422a1519.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1624
PATCHFILES+=	5c10282f00fa074df56864ebef86256319c5fabd.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1441
PATCHFILES+=	5b40f07d69c0864851c03eee38d1d554dd45872d.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1441
PATCHFILES+=	209b149c8ca98ca6820a6fec6ddac86c5bec3682.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1441
PATCHFILES+=	7e435ca755567948e2dbd155b610bcd1ad95089d.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1415
PATCHFILES+=	3110edf96b3b5e0377583e3c8a9008b7dba9ab6b.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1416
PATCHFILES+=	0df855aa4f9d58bf9790d0f1845257d496622095.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1482
PATCHFILES+=	70064c52f445ca83f83e0f7f2c6a90e00279b095.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	04ffe8e9a68cdf0e39aae6bc814c4227f281cbc9.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	ee6243393334f1134b1f03f54c90d27838bb5fe9.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	d5bcf6ab9479e21bf7c9776c985af89f61e23f62.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	d57313f9a4fa129e80a48bf26d37ab89f7f10e71.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

PORTSCOUT=	limit:1,even

BUILD_DEPENDS+=	at-spi2-atk>=0:accessibility/at-spi2-atk
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		at-spi2-atk>=0:accessibility/at-spi2-atk \
		librsvg2>=0:graphics/librsvg2

USE_PERL5=	build
USE_LDCONFIG=	yes
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango
USES=		compiler:c11 gettext gnome meson localbase:ldflags \
		pathfix perl5 python:3.5+ pkgconfig shared-mime-info tar:xz
CPPFLAGS+=	-fno-omit-frame-pointer
# INSTALLS_ICONS=	yes # <DankBSD> we're the gtk-update-icon-cache, this would be a self dep

LIBVERSION=	0.2410.7
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	CUPS CLOUDPRINT COLORD DEBUG BROADWAY WAYLAND X11
OPTIONS_DEFAULT=CUPS COLORD BROADWAY WAYLAND X11
OPTIONS_SUB=	yes

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_MESON_TRUE=	broadway_backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_YES=colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_ENABLE=	cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_MESON_ON=	
CLOUDPRINT_USE=		gnome=libxml2
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libsoup-2.4.so:devel/libsoup \
			libjson-glib-1.0.so:devel/json-glib

WAYLAND_DESC=		GDK Wayland backend
WAYLAND_MESON_TRUE=	wayland_backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
			v4l_compat>=0:multimedia/v4l_compat
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl

X11_MESON_TRUE=	x11_backend
X11_USES=	xorg
X11_USE=	XORG=xext,xrender,x11,xinerama,xi,xrandr,xcursor,xfixes,xdamage,xcomposite

.include <bsd.port.options.mk>

PRINT_BACKENDS+=	file
.if ${PORT_OPTIONS:MCUPS}
PRINT_BACKENDS+=	cups
.endif
.if ${PORT_OPTIONS:MCLOUDPRINT}
PRINT_BACKENDS+=	cloudprint
.endif

MESON_ARGS+=	-Dprint_backends="${PRINT_BACKENDS:ts,}"

pre-configure-X11-on:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

pre-build:
	@${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders
	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-3.0.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
