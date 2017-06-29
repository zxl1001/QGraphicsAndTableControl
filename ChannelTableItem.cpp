
#include "ChannelRecordWidget.h"
#include "ChannelTableItem.h"
#include "ui_ChannelTableItem.h"
#include <QProgressBar>
#include <QHeaderView>

ChannelTableItem::ChannelTableItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelTableItem),
    m_minXValue(0),
    m_maxXValue(100),
    m_minYValue(0),
    m_maxYValue(200),
    m_timeLine(Q_NULLPTR)
{
    ui->setupUi(this);
    m_timeLine = new ChannelTimeLineItem(m_minXValue,m_maxXValue,m_minYValue,m_maxYValue,this);
    ui->timeLineLayout->addWidget(m_timeLine);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnWidth(0,100);
}

ChannelTableItem::~ChannelTableItem()
{
    delete ui;
}

void ChannelTableItem::cleanRecord()
{
    for(int i=0; i<ui->tableWidget->rowCount(); ++i)
    {
        ui->tableWidget->removeCellWidget(i,1);
    }
    ui->tableWidget->clear();
}

void ChannelTableItem::updateChannelRecord(int num)
{
    cleanRecord();
    ui->tableWidget->setRowCount(num);
    for(int i=0; i<num; ++i)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("Channel_%1").arg(i+1)));
        ui->tableWidget->setCellWidget(i,1,new ChannelRecordWidget(m_minXValue,m_maxXValue,m_minYValue,m_maxYValue));
        ui->tableWidget->setRowHeight(i,200);
    }
}
