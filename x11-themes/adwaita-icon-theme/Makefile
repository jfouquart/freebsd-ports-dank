# Created by: Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	adwaita-icon-theme
PORTVERSION=	3.36.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

NO_ARCH=	yes
USES=		gettext-tools gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GTK_ENCODE_SYMBOLIC_SVG="false"
# INSTALLS_ICONS=	yes # <DankBSD> this is a dep of gtk3, which is what provides gtk-update-icon-cache for us

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/locale
	@${RM} -r ${STAGEDIR}${PREFIX}/locale

.include <bsd.port.mk>
