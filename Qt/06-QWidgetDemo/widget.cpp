#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

#if 0
    // 未指定父窗口，这个窗口就是独立的窗口
    // 需要调用其show方法，来将其显示
    SubWidget *subWidget = new SubWidget();
    subWidget->setWindowTitle("SubWidget");
    subWidget->show();
#endif

#if 0
    // 如果制定了父窗口，这个窗口就是内嵌窗口
    // 就不需要调用其show方法，因为其父窗口显示时，会自动显示子窗口
    SubWidget *subWidget = new SubWidget(this);
    subWidget->setWindowTitle("SubWidget");
#endif



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnGetSize_clicked()
{
    qDebug() << "---------------------------";
    QRect rect = this->geometry();

    qDebug() << "左上角：" << rect.topLeft();
    qDebug() << "右上角：" << rect.topRight();
    qDebug() << "左下角：" << rect.bottomLeft();
    qDebug() << "右下角：" << rect.bottomRight();
    qDebug() << "宽：" << rect.width();
    qDebug() << "高：" << rect.height();

}


void Widget::on_btnSetSize_clicked()
{
    this->resize(400, 400);
}


void Widget::on_btnSetFixedSize_clicked()
{
    this->setFixedSize(500, 500);
}


void Widget::on_btnSetMaxSize_clicked()
{
    this->setMaximumSize(600, 600);
}


void Widget::on_btnSetMinSize_clicked()
{
    this->setMinimumSize(300, 300);
}


void Widget::on_btnMove_clicked()
{
    this->move(100, 100);
}


void Widget::on_btnSetIcon_clicked()
{
    this->setWindowIcon(QIcon(":/images/icon.png"));
}


void Widget::on_btnSetTitle_clicked()
{
    this->setWindowTitle("QWidget演示");
}

