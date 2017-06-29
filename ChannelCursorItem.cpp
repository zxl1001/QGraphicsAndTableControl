/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    FormTimeCursor.cpp
 * @brief
 *******************************************************************************
 */
#include "ChannelCursorItem.h"
#include <QPainter>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>

ChannelCursorItem::ChannelCursorItem(QGraphicsItem *parent)
    :QGraphicsRectItem(parent),
      m_size(20,10),
      m_cursoPos(0,0)
{
    setZValue(1000);
    setRect(0,0,10, 10);
}

ChannelCursorItem::~ChannelCursorItem()
{

}

void ChannelCursorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, false);
    painter->beginNativePainting();
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    QPolygonF polygon;
    polygon.append(QPointF(-10,0));
    polygon.append(QPointF(10,0));
    polygon.append(QPointF(0,20));
    painter->drawPolygon(polygon);
    painter->drawLine(QPointF(0,0), QPointF(0, widget->size().height()));
    painter->endNativePainting();
}
