#ifndef CHANNELTIMELINEITEM_H
#define CHANNELTIMELINEITEM_H

#include <QWidget>

class ChannelTimeLineItem : public QWidget
{
    Q_OBJECT
public:
    explicit ChannelTimeLineItem(int minX, int maxX, int minY, int maxY, QWidget *parent=0);
    virtual ~ChannelTimeLineItem();

private:
    void paintEvent(QPaintEvent *event);
private:
    int m_trick;
    int m_timeLineTop;

    int m_minXValue;
    int m_maxXValue;
    int m_minYValue;
    int m_maxYValue;
};

#endif // CHANNELTIMELINEITEM_H
