#include "QtLocation/private/qgeocameracapabilities_p.h"
#include "qgeotiledmappingmanagerenginebingmaps.h"
#include "qgeotiledmapbingmaps.h"
#include "qgeotilefetcherbingmaps.h"
#include "QtLocation/private/qgeotilespec_p.h"
#include "QtLocation/private/qgeofiletilecache_p.h"

#include <QDebug>
#include <QDir>
#include <QVariant>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/qmath.h>
#include <QtCore/qstandardpaths.h>

QT_BEGIN_NAMESPACE

QGeoTiledMappingManagerEngineBingmaps::QGeoTiledMappingManagerEngineBingmaps(const QVariantMap &parameters,
    QGeoServiceProvider::Error *error,
    QString *errorString)
    : QGeoTiledMappingManagerEngine()
{
    Q_UNUSED(error);
    Q_UNUSED(errorString);

    QGeoCameraCapabilities capabilities;

    capabilities.setMinimumZoomLevel(0.0);
    capabilities.setMaximumZoomLevel(21.0);

    setCameraCapabilities(capabilities);

    int tile = parameters.value(QStringLiteral("Bingmaps.maps.tilesize"), 256).toInt();

    setTileSize(QSize(tile, tile));

    QList<QGeoMapType> types;
    types << QGeoMapType(QGeoMapType::StreetMap,"Bing Street Map", "Bing street map", false, false, 1);
    types << QGeoMapType(QGeoMapType::SatelliteMapDay, "Bing Satellite Map", "Bing satellite map", false, false, 2);
    types << QGeoMapType(QGeoMapType::HybridMap, "Bing Hybrid Map", "Bing hybrid map", false, false, 3);

    setSupportedMapTypes(types);

    QGeoTileFetcherBingmaps *fetcher = new QGeoTileFetcherBingmaps(parameters, this, tileSize());
    setTileFetcher(fetcher);

    m_cacheDirectory = QAbstractGeoTileCache::baseCacheDirectory() + QLatin1String("bingmaps");

    QAbstractGeoTileCache *tileCache = new QGeoFileTileCache(m_cacheDirectory);
    setTileCache(tileCache);

    populateMapSchemes();
}

QGeoTiledMappingManagerEngineBingmaps::~QGeoTiledMappingManagerEngineBingmaps()
{
}

void QGeoTiledMappingManagerEngineBingmaps::populateMapSchemes()
{
    m_mapSchemes[0] = QStringLiteral("roadmap");
    m_mapSchemes[1] = QStringLiteral("roadmap");
    m_mapSchemes[2] = QStringLiteral("satellite");
    m_mapSchemes[3] = QStringLiteral("hybrid");
}

QString QGeoTiledMappingManagerEngineBingmaps::getScheme(int mapId)
{
    return m_mapSchemes[mapId];
}

QGeoMap *QGeoTiledMappingManagerEngineBingmaps::createMap()
{
    return new QGeoTiledMapBingmaps(this);
}

QT_END_NAMESPACE

