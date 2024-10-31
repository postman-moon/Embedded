#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnGetText_clicked()
{
    QMessageBox::information(this, "标签演示", ui->labTime->text());
}


void Widget::on_btnSetText_clicked()
{
    ui->labTime->setText(QTime::currentTime().toString());
}


void Widget::on_btnAlignLeft_clicked()
{
    ui->labAlign->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}


void Widget::on_btnAlignCenter_clicked()
{
    ui->labAlign->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}


void Widget::on_btnAlignRight_clicked()
{
    ui->labAlign->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}


void Widget::on_btnDisableWrap_clicked()
{
    ui->labWrap->setWordWrap(false);
}


void Widget::on_btnEnableWrap_clicked()
{
    ui->labWrap->setWordWrap(true);
}


void Widget::on_btnToggleImage_clicked()
{
    QPixmap pixmap;

    if (index == 0) {
        pixmap.load(":/images/stop.png");
        index ++;
    } else {
        pixmap.load(":/images/start.png");
        index = 0;
    }

    // 把图片显示到标签上
    ui->labImage->setPixmap(pixmap);

    // 不要缩放，保持图片的宽高比，不然会失真
    ui->labImage->setScaledContents(false);

    // 居中显示图片
    ui->labImage->setAlignment(Qt::AlignCenter);
}

