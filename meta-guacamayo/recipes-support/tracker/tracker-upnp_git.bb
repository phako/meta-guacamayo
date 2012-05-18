DESCRIPTION = "Tracker Upnp"
LICENSE = "LGPL2.1"
LIC_FILES_CHKSUM = "file://COPYING;md5=ee31012bf90e7b8c108c69f197f3e3a4"
DEPENDS = "vala-native glib-2.0 tracker"
HOMEPAGE = "http://gitorious.org/tracker-upnp"

SRCREV = "7bfee9cadfdc06a53fe5921b6abf50c4e09948e0"
PR = "r0"
PV = "0.1.5+git${SRCPV}"

inherit autotools pkgconfig vala

SRC_URI = "git://gitorious.org/tracker-upnp/tracker-upnp.git;proto=git"
S = "${WORKDIR}/git"
