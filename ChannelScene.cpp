#include "ChannelScene.h"
#include <QPointF>
#include <QDebug>

ChannelScene::ChannelScene(QObject *parent)
    :QGraphicsScene(parent),
      m_LineItem(new ChannelCursorItem),
      m_chWidget(new ChannelTableItem),
      m_isDragIng(false)
{

    addItem(m_LineItem);
    m_chProxyWidget = addWidget(m_chWidget);
    startTimer(30);
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
    m_LineItem->setX(m_LineItem->x() + 10);
    if(m_LineItem->pos().x() > sceneRect().width())
    {
        m_LineItem->setX(-10);
    }
    update();
}

void ChannelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(event->scenePos().x() > m_LineItem->pos().x() - 10
                && event->scenePos().x() < m_LineItem->pos().x()+10
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
        m_LineItem->setX(event->scenePos().x());
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

