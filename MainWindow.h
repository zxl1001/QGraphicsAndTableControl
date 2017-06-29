#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ChannelView.h"
//#include "Form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_updateChannelBtn_clicked();

private:
    Ui::MainWindow *ui;
    ChannelView *m_view;
//    Form *m_form;
};

#endif // MAINWINDOW_H
