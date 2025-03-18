#include "pagetimerevent.h"

PageTimerEvent::PageTimerEvent(QWidget *parent)
    : QWidget{parent}
{
    // 创建垂直布局
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 创建一个标签
    labRed = new QLabel(this);
    labRed->setFixedSize(50, 50);
    labRed->setStyleSheet("background-color: red;");

    verticalLayout->addWidget(labRed);

    // 创建一个标签
    labBlue = new QLabel(this);
    labBlue->setFixedSize(50, 50);
    labBlue->setStyleSheet("background-color: blue;");

    verticalLayout->addWidget(labBlue);

    // 创建水平布局
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    verticalLayout->addLayout(horizontalLayout);

    // 创建开始按钮
    btnStart = new QPushButton(this);
    btnStart->setText("开始");
    btnStart->setStyleSheet("font-size: 16px;");

    horizontalLayout->addWidget(btnStart);

    // 创建停止按钮
    btnStop = new QPushButton(this);
    btnStop->setText("停止");
    btnStop->setStyleSheet("font-size: 16px;");
    horizontalLayout->addWidget(btnStop);

    // 创建复位按钮
    btnReset = new QPushButton(this);
    btnReset->setText("复位");
    btnReset->setStyleSheet("font-size: 16px");
    horizontalLayout->addWidget(btnReset);

    connect(btnStart, &QPushButton::clicked, this, &PageTimerEvent::handleBtnClicked);
    connect(btnStop, &QPushButton::clicked, this, &PageTimerEvent::handleBtnClicked);
    connect(btnReset, &QPushButton::clicked, this, &PageTimerEvent::handleBtnClicked);

    // 创建定时器
    timerMove = new QTimer(this);
    timerMove->setInterval(100);
    connect(timerMove, &QTimer::timeout, this, &PageTimerEvent::handleTimeOut);
}

void PageTimerEvent::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1) {
        labRed->move(labRed->x() + 10, labRed->y());
        if (labRed->x() >= this->width()) {
            labRed->move(0, labRed->y());
        }
    } else if (event->timerId() == id2) {
        labBlue->move(labBlue->x() + 20, labBlue->y());
        if (labBlue->x() >= this->width()) {
            labBlue->move(0, labBlue->y());
        }
    }
}

void PageTimerEvent::handleBtnClicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    if (!btn) return;

    if (btn == btnStart) {
#ifdef USE_TIMER_EVENT
        timerMove->start();
#else
        id1 = startTimer(10);
        id2 = startTimer(20);
#endif
    } else if (btn == btnStop) {
#ifdef USE_TIMER_EVENT
        timerMove->stop();
#else
        killTimer(id1);
        killTimer(id2);
#endif
    } else if (btn == btnReset) {
        labRed->move(0, labRed->y());
        labBlue->move(0, labBlue->y());
    }
}

void PageTimerEvent::handleTimeOut()
{
    QTimer *timer = qobject_cast<QTimer *>(sender());

    if (!timer) return;

    if (timer == timerMove) {
        labRed->move(labRed->x() + 10, labRed->y());
        if (labRed->x() >= this->width()) {
            labRed->move(0, labRed->y());
        }

        labBlue->move(labBlue->x() + 20, labBlue->y());
        if (labBlue->x() >= this->width()) {
            labBlue->move(0, labBlue->y());
        }
    }
}
