# Created by: ijliao
# $FreeBSD$

PORTNAME=	fribidi
PORTVERSION=	1.0.9
CATEGORIES=	converters
MASTER_SITES=	https://github.com/fribidi/fribidi/releases/download/v${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson tar:xz
USE_LDCONFIG=	yes

post-patch:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' < \
		${FILESDIR}/fribidi-config > ${WRKDIR}/fribidi-config

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fribidi-config ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
