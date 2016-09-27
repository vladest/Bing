#ifndef QGEOMAPREPLYBINGMAPS_H
#define QGEOMAPREPLYBINGMAPS_H

#include <QtNetwork/QNetworkReply>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotiledmapreply_p.h>
#include <QtCore/QPointer>

QT_BEGIN_NAMESPACE

class QGeoMapReplyBingmaps : public QGeoTiledMapReply
{
    Q_OBJECT

public:
    QGeoMapReplyBingmaps(QNetworkReply *reply, const QGeoTileSpec &spec, QObject *parent = 0);
    ~QGeoMapReplyBingmaps();

    void abort();

    QNetworkReply *networkReply() const;

private Q_SLOTS:
    void networkFinished();
    void networkError(QNetworkReply::NetworkError error);

private:
    QPointer<QNetworkReply> m_reply;
};

QT_END_NAMESPACE

#endif
