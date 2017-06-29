#include "ChannelScene.h"
#include <QPointF>
#include <QDebug>

ChannelScene::ChannelScene(QObject *parent)
    :QGraphicsScene(parent),
      m_timeCursor(new ChannelCursorItem),
      m_chWidget(new ChannelTableItem),
      m_isDragIng(false),
      m_timeCursorLeftBound(100),
      m_timeCursorRightBound(100)
{

    m_timeCursor->setX(m_timeCursorLeftBound);
    addItem(m_timeCursor);
    m_chProxyWidget = addWidget(m_chWidget);
    startTimer(50);
}

ChannelScene::~ChannelScene()
{
    if(m_chProxyWidget)
    {
        delete m_chProxyWidget;
        m_chProxyWidget = Q_NULLPTR;
    }
}

void ChannelScene::resetRect(const QRectF &rect)
{
    m_timeCursorRightBound = rect.width() - 13;
    setSceneRect(rect);
    m_chProxyWidget->setPos(rect.x(), rect.y());
    m_chProxyWidget->resize(rect.size());
}

void ChannelScene::updateChannelRecord(int num)
{
    m_chWidget->updateChannelRecord(num);
}

void ChannelScene::timerEvent(QTimerEvent *event)
{
    if(m_isDragIng)
    {
        return;
    }
    m_timeCursor->setX(m_timeCursor->x() + 10);
    if(m_timeCursor->pos().x() > m_timeCursorRightBound)
    {
        m_timeCursor->setX(m_timeCursorLeftBound);
    }
    update();
}

void ChannelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(event->scenePos().x() > m_timeCursor->pos().x() - 10
                && event->scenePos().x() < m_timeCursor->pos().x()+10
                && event->scenePos().y() > 0 && event->scenePos().y() < 20)
        {
            m_isDragIng = true;
        }
    }
}

void ChannelScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(m_isDragIng)
    {
        m_timeCursor->setX(event->scenePos().x());
        if(m_timeCursor->x() < m_timeCursorLeftBound)
        {
            m_timeCursor->setX(m_timeCursorLeftBound);
        }

        if(m_timeCursor->x() > m_timeCursorRightBound)
        {
            m_timeCursor->setX(m_timeCursorRightBound);
        }
        update();
    }
}

void ChannelScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_isDragIng)
    {
        m_isDragIng = false;
    }
}

