#include "pagekeyevent.h"

PageKeyEvent::PageKeyEvent(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    labKey = new QLabel(this);

    labKey->setText("");
    labKey->setFrameShape(QFrame::Box);
    labKey->setFixedSize(50, 50);
    labKey->setAlignment(Qt::AlignCenter);
    labKey->setStyleSheet("background-color: skyblue; color: white; font-size: 24px;");

    verticalLayout->addWidget(labKey);

    // 获取焦点
    setFocusPolicy(Qt::StrongFocus);
}

void PageKeyEvent::keyPressEvent(QKeyEvent *event)
{
    // 1. 单个按键
    switch (event->key()) {
    case Qt::Key_Up:
        qDebug() << "Up";
        labKey->move(labKey->x(), labKey->y() - 20);
        if (labKey->y() <= -(labKey->height())) {
            labKey->move(labKey->x(), this->height());
        }
        break;

    case Qt::Key_Down:
        qDebug() << "Down";
        labKey->move(labKey->x(), labKey->y() + 20);
        if (labKey->y() >= this->height()) {
            labKey->move(labKey->x(), 0);
        }
        break;

    case Qt::Key_Left:
        qDebug() << "Left";
        labKey->move(labKey->x() - 20, labKey->y());
        if (labKey->x() <= -(labKey->width())) {
            labKey->move(this->width(), labKey->y());
        }
        break;

    case Qt::Key_Right:
        qDebug() << "right";
        labKey->move(labKey->x() + 20, labKey->y());
        if (labKey->x() >= this->width()) {
            labKey->move(0, labKey->y());
        }
        break;

    default:
        break;
    }

    // 2. 两个按键
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_A) {
        qDebug() << "Ctrl + A";
    }

    if (event->modifiers() == Qt::ShiftModifier && event->key() == Qt::Key_B) {
        qDebug() << "Shift + B";
    }

    if (event->modifiers() == Qt::AltModifier && event->key() == Qt::Key_C) {
        qDebug() << "Alt + C";
    }

    // 3.三个按键
    if ((event->modifiers() == Qt::ControlModifier | Qt::ShiftModifier) && event->key() == Qt::Key_D) {
        qDebug() << "Ctrl + Shift + D";
    }
}

void PageKeyEvent::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        qDebug() << Q_FUNC_INFO << "Up";
        break;

    case Qt::Key_Down:
        qDebug() << Q_FUNC_INFO << "Down";
        break;

    case Qt::Key_Left:
        qDebug() << Q_FUNC_INFO << "Left";
        break;

    case Qt::Key_Right:
        qDebug() << Q_FUNC_INFO << "Right";
        break;
    }

    // 2.两个按键
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_A) {
        qDebug() << Q_FUNC_INFO << "Ctrl + A";
    }

    if (event->modifiers() == Qt::ShiftModifier && event->key() == Qt::Key_B) {
        qDebug() << Q_FUNC_INFO  << "Shift + B";
    }

    if (event->modifiers() == Qt::AltModifier && event->key() == Qt::Key_C) {
        qDebug() << Q_FUNC_INFO << "Alt + C";
    }

    // 3. 三个按键
    if (event->modifiers() == Qt::ControlModifier | Qt::ShiftModifier && event->key() == Qt::Key_D) {
        qDebug() << Q_FUNC_INFO << "Ctrl + Shift +D";
    }
}
