#ifndef CHANNELSCENE_H
#define CHANNELSCENE_H

#include "ChannelCursorItem.h"
#include "ChannelTableItem.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class ChannelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChannelScene(QObject *parent = 0);
    virtual ~ChannelScene();
    void resetRect(const QRectF &rect);
    void updateChannelRecord(int num);
    void timerEvent(QTimerEvent *event);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    ChannelCursorItem *m_timeCursor;
    ChannelTableItem *m_chWidget;
    QGraphicsProxyWidget *m_chProxyWidget;
    bool m_isDragIng;
    int m_timeCursorLeftBound;
    int m_timeCursorRightBound;
};

#endif // CHANNELSCENE_H
