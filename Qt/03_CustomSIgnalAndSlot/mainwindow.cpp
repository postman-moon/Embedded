#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Commander commander;
    Solider solider;

    connect(&commander, SIGNAL(go()), &solider, SLOT(fight()));
    connect(&commander, SIGNAL(go(QString)), &solider, SLOT(fight(QString)));

    emit commander.go();
    emit commander.go("freedom");

}

MainWindow::~MainWindow()
{
    delete ui;
}
