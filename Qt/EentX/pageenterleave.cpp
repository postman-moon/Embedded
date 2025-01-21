#include "pageenterleave.h"

static int cnt = 1;

PageEnterLeave::PageEnterLeave(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    LabelX *labX = new LabelX();
    // lab->setText("鼠标进入/离开");
    labX->setFrameShape(QFrame::Box);
    labX->setFixedHeight(50);
    labX->setAlignment(Qt::AlignCenter);
    labX->setStyleSheet("background-color: skyblue; color: white; font-size: 25px;");

    verticalLayout->addWidget(labX);

    // 2. 添加一个标准的标签控件
    lab = new QLabel(this);
    lab->setFrameShape(QFrame::Box);
    lab->setFixedHeight(50);
    lab->setAlignment(Qt::AlignCenter);
    lab->setStyleSheet("background-color: pink; color: white; font-size: 25px;");

    verticalLayout->addWidget(lab);

    // 为标签安装事件过滤器
    lab->installEventFilter(this);
}

bool PageEnterLeave::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == lab) {
        if (event->type() == QEvent::Enter) {
            lab->setText(QString("enterEvent: %1").arg(cnt++));
        } else if (event->type() == QEvent::Leave) {
            lab->setText(QString("leaveEvent: %1").arg(cnt++));
        }
    }

    return QWidget::eventFilter(watched, event);
}
