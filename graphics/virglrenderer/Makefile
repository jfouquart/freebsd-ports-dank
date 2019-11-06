# Created by: 
# $FreeBSD$

PORTNAME=	virglrenderer
PORTVERSION=	0.8.0
CATEGORIES=	graphics

MAINTAINER=	moa
COMMENT=	VirGL virtual OpenGL renderer

LICENSE=	MIT

#BUILD_DEPENDS=	gem:devel/ruby-gems \
		go>=1.5.3:lang/go

HAS_CONFIGURE=	yes
USES=		autoreconf gmake pkgconfig libtool python

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy

USE_GL+=        gl egl gbm

CONFIGURE_ARGS+= --with-glx

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	virgl
GL_PROJECT=	virglrenderer
# Find the commit hash here: https://gitlab.freedesktop.org/virgl/virglrenderer/tags
GL_COMMIT=	${PORTVERSION}
COMMIT=		48cc96c9aebb9d0164830a157efc8916f08f00c0

WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_COMMIT}-${COMMIT}

.include <bsd.port.mk>
