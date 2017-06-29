/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    FormTimeCursor.h
 * @brief
 *******************************************************************************
 */
#ifndef CHANNELCURSORITEM_H
#define CHANNELCURSORITEM_H
#include <QGraphicsRectItem>

class ChannelCursorItem : public QGraphicsRectItem
{
public:
    explicit ChannelCursorItem(QGraphicsItem *parent=0);
    virtual ~ChannelCursorItem();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QSize m_size;
    QPointF m_cursoPos;
};

#endif // CHANNELCURSORITEM_H
