#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 最大化显示
    connect(ui->btnMaxShow, SIGNAL(clicked()), this, SLOT(showMaximized()));
    // 正常显示
    connect(ui->btnNormalShow, SIGNAL(clicked()), this, SLOT(showNormal()));
    // 最小化显示
    connect(ui->btnMinShow, SIGNAL(clicked()), this, SLOT(showMinimized()));
    // 关闭窗口
    connect(ui->btnClose, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
