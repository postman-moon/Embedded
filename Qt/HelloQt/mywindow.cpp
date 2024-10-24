#include "mywindow.h"
#include "ui_mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    // ui->btnStart->setText("开始");
    // ui->btnStop->setText("结束");

}

MyWindow::~MyWindow()
{
    delete ui;
}
