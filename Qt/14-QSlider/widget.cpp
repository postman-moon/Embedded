#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化红色滑动条
    ui->sliderRed->setRange(0, 255);
    ui->sliderRed->setSingleStep(1);
    ui->sliderRed->setPageStep(10);
    ui->sliderRed->setOrientation(Qt::Horizontal);
    ui->sliderRed->setValue(0);
    ui->lineRed->setText(QString::number(0));

    // 初始化绿色滑动条
    ui->sliderGreen->setRange(0, 255);
    ui->sliderGreen->setSingleStep(5);
    ui->sliderGreen->setPageStep(20);
    ui->sliderGreen->setOrientation(Qt::Horizontal);
    ui->sliderGreen->setValue(0);
    ui->lineGreen->setText(QString::number(0));

    // 初始化蓝色滑动条
    ui->sliderBlue->setRange(0, 255);
    ui->sliderBlue->setSingleStep(10);
    ui->sliderBlue->setPageStep(100);
    ui->sliderBlue->setOrientation(Qt::Horizontal);
    ui->sliderBlue->setValue(0);
    ui->lineBlue->setText(QString::number(0));

    QString style = QString("background-color: rgb(0, 0, 0);");
    ui->lineEdit->setStyleSheet(style);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sliderRed_valueChanged(int value)
{
    QString red = QString::number(value);
    QString green = QString::number(ui->sliderGreen->value());
    QString blue = QString::number(ui->sliderBlue->value());

    ui->lineRed->setText(red);

    QString style = QString("background-color: rgb(%1, %2, %3)").arg(red)
                                                                .arg(green)
                                                                .arg(blue);
    ui->lineEdit->setStyleSheet(style);
}


void Widget::on_sliderGreen_valueChanged(int value)
{
    QString red = QString::number(ui->sliderRed->value());
    QString green = QString::number(value);
    QString blue = QString::number(ui->sliderBlue->value());

    ui->lineGreen->setText(green);

    QString style = QString("background-color: rgb(%1, %2, %3)").arg(red)
                        .arg(green)
                        .arg(blue);
    ui->lineEdit->setStyleSheet(style);

}


void Widget::on_sliderBlue_valueChanged(int value)
{
    QString red = QString::number(ui->sliderRed->value());
    QString green = QString::number(ui->sliderGreen->value());
    QString blue = QString::number(value);

    ui->lineBlue->setText(blue);

    QString style = QString("background-color: rgb(%1, %2, %3)").arg(red)
                        .arg(green)
                        .arg(blue);
    ui->lineEdit->setStyleSheet(style);
}

