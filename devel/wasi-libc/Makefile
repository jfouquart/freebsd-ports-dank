# $FreeBSD$

PORTNAME=	wasi-libc
DISTVERSION=	g20200229
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	WASI libc implementation for WebAssembly

LICENSE=	APACHE20 MIT LLVM2
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_LLVM2=	${WRKSRC}/LICENSE-APACHE-LLVM
LICENSE_NAME_LLVM2=	Apache License 2.0 with LLVM Exceptions
LICENSE_PERMS_LLVM2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	CraneStation
GH_TAGNAME=	0cc57ac7b4c0e48a9e4a99e52538c793f2516f31
GH_TUPLE=	WebAssembly:WASI:85df508:wasi/tools/wasi-headers/WASI
NO_ARCH=	yes
LLVM_VERSION?=	90

ALL_TARGET=	finish

# NOTE: matches the https://github.com/CraneStation/wasi-sdk
WASI_SYSROOT=	${PREFIX}/share/wasi-sysroot

# NOTE: our llvm ports don't ship stdarg/stddef clang headers, so they're in FILESDIR
#       and we install them to the sysroot

MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${WASI_SYSROOT} \
		WASM_AR=${LOCALBASE}/bin/llvm-ar${LLVM_VERSION} \
		WASM_CC=${LOCALBASE}/bin/clang${LLVM_VERSION} \
		WASM_CFLAGS="-O2 -DNDEBUG -I${FILESDIR}" \
		WASM_NM=${LOCALBASE}/bin/llvm-nm${LLVM_VERSION}

# NOTE: phony targets cause make install to rebuild everything
#       https://github.com/CraneStation/wasi-libc/issues/156
post-patch:
	${REINPLACE_CMD} -e 's|install: finish|install:|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/stdarg.h ${STAGEDIR}${WASI_SYSROOT}/include/
	${INSTALL_DATA} ${FILESDIR}/stddef.h ${STAGEDIR}${WASI_SYSROOT}/include/

.include <bsd.port.mk>
