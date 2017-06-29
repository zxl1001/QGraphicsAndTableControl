#ifndef CHANNELTABLEITEM_H
#define CHANNELTABLEITEM_H

#include "ChannelTimeLineItem.h"
#include <QWidget>

namespace Ui {
class ChannelTableItem;
}

class ChannelTableItem : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelTableItem(QWidget *parent = 0);
    ~ChannelTableItem();
    void cleanRecord();
    void updateChannelRecord(int num);

private:
    Ui::ChannelTableItem *ui;
    ChannelTimeLineItem *m_timeLine;
    int m_minXValue;
    int m_maxXValue;
    int m_minYValue;
    int m_maxYValue;

};

#endif // CHANNELTABLEITEM_H
