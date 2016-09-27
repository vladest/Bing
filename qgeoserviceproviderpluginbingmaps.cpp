#include "qgeoserviceproviderpluginbingmaps.h"
#include "qgeotiledmappingmanagerenginebingmaps.h"


QGeoCodingManagerEngine *QGeoServiceProviderFactoryBingmaps::createGeocodingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)
    return Q_NULLPTR;//new QGeoCodingManagerEngineBingmaps(parameters, error, errorString);
}

QGeoRoutingManagerEngine *QGeoServiceProviderFactoryBingmaps::createRoutingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)

    return Q_NULLPTR;//new QGeoRoutingManagerEngineBingmaps(parameters, error, errorString);
}

QPlaceManagerEngine *QGeoServiceProviderFactoryBingmaps::createPlaceManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters)
    Q_UNUSED(error)
    Q_UNUSED(errorString)

    return Q_NULLPTR;//new QPlaceManagerEngineBingmaps(parameters, error, errorString);
}

QGeoMappingManagerEngine *QGeoServiceProviderFactoryBingmaps::createMappingManagerEngine(
        const QVariantMap &parameters,
        QGeoServiceProvider::Error *error,
        QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineBingmaps(parameters, error, errorString);
}
