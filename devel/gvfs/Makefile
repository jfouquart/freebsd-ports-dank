# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvfs
PORTVERSION=	1.44.1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME virtual file system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libsoup-2.4.so:devel/libsoup \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgcrypt.so:security/libgcrypt \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libgpg-error.so:security/libgpg-error \
		libcdio.so:sysutils/libcdio \
		libudisks2.so:sysutils/libudisks \
		libgudev-1.0.so:devel/libgudev \
		libudev.so:devel/libudev-devd \
		libmtp.so:multimedia/libmtp \
		libjson-glib-1.0.so:devel/json-glib
PORTSCOUT=	limitw:1,even

.if !exists(/usr/bin/ssh)
BUILD_DEPENDS+=	${LOCALBASE}/bin/ssh:security/openssh-portable
.endif

USES=		gettext gnome libarchive localbase meson \
		pkgconfig tar:xz
USE_GNOME=	glib20 libxslt:build
MESON_ARGS=	-Dsystemduserunitdir=no \
		-Dtmpfilesdir=no \
		-Dbluray=false \
		-Dadmin=false \
		-Dlogind=false \
		-Dlibusb=false \
		-Dman=true

INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.system.gvfs.enums.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI SAMBA GPHOTO2 CDDA FUSE AFC GOOGLE NFS
OPTIONS_DEFAULT=AVAHI SAMBA GPHOTO2 CDDA FUSE AFC GOOGLE NFS
CDDA_DESC=	CDDA support
GPHOTO2_DESC=	Gphoto 2 camera support for PTP support
SAMBA_DESC=	Samba support
AFC_DESC=	Apple device support
GOOGLE_DESC=	Google backend

FUSE_USES=	fuse:3
FUSE_MESON_TRUE=	fuse

SAMBA_USES=	samba:lib
SAMBA_MESON_TRUE=	smb

CDDA_LIB_DEPENDS=	libcdio_paranoia.so:sysutils/libcdio-paranoia
CDDA_MESON_TRUE=	cdda

GPHOTO2_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO2_MESON_TRUE=	gphoto2

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	avahi

AFC_LIB_DEPENDS=	libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
AFC_MESON_TRUE=	afc

GOOGLE_MESON_TRUE=	google
GOOGLE_LIB_DEPENDS=	libgdata.so:devel/libgdata

NFS_MESON_TRUE=	nfs
NFS_LIB_DEPENDS=	libnfs.so:net/libnfs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSAMBA}
GLIB_SCHEMAS+=	org.gnome.system.smb.gschema.xml
.endif

.if ${PORT_OPTIONS:MAVAHI}
GLIB_SCHEMAS+=	org.gnome.system.dns_sd.gschema.xml
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/remote-volume-monitors
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
