# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pulseaudio
DISTVERSIONPREFIX=	v
DISTVERSION=	13.99.1-35
DISTVERSIONSUFFIX=	-g062fc45cd
CATEGORIES=	audio

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound server for UNIX

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libdbus-1.so:devel/dbus \
		libltdl.so:devel/libltdl \
		libck-connector.so:sysutils/consolekit2

USES=		compiler:c11 cpe gettext gnome iconv localbase meson \
		pathfix pkgconfig python:run shebangfix ssl tar:xz

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	myfreeweb
GL_COMMIT=	5a53e2dc67aee6e100cfbe6213e0fd3ec0becd06
USE_GNOME=	glib20
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	shell-completion/bash/pulseaudio \
		scripts/benchmark_memory_usage.sh \
		src/utils/pa-info \
		src/utils/qpaeq
bash_CMD=	${SETENV} bash
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	-Db_lundef=false \
		-Dlocalstatedir=/var \
		-Dipv6=true \
		-Dfftw=enabled \
		-Ddbus=enabled \
		-Dbluez5=false \
		-Dudev=disabled \
		-Dgtk=disabled \
		-Dsystemd=disabled \
		-Dlirc=disabled # untested

USERS=		pulse
GROUPS=		pulse pulse-access pulse-rt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI GSETTINGS SIMD TEST X11
OPTIONS_DEFAULT=AVAHI GSETTINGS SIMD SIMPLE SOXR SPEEX WEBRTC_AEC X11
AVAHI_MESON_ENABLED=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
GSETTINGS_DESC=	GSettings configuration backend support
GSETTINGS_MESON_ENABLED=	gsettings
GSETTINGS_VARS=	GLIB_SCHEMAS=org.freedesktop.pulseaudio.gschema.xml
SIMD_MESON_ENABLED=	orc
SIMD_LIB_DEPENDS=	liborc-0.4.so:devel/orc
TEST_TEST_TARGET=	test
TEST_MESON_TRUE=	tests
TEST_BUILD_DEPENDS=	check>0:devel/check
X11_MESON_ENABLED=	x11
X11_USES=		xorg
X11_USE=		XORG=ice,sm,x11,xcb,xtst

OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA JACK SOXR SPEEX WEBRTC_AEC
AUDIO_DESC=		Audio support
ALSA_MESON_ENABLED=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
JACK_MESON_ENABLED=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
SOXR_MESON_ENABLED=	soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SPEEX_DESC=		Speex resampler and AEC support
SPEEX_MESON_ENABLED=	speex
SPEEX_LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp
WEBRTC_AEC_DESC=	WebRTC-based echo canceller
WEBRTC_AEC_LIB_DEPENDS=	libwebrtc_audio_processing.so:audio/webrtc-audio-processing
WEBRTC_AEC_MESON_ENABLED=	webrtc-aec

OPTIONS_SINGLE=			DATABASE
OPTIONS_SINGLE_DATABASE=	TDB GDBM SIMPLE
DATABASE_DESC=		Database support
GDBM_DESC=		GNU database manager support
GDBM_MESON_ON=	-Ddatabase=gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
SIMPLE_DESC=		Simple database support
SIMPLE_MESON_ON=	-Ddatabase=simple
TDB_DESC=		Trivial database support
TDB_MESON_ON=		-Ddatabase=tdb
TDB_LIB_DEPENDS=	libtdb.so:databases/tdb

PULSE_VERSION=	${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PLIST_SUB=	PULSE_VERSION=${PULSE_VERSION}

post-extract:
	@${PRINTF} "%s" "${DISTVERSION}${DISTVERSIONSUFFIX}" > ${WRKSRC}/.tarball-version

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/daemon/default.pa.in
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		-e 's|--directory|-d|g' \
		${WRKSRC}/src/utils/pa-info

pre-install-TEST-on: do-test

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pulse
.for ii in default.pa daemon.conf system.pa
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/daemon/${ii} \
		${STAGEDIR}${PREFIX}/etc/pulse/${ii}.sample
.endfor
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/pulse/client.conf \
		${STAGEDIR}${PREFIX}/etc/pulse/client.conf.sample
# Delete ${STAGEDIR}${PREFIX}/libexec/pulse directory, if it's empty
	@(cd ${STAGEDIR}${PREFIX}/libexec && \
		${FIND} * -maxdepth 0 -type d -empty -name pulse -delete)

.include <bsd.port.mk>
