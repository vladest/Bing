#ifndef QGEOTILEFETCHERBINGMAPS_H
#define QGEOTILEFETCHERBINGMAPS_H

#include "qgeoserviceproviderpluginbingmaps.h"

#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QMutex>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE

class QGeoTiledMapReply;
class QGeoTileSpec;
class QGeoTiledMappingManagerEngine;
class QGeoTiledMappingManagerEngineBingmaps;
class QNetworkAccessManager;

class QGeoTileFetcherBingmaps : public QGeoTileFetcher
{
    Q_OBJECT

public:
    QGeoTileFetcherBingmaps(const QVariantMap &parameters,
                         QGeoTiledMappingManagerEngineBingmaps *engine, const QSize &tileSize);
    ~QGeoTileFetcherBingmaps();

    QGeoTiledMapReply *getTileImage(const QGeoTileSpec &spec);

private:
    QString _getURL(int type, int x, int y, int zoom);

private slots:
    void _networkReplyError(QNetworkReply::NetworkError error);
    void _replyDestroyed();

private:
    Q_DISABLE_COPY(QGeoTileFetcherBingmaps)

    QNetworkAccessManager *m_networkManager;

    QPointer<QGeoTiledMappingManagerEngineBingmaps> m_engineBingmaps;
    QSize m_tileSize;

    int             _timeout;
    QNetworkReply*  _bingReply;
    QByteArray      _userAgent;
    QString         _language;

    // Bing version strings
    QString         _versionBingMaps;

    QNetworkRequest netRequest;
};

QT_END_NAMESPACE

#endif
