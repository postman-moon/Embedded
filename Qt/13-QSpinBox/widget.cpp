#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 单价
    // 设置范围
    ui->dsbPrice->setMinimum(1.00);
    ui->dsbPrice->setMaximum(99.99);
    // ui->dsbPrice->setRange(1.00, 99.99);

    // 设置前缀
    ui->dsbPrice->setPrefix("￥");

    // 设置步长
    ui->dsbPrice->setSingleStep(0.5);

    // 设置加速
    ui->dsbPrice->setAccelerated(true);

    // 设置循环
    ui->dsbPrice->setWrapping(true);

    // 2. 数量
    // 设置范围
    ui->sbWeight->setRange(100, 200);

    // 设置后缀
    ui->sbWeight->setSuffix("KG");

    // 设置步长
    ui->sbWeight->setSingleStep(2);

    // 设置加速
    ui->sbWeight->setAccelerated(true);

    // 设置循环
    ui->sbWeight->setWrapping(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_dsbPrice_valueChanged(double arg1)
{
    double weight = ui->sbWeight->value();

    ui->lineTotal->setText(QString::number(arg1 * weight));
}


void Widget::on_sbWeight_valueChanged(int arg1)
{
    double price = ui->dsbPrice->value();

    ui->lineTotal->setText(QString::number(arg1 * price));
}

