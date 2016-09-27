#include "qgeomapreplybingmaps.h"
#include <QNetworkAccessManager>
#include <QNetworkCacheMetaData>
#include <QDateTime>

QT_BEGIN_NAMESPACE

QGeoMapReplyBingmaps::QGeoMapReplyBingmaps(QNetworkReply *reply, const QGeoTileSpec &spec, QObject *parent)
        : QGeoTiledMapReply(spec, parent),
        m_reply(reply)
{
    connect(m_reply,
            SIGNAL(finished()),
            this,
            SLOT(networkFinished()));

    connect(m_reply,
            SIGNAL(error(QNetworkReply::NetworkError)),
            this,
            SLOT(networkError(QNetworkReply::NetworkError)));
}

QGeoMapReplyBingmaps::~QGeoMapReplyBingmaps()
{
}

QNetworkReply *QGeoMapReplyBingmaps::networkReply() const
{
    return m_reply;
}

void QGeoMapReplyBingmaps::abort()
{
    if (!m_reply)
        return;

    m_reply->abort();
}

void QGeoMapReplyBingmaps::networkFinished()
{
    if (!m_reply)
        return;

    if (m_reply->error() != QNetworkReply::NoError)
        return;

    setMapImageData(m_reply->readAll());
    const int _mid = tileSpec().mapId();
    if (_mid == 0 || _mid == 1)
        setMapImageFormat("png");
    else
        setMapImageFormat("jpeg");
    setFinished(true);

    m_reply->deleteLater();
    m_reply = 0;
}

void QGeoMapReplyBingmaps::networkError(QNetworkReply::NetworkError error)
{
    if (!m_reply)
        return;

    if (error != QNetworkReply::OperationCanceledError)
        setError(QGeoTiledMapReply::CommunicationError, m_reply->errorString());
    setFinished(true);
    m_reply->deleteLater();
    m_reply = 0;
}

QT_END_NAMESPACE
