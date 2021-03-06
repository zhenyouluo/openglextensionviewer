CONFIG   += warn_on release designer plugin
TARGET   = extfunctionlist
TEMPLATE = lib
LANGUAGE = C++

QT += qt3support

ROOTDIR = /home/msar/CORELIBS

INCLUDEPATH += \
	$$ROOTDIR/filesysascii

SOURCES  = \
	../plugin-common/plugin.cpp \
	../extfunctionlistwidget/extfunctionlistwidget.cpp

HEADERS  = \
	../plugin-common/plugin.h \
	../extfunctionlistwidget/extfunctionlistwidget.h \
	plugincustom.h 

DESTDIR   = ../plugins

target.path == $$[QT_INSTALL_PLUGINS]/designer
sources.files == $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/customwidgetplugin

INSTALLS += target sources

DBFILE    = plugin.db
