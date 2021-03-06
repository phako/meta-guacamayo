DESCRIPTION = "For us to know and for you to wonder ..."
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${GUACABASE}/meta-guacamayo/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

PR = "r0"

GUACAMAYO_FEATURES =+ "package-management"

# Extra Image features
GUACAMAYO_FEATURES =+ "\
		      guacamayo-restricted \
		      guacamayo-mex \
		      guacamayo-gles-tests \
		      "

inherit guacamayo-image
