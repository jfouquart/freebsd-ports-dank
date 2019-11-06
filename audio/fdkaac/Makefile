# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdkaac
PORTVERSION=	1.0.0
CATEGORIES=	audio

MAINTAINER=	moa
COMMENT=	command line encoder frontend for libfdk-aac

LICENSE=	BSD2CLAUSE BSD4CLAUSE MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac

USES=		autoreconf gmake

USE_GCC=	8+

USE_GITHUB=	yes
GH_ACCOUNT=	nu774
GH_TAGNAME=	${PORTVERSION}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/fdkaac man/man1/fdkaac.1.gz

.include <bsd.port.mk>
