#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->btnStart->setIcon(QIcon(":/images/start.png"));
    ui->btnStart->setIconSize(QSize(32, 32));

    ui->btnSend->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnStart_clicked()
{
    QString str = ui->btnStart->text();

    if (str == "启动") {
        ui->btnStart->setText("停止");
        ui->btnStart->setFont(QFont("黑体", 14));

        ui->btnStart->setIcon(QIcon(":/images/stop.png"));
        ui->btnStart->setIconSize(QSize(32, 32));
    } else {
        ui->btnStart->setText("启动");
        ui->btnStart->setFont(QFont("黑体", 14));

        ui->btnStart->setIcon(QIcon(":/images/start.png"));
        ui->btnStart->setIconSize(QSize(32, 32));
    }
}


void Widget::on_btnConnect_clicked()
{
    QString str = ui->btnConnect->text();

    if (str == "连接") {
        ui->btnConnect->setText("断开连接");
        ui->btnSend->setEnabled(true);
    } else {
        ui->btnConnect->setText("连接");
        ui->btnSend->setEnabled(false);
    }
}


void Widget::on_btnSignal_clicked()
{
    qDebug() << Q_FUNC_INFO << "clicked....";
}


void Widget::on_btnSignal_pressed()
{
    qDebug() << Q_FUNC_INFO << "pressed...";
}


void Widget::on_btnSignal_released()
{
    qDebug() << Q_FUNC_INFO << "released...";
}

