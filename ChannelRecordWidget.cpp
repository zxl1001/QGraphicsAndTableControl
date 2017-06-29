#include "ChannelRecordWidget.h"

ChannelRecordWidget::ChannelRecordWidget(int minX, int maxX, int minY, int maxY, QWidget *parent)
    :QWidget(parent),
      m_minX(minX),
      m_maxX(maxX),
      m_minY(minY),
      m_maxY(maxY)
{

}

void ChannelRecordWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.beginNativePainting();

    double xLineScale = (double)(width()) / m_maxX;
    double yLineScale = (double)(height()) / m_maxY;
    QVector<QPointF> points;
    for(int i=0; i<m_maxX; ++i)
    {
        points.push_back(QPointF(i * xLineScale, (qrand() % m_maxY) * yLineScale));
    }
    painter.setPen(QPen(Qt::blue, 1));
    painter.drawPolyline(points);
    painter.setPen(QPen(Qt::red, 4));
    painter.drawPoints(points);
    painter.endNativePainting();
}
