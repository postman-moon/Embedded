#include "framelesswidget.h"

FramelessWidget::FramelessWidget(QWidget *parent)
    : QWidget(parent)
{
    // 设置窗口的宽高
    this->setMinimumWidth(500);
    this->setMinimumHeight(300);

    // 设置背景色
    this->setStyleSheet("background-color: #303030");

    // 添加两个按钮 - 水平布局
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);

    QPushButton *btn1 = new QPushButton("确定");
    QPushButton *btn2 = new QPushButton("取消");

    layout->addWidget(btn1);
    layout->addWidget(btn2);

    // 设置按钮样式
    QString style = R"(
        QPushButton {
            background-color: rgb(64, 64, 64);
            font-size: 16px;
            color: rgb(200, 200, 200);
            border: 1px solid #707070;
            border-radius: 5px;
            padding: 5px;
        }

        QPushButton:hover {
            background-color: rgba(64, 64, 64, 0.7);
        }

        QPushButton:pressed {
            background-color: rgb(64, 64, 64);
        }
    )";
    btn1->setStyleSheet(style);
    btn2->setStyleSheet(style);

    // 去除标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    isLeftPressed = false;

    // 开启鼠标追踪
    this->setMouseTracking(true);

}

FramelessWidget::~FramelessWidget()
{
}

void FramelessWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        this->close();
    } else if (event->button() == Qt::LeftButton) {
        isLeftPressed = true;
        mousePos = event->globalPos() - this->frameGeometry().topLeft();
    }
}

void FramelessWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint globalPos = event->globalPos();

    if (isLeftPressed) {
        move(globalPos - mousePos);
    }
}

void FramelessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isLeftPressed = false;
    }
}

