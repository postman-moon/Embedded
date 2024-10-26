#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. SIGNAL/SLOT(Qt4)
    connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));

    // 2. 函数地址（Qt5）
    connect(ui->btnNormal, &QPushButton::clicked, this, &QMainWindow::showNormal);

    // 5.lambda 表达式
    connect(ui->btnUpdate, &QPushButton::clicked, this, [this]() {
        this->setWindowTitle("[连接信号槽的 5 中方式]");
    });

#if 0
    // 3.1 匿名函数的定义
    []() {
        qDebug() << "lambda...";
    };
#endif

#if 0
    // 3.2 匿名函数的调用
    []() {
        qDebug() << "lambda...";
    }();
#endif

    int a = 10;

#if 0
    // 3.3 不捕获任何变量
    []() {
        qDebug() << a;
    }();
#endif

#if 0
    // 3.4 按引用捕获任何变量
    [&]() {
        qDebug() << a++;    // 10
    }();
    qDebug() << a;          // 11
#endif

#if 0
    // 3.5 按值捕获任何变量
    [=]() {
        qDebug() << a++;    // 10
    }();
    qDebug() << a;          // 11
#endif

#if 0
    // 3.6 按值捕获任何变量 + mutable
    [=]() mutable {
        qDebug() << a++;    // 10
    }();
    qDebug() << a;          // 10
#endif

#if 0
    // 3.7 参数
    [=](int x, int y) {
        qDebug() << x + y;  // 3
    }(1, 2);
#endif

#if 0
    // 3.8 返回值
    int sum = [](int x, int y) -> int {
        return x + y;
    }(1, 2);

    qDebug() << "sum:" << sum;
#endif

#if 0
    int sum = [](int x, int y) {
        return x + y;
    }(1, 2);

    qDebug() << "sum:" << sum;
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMin_clicked()
{
    this->showMinimized();
}

