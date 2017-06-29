#include "ChannelTimeLineItem.h"

#include <QPainter>

ChannelTimeLineItem::ChannelTimeLineItem(int minX, int maxX, int minY, int maxY, QWidget *parent)
    :QWidget(parent),
      m_trick(100),
      m_timeLineTop(20),
      m_minXValue(minX),
      m_maxXValue(maxX),
      m_minYValue(minY),
      m_maxYValue(maxY)
{

}

ChannelTimeLineItem::~ChannelTimeLineItem()
{

}

void ChannelTimeLineItem::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    double xLineScale = (double)(width()) / m_maxXValue;
    int xTrickStep = m_maxXValue / m_trick;
    painter.beginNativePainting();
    painter.setPen(Qt::white);
    painter.setBrush(QBrush(QColor(4,4,4)));
    painter.drawRect(QRect(0,0,width(), 40));
    painter.drawLine(0,m_timeLineTop,width(),m_timeLineTop);
    for(int i=0; i<m_trick; ++i)
    {
        int timeLineBottom = m_timeLineTop + 10;
        QPointF timeStartPos(i * xTrickStep * xLineScale, m_timeLineTop);
        if(i % 10 == 0)
        {
            painter.drawText(timeStartPos, QString::number(i * xTrickStep));
            timeLineBottom = m_timeLineTop + 20;
        }
        painter.drawLine(timeStartPos, QPointF(timeStartPos.x(), timeLineBottom));
    }
    painter.endNativePainting();
}
