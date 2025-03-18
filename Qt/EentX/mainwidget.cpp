#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // 1. 整体采用水平布局
    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    // 2. 左侧导航窗体
    navWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(navWidget);
    leftLayout->setSpacing(0);
    leftLayout->setContentsMargins(0, 0, 0, 0);

    horizontalLayout->addWidget(navWidget);

    // 3. 右侧主体布局 - 子界面
    mainWidget = new QWidget(this);
    mainWidget->setMinimumWidth(400);

    QVBoxLayout *rightLayout = new QVBoxLayout(mainWidget);
    rightLayout->setSpacing(0);
    rightLayout->setContentsMargins(0, 0, 0, 0);

    stackedWidget = new QStackedWidget(mainWidget);
    rightLayout->addWidget(stackedWidget);

    horizontalLayout->addWidget(mainWidget);

    initNav();
    initMain();
}

MainWidget::~MainWidget() {}

void MainWidget::handleBtnClicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    if (!btn) return ;

    int id = btnGroup->checkedId();
    stackedWidget->setCurrentIndex(id);
}

void MainWidget::initNav()
{
    QStringList nameList;
    nameList << "鼠标进入/离开"
             << "鼠标按下/移动/释放"
             << "键盘事件"
             << "定时器事件"
             << "拖动事件"
             << "绘图事件"
             << "右键菜单"
             << "总结：事件的传递流程";

    btnGroup = new QButtonGroup(this);

    for (int i = 0; i < nameList.count(); i++) {
        QPushButton *btn = new QPushButton(this);

        btn->setText(QString("%1.%2").arg(i + 1, 2, 10, QChar('0')).arg(nameList.at(i)));
        btn->setMinimumHeight(60);
        btn->setCheckable(true);

        navWidget->setStyleSheet(R"(
            QPushButton {
                font-size: 20px;
                text-align: left;
            }
        )");

        // 将按钮添加到 btnGroup
        btnGroup->addButton(btn, i);

        navWidget->layout()->addWidget(btn);

        connect(btn, &QPushButton::clicked, this, &MainWidget::handleBtnClicked);

    }

    btnGroup->button(0)->click();
}

void MainWidget::initMain()
{
    pageEnterLeave = new PageEnterLeave();
    stackedWidget->addWidget(pageEnterLeave);

    pagePress = new PagePress();
    stackedWidget->addWidget(pagePress);

    // 键盘事件界面
    pageKeyEvent = new PageKeyEvent();
    stackedWidget->addWidget(pageKeyEvent);

    // 定时器事件界面
    pageTimerEvent = new PageTimerEvent();
    stackedWidget->addWidget(pageTimerEvent);

    // 拖放事件界面
    pageDragEvent = new PageDragEvent();
    stackedWidget->addWidget(pageDragEvent);
}
