#include "pagecontext.h"

PageContext::PageContext(QWidget *parent) : QWidget(parent)
{
    cut = new QAction("剪切(T)", this);
    copy = new QAction("复制(C)", this);
    paster = new QAction("粘贴(P)", this);
    toUpper = new QAction("转成大写(U)", this);
    toLower = new QAction("转成小写(L)", this);
    hide = new QAction("隐藏行");

    connect(cut, SIGNAL(triggered(bool)), this, SLOT(slotAction()));
    connect(copy, SIGNAL(triggered(bool)), this, SLOT(slotAction()));
    connect(paster, SIGNAL(triggered(bool)), this, SLOT(slotAction()));
    connect(toUpper, SIGNAL(triggered(bool)), this, SLOT(slotAction()));
    connect(toLower, SIGNAL(triggered(bool)), this, SLOT(slotAction()));
    connect(hide, SIGNAL(triggered(bool)), this, SLOT(slotAction()));

}

void PageContext::contextMenuEvent(QContextMenuEvent *event)
{
    // 显示菜单
    QMenu *menu = new QMenu();

    menu->setFixedWidth(160);

    menu->addAction(cut);
    menu->addAction(copy);
    menu->addAction(paster);
    menu->addAction(toUpper);
    menu->addAction(toLower);
    menu->addAction(hide);

    menu->exec(event->globalPos());

    delete menu;

}

void PageContext::slotAction()
{
    QAction *action  = qobject_cast<QAction*>(sender());    // QObject类的方法，返回发送该信号的对象

    qDebug() << action->text();
}
