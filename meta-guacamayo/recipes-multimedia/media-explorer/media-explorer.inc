DESCRIPTION = "A media centre application for Linux"
SECTION = "x11/multimedia"
LICENSE = "LGPLv2.1"

DEPENDS = "gnome-common glib-2.0 libsoup-2.4 librest gdk-pixbuf grilo \
           clutter-gst-1.10 mx xtst gnome-desktop gssdp connman tracker tracker-upnp"

inherit autotools gettext gtk-doc

SRC_URI = "http://github.com/downloads/media-explorer/media-explorer/${BPN}-${PV}.tar.xz"

INCPR = "r2"

# Cheating, disabling web remote as it needs tracker-sparql-0.10 avahi-glib avahi-client
# Also disable debug buddy as it needs libunwind
EXTRA_OECONF += "--with-online=connman --enable-networks --disable-webremote \
                 --disable-lirc --disable-debug-buddy"

do_install_append() {
    install -d ${D}${sysconfdir}/xdg/autostart
    install -m 0544 ${D}${datadir}/applications/media-explorer.desktop ${D}${sysconfdir}/xdg/autostart

    rm ${D}${libdir}/media-explorer/plugins/*.la

    # Remove unused empty directories
    rmdir ${D}${datadir}/media-explorer/plugins/*
    rmdir ${D}${datadir}/media-explorer/plugins
    rmdir ${D}${datadir}/gir-1.0
    rmdir ${D}${libdir}/girepository-1.0
}

python populate_packages_prepend() {
        plugindir = d.expand('${libdir}/media-explorer/plugins')
        do_split_packages(d, plugindir, '^mex-(.*)\.so$', '${PN}-plugin-%s', 'Media Explorer plugin for %s', allow_dirs=True, prepend=False)
}

PACKAGES_DYNAMIC = "${PN}-plugin-*"

PACKAGES_prepend = "${PN}-autostart "

FILES_${PN} += "${datadir}/icons/hicolor/*/apps/media-explorer.png \
                ${datadir}/dbus-1/services/*.service"
FILES_${PN}-dbg += "${libdir}/media-explorer/plugins/.debug"
FILES_${PN}-autostart = "${sysconfdir}/xdg/autostart"

RDEPENDS_${PN} += "ttf-droid grilo-plugins connman gst-meta-base"
RDEPENDS_${PN}-plugin-tracker += "tracker tracker-upnp"
RDEPENDS_${PN}-autostart = "${PN}"

