# Created by: 
# $FreeBSD$

PORTNAME=	GtkD
PORTVERSION=	3.8.3
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-toolkits

MAINTAINER=	moa
COMMENT=	GtkD is the Digital Mars D programming language OO wrapper for Gtk+ 3.

LICENSE=	LGPL3

USES=		gmake gl gnome
MAKEFILE=	GNUmakefile

SSP_UNSAFE=	yes

BUILD_DEPENDS=	ldmd2:lang/ldc \
		gdk-pixbuf-pixdata:graphics/gdk-pixbuf2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libpeas-1.0.so:devel/libpeas \
		libgstreamer-1.0.so:multimedia/gstreamer1

USE_GNOME=	gtk30 gtksourceview3 vte3
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	gtkd-developers


.include <bsd.port.mk>
