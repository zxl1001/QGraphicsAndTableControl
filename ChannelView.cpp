#include "ChannelView.h"

ChannelView::ChannelView(QWidget *parent)
    :QGraphicsView(parent),
      m_scene(new ChannelScene(this))
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setScene(m_scene);
}

ChannelView::~ChannelView()
{

}

void ChannelView::updateChannelRecord(int num)
{
    m_scene->updateChannelRecord(num);
}

void ChannelView::resizeEvent(QResizeEvent *event)
{
    m_scene->resetRect(QRectF(0,0, event->size().width(), event->size().height()));
}
