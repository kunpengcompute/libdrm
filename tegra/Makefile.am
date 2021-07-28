AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/include/drm

AM_CFLAGS = \
	@PTHREADSTUBS_CFLAGS@ \
	$(WARN_CFLAGS) \
	-fvisibility=hidden

libdrm_tegra_ladir = $(libdir)
libdrm_tegra_la_LTLIBRARIES = libvmidrm_tegra.la
libdrm_tegra_la_LDFLAGS = -version-number 0:0:0 -no-undefined
libdrm_tegra_la_LIBADD = ../libdrm.la @PTHREADSTUBS_LIBS@

libdrm_tegra_la_SOURCES = \
	private.h \
	tegra.c

libdrm_tegraincludedir = ${includedir}/libdrm
libdrm_tegrainclude_HEADERS = tegra.h

pkgconfigdir = @pkgconfigdir@
pkgconfig_DATA = libvmidrm_tegra.pc

AM_TESTS_ENVIRONMENT = NM='$(NM)'
TESTS = tegra-symbol-check
EXTRA_DIST = $(TESTS)
