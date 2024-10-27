#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0
    // 1. Qt4 信号槽的连接：SIGNAL/SLOT
    Commander commander;
    Soldier solider;

    connect(&commander, SIGNAL(go()), &solider, SLOT(fight()));
    connect(&commander, SIGNAL(go(QString)), &solider, SLOT(fight(QString)));

    emit commander.go();
    emit commander.go("freedom");
#endif

#if 0
    // 2. Qt5 信号槽的连接： 函数地址
    Commander commander;
    Soldier soldier;

    // 没有同名的信号和槽时，可以直接这样写。因为不存在二义性
    // connect(&commander, &Commander::go, &soldier, &Soldier::fight);

    // 有同名的信号和槽时，需要像下面这样定义函数指针。因为存在二义性
    // 编译器自动推断，将无参的信号go和无参的槽，赋值给函数指针（ctrl+鼠标点击可以智能跳转过去）
    void (Commander::*pGo)() = &Commander::go;
    void (Soldier::*pFight)() = &Soldier::fight;

    connect(&commander, pGo, &soldier, pFight);

    // 编译器自动推断，将有参的信号go和有参的槽，赋值给函数指针（ctrl+鼠标点击可以智能跳转过去）
    void (Commander::*pGoForFreedom)(QString) = &Commander::go;
    void (Soldier::*pFightForFreedom)(QString) = &Soldier::fight;

    connect(&commander, pGoForFreedom, &soldier, pFightForFreedom);

    emit commander.go();
    emit commander.go("freedom");
#endif

#if 0
    // 3. 一个信号连接多个槽函数
    Commander commander;
    Soldier soldier1;
    Soldier soldier2;

    connect(&commander, SIGNAL(go()), &soldier1, SLOT(fight()));
    connect(&commander, SIGNAL(go()), &soldier2, SLOT(escape()));

    emit commander.go();
#endif

#if 0
    // 4. 多个信号连接一个槽函数
    Commander commander;
    Soldier soldier;

    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(move()), &soldier, SLOT(fight()));

    emit commander.go();
    emit commander.move();
#endif

#if 0
    // 5. 信号连接信号
    commander = new Commander();
    soldier = new Soldier();

    connect(ui->btnAction, &QPushButton::clicked, commander, &Commander::move);
    connect(commander, SIGNAL(move()), soldier, SLOT(fight()));
#endif


    // 6. 断开信号和槽的连接
    Commander commander;
    Soldier soldier;

    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(go(QString)), &soldier, SLOT(fight(QString)));

    emit commander.go();
    commander.disconnect();
    emit commander.go("freedom");

}

MainWindow::~MainWindow()
{
    delete ui;
}
