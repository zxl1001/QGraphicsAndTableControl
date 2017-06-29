#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_view(new ChannelView(this))
{
    ui->setupUi(this);
    ui->channelViewLayout->addWidget(m_view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_updateChannelBtn_clicked()
{
    m_view->updateChannelRecord(200);
}
