#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    iconPathList << ":/images/shengdanwa.png"
                 << ":/images/shengdanye.png"
                 << ":/images/xiaxue.png"
                 << ":/images/xing.png"
                 << ":/images/xingxing.png";

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->rbListMode, 0);
    btnGroup->addButton(ui->rbIconMode, 1);

    ui->rbListMode->setChecked(true);
    ui->lwProvince->setViewMode(QListView::ListMode);

    connect(ui->rbListMode, &QRadioButton::clicked, this, &Widget::handleMode);
    connect(ui->rbIconMode, &QRadioButton::clicked, this, &Widget::handleMode);

    connect(ui->lwProvince, &QListWidget::itemClicked, this, &Widget::handleClicked);
    connect(ui->lwProvince, &QListWidget::itemDoubleClicked, this, &Widget::handleDoubleClicked);

    connect(ui->btnAdd, &QPushButton::clicked, this, &Widget::handleAddClicked);
    connect(ui->btnInsert, &QPushButton::clicked, this, &Widget::handleInsertClicked);
    connect(ui->btnDel, &QPushButton::clicked, this, &Widget::handleDelClicked);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMode()
{
    int checkedId = btnGroup->checkedId();

    if (checkedId == 0) {
        ui->lwProvince->setViewMode(QListView::ListMode);
    } else {
        ui->lwProvince->setViewMode(QListView::IconMode);
    }

}

void Widget::handleClicked(QListWidgetItem *item)
{
    ui->lineEdit->setText(item->text());
}

void Widget::handleDoubleClicked(QListWidgetItem *item)
{
    item->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}

void Widget::handleAddClicked()
{
    int iconIndex = QRandomGenerator::global()->generate()%5;   // 产生5以内的随机数 0～4

    QIcon icon(iconPathList[iconIndex]);
    QString val = ui->lineEdit_2->text();

    QListWidgetItem *item = new QListWidgetItem(icon, val);

    ui->lwProvince->addItem(item);
}

void Widget::handleInsertClicked()
{
    int iconIndex = QRandomGenerator::global()->generate()%5;

    QIcon icon(iconPathList[iconIndex]);
    QString val = ui->lineEdit_2->text();

    QListWidgetItem *item = new QListWidgetItem(icon, val);
    int currentIndex = ui->lwProvince->currentRow();

    ui->lwProvince->insertItem(currentIndex, item);

}

void Widget::handleDelClicked()
{
#if 0
    QListWidgetItem *item = ui->lwProvince->currentItem();
    ui->lwProvince->removeItemWidget(item);
    delete item;
#endif

    int row = ui->lwProvince->currentRow();
    QListWidgetItem *item = ui->lwProvince->takeItem(row);
    delete item;
}

