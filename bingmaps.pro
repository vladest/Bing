TARGET = qtgeoservices_bingmaps
QT += location-private positioning-private network

PLUGIN_TYPE = geoservices
PLUGIN_CLASS_NAME = QGeoServiceProviderFactoryBingMaps
load(qt_plugin)

HEADERS += \
    qgeoserviceproviderpluginbingmaps.h \
    qgeomapreplybingmaps.h \
    qgeotiledmapbingmaps.h \
    qgeotiledmappingmanagerenginebingmaps.h \
    qgeotilefetcherbingmaps.h

SOURCES += \
    qgeoserviceproviderpluginbingmaps.cpp \
    qgeomapreplybingmaps.cpp \
    qgeotiledmapbingmaps.cpp \
    qgeotiledmappingmanagerenginebingmaps.cpp \
    qgeotilefetcherbingmaps.cpp


OTHER_FILES += \
    bingmaps_plugin.json

