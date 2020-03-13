# $FreeBSD$

PKGNAMESUFFIX=	-libevent

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	libevent integration for the Avahi mDNS system

LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libevent.so:devel/libevent
RUN_DEPENDS=	avahi-header>=0.8:net/avahi-header

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-libevent
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	libevent
AVAHI_PKGCONFIG=avahi-libevent.pc

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-common
	${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-client
	${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-libevent

do-install:
	@(cd ${WRKSRC}/avahi-libevent; ${MAKE_CMD} ${MAKE_ARGS} \
		install-avahilibeventincludeHEADERS install-libLTLIBRARIES)

.include "${MASTERDIR}/Makefile"
