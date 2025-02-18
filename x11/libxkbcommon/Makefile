# $FreeBSD$

PORTNAME=	libxkbcommon
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://xkbcommon.org/download/
DIST_SUBDIR=	xorg/lib

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Keymap handling library for toolkits and window systems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE


USES=		bison meson pkgconfig tar:xz
MESON_ARGS=	-Denable-docs=false \
		-Denable-wayland=false \
		-Dx-locale-root="${PREFIX}/lib/X11/locale"

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

X11_USES=	xorg
X11_USE=	XORG=xcb
X11_MESON_TRUE=	enable-x11
X11_RUN_DEPENDS=xkeyboard-config>0:x11/xkeyboard-config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1200000
MESON_ARGS+=	-Ddefault-rules=xorg
.endif

.include <bsd.port.post.mk>
