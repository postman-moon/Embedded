#include "pagepress.h"

PagePress::PagePress(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *lab = new QLabel(this);
    lab->setText("鼠标按下/移动/释放");
    lab->setFrameShape(QFrame::Box);
    lab->setFixedHeight(50);
    lab->setAlignment(Qt::AlignCenter);
    lab->setStyleSheet("background-color: skyblue; color: white; font-size: 24px");

    widget = new QWidget(this);
    lbl = new QLabel(widget);

    lbl->setFrameShape(QFrame::Box);
    lbl->setFixedSize(100, 100);
    lbl->setStyleSheet("background-color: pink");

    verticalLayout->addWidget(lab);
    verticalLayout->addWidget(widget);

    // 安装事件过滤器
    lbl->installEventFilter(this);
}

bool PagePress::eventFilter(QObject *watched, QEvent *event)
{
    if (watched != lbl)
        return QWidget::eventFilter(watched, event);

    if (event->type() == QEvent::MouseButtonPress) {
        qDebug() << "MouseButtonPress";

        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        pressPos = mouseEvent->globalPos();
        wdPos = lbl->pos();

    } else if (event->type() == QEvent::MouseMove) {
        qDebug() << "MouseMove";

        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QPoint dstPos = wdPos + (mouseEvent->globalPos() - pressPos);

        lbl->move(dstPos);

    } else if (event->type() == QEvent::MouseButtonRelease) {
        qDebug() << "MouseButtonRelease";
    }
}
