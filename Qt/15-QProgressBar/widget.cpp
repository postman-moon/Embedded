#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbDownload->setMaximum(100);
    ui->pbDownload->setMinimum(0);
    ui->pbDownload->setValue(0);

    ui->pbCopy->setRange(0, 1000);
    ui->pbCopy->setValue(0);
    ui->pbCopy->setFormat("%v/%m");

    ui->pbNetwork->setMinimum(0);
    ui->pbNetwork->setMaximum(0);
    ui->pbNetwork->setFormat("");

    // timer
    timerDownload = new QTimer(this);
    timerDownload->setInterval(100);

    timerCopy = new QTimer(this);
    timerCopy->setInterval(10);

    // connect
    connect(ui->btnDownload, &QPushButton::clicked, this, &Widget::handleBtnClicked);
    connect(ui->btnCopy, &QPushButton::clicked, this, &Widget::handleBtnClicked);
    connect(timerDownload, &QTimer::timeout, this, &Widget::handleTimeout);
    connect(timerCopy, &QTimer::timeout, this, &Widget::handleTimeout);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleBtnClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if (!btn)
        return;

    if (btn == ui->btnDownload) {
        ui->pbDownload->reset();
        timerDownload->start();
    } else if (btn == ui->btnCopy) {
        ui->pbCopy->reset();
        timerCopy->start();
    }
}

void Widget::handleTimeout()
{
    QTimer *timer = qobject_cast<QTimer *>(sender());

    if (!timer)
        return ;

    if (timer == timerDownload) {
        int val = ui->pbDownload->value();

        if (val >= ui->pbDownload->maximum()) {
            timerDownload->stop();
            QMessageBox::information(this, "提示", "文件下载成功");
        } else {
            ui->pbDownload->setValue(++val);
        }

    } else if (timer == timerCopy) {
        int val = ui->pbCopy->value();

        if (val >= ui->pbCopy->maximum()) {
            timerCopy->stop();
            QMessageBox::information(this, "提示", "文件拷贝成功");
        } else {
            ui->pbCopy->setValue(++val);
        }
    }
}
