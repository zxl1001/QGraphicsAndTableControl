#ifndef CHANNELVIEW_H
#define CHANNELVIEW_H

#include "ChannelScene.h"
#include <QGraphicsView>
#include <QResizeEvent>


class ChannelView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ChannelView(QWidget *parent=0);
    virtual ~ChannelView();

    void updateChannelRecord(int num);
private:
    void resizeEvent(QResizeEvent *event);
    ChannelScene *m_scene;
};

#endif // CHANNELVIEW_H
