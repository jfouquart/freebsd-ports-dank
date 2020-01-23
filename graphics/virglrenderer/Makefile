# Created by: 
# $FreeBSD$

PORTNAME=	virglrenderer
PORTVERSION=	0.8.1
CATEGORIES=	graphics

MAINTAINER=	moa
COMMENT=	VirGL virtual OpenGL renderer

LICENSE=	MIT

#BUILD_DEPENDS=	gem:devel/ruby-gems \
		go>=1.5.3:lang/go

HAS_CONFIGURE=	yes
USES=		autoreconf gl meson pkgconfig libtool python:3.7+

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy

USE_GL+=        gl egl gbm

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	virgl
GL_PROJECT=	virglrenderer
# Find the commit hash here: https://gitlab.freedesktop.org/virgl/virglrenderer/tags
GL_COMMIT=	${PORTNAME}-${PORTVERSION}
COMMIT=		66c57963aaf09a1c41056bd2a001da1d51957a14

WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_COMMIT}-${COMMIT}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
