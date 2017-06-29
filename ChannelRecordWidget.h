#ifndef CHANNELRECORDWIDGET_H
#define CHANNELRECORDWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class ChannelRecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChannelRecordWidget(int minX, int maxX, int minY, int maxY, QWidget *parent=0);
private:
    void paintEvent(QPaintEvent *event);
private:
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;
};

#endif // CHANNELRECORDWIDGET_H
