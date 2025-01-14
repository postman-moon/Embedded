#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 初始化列表
    // 1.1 添加 4 列
    ui->tableStudent->setColumnCount(4);

    QStringList horizontalLabels;
    horizontalLabels << "姓名" << "性别" << "年龄" << "籍贯";

    ui->tableStudent->setHorizontalHeaderLabels(horizontalLabels);

    // 1.2 设置列的宽度
    ui->tableStudent->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 1.3 添加几列初始化数据
    addRowData("李雷", "男", 12, "广东");
    addRowData("韩梅梅", "女", 11, "北京");
    addRowData("林涛", "男", 13, "上海");

    // 行表头
    if (ui->tableStudent->horizontalHeader()->isHidden()) {
        ui->checkHHeader->setChecked(false);
    } else {
        ui->checkHHeader->setChecked(true);
    }

    connect(ui->checkHHeader, &QCheckBox::stateChanged, this, [=](int state){
        if (state) {
            ui->tableStudent->horizontalHeader()->show();
        } else {
            ui->tableStudent->horizontalHeader()->hide();
        }
    });

    // 列表头
    if (ui->tableStudent->verticalHeader()->isHidden()) {
        ui->checkVHeader->setChecked(false);
    } else {
        ui->checkVHeader->setChecked(true);
    }

    connect(ui->checkVHeader, &QCheckBox::stateChanged, this, [=](int state) {
        if (state) {
            ui->tableStudent->verticalHeader()->show();
        } else {
            ui->tableStudent->verticalHeader()->hide();
        }
    });

    // 交替背景色
    if (ui->tableStudent->alternatingRowColors()) {
        ui->checkAltemate->setChecked(true);
    } else {
        ui->checkAltemate->setChecked(false);
    }

    connect(ui->checkAltemate, &QCheckBox::stateChanged, this, [=](int state) {
        if (state) {
            ui->tableStudent->setAlternatingRowColors(true);
        } else {
            ui->tableStudent->setAlternatingRowColors(false);
        }
    });

    // 单元格可编辑
    if (ui->tableStudent->editTriggers()) {
        ui->checkEditCell->setChecked(true);
    } else {
        ui->checkEditCell->setChecked(false);
    }

    connect(ui->checkEditCell, &QCheckBox::stateChanged, this, [=](int state) {
        if (state) {
            ui->tableStudent->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);
        } else {
            ui->tableStudent->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    });

    // 6.选择单元格/选择行
    int selectionBehavior = ui->tableStudent->selectionBehavior();
    if (selectionBehavior == QAbstractItemView::SelectItems) {
        ui->radioCell->setChecked(true);
    } else if (selectionBehavior == QAbstractItemView::SelectRows) {
        ui->radioRow->setChecked(true);
    }

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->radioCell, 0);
    btnGroup->addButton(ui->radioRow, 1);
    connect(ui->radioCell, &QPushButton::clicked, this, &Widget::handleSelectionRadioClicked);
    connect(ui->radioRow, &QPushButton::clicked, this, &Widget::handleSelectionRadioClicked);

    // 7. 点击单元格时，将数据显示到文本框
    connect(ui->tableStudent, &QTableWidget::itemClicked, this, &Widget::handleItemClicked);

    connect(ui->btnAdd, &QPushButton::clicked, this, [=]() {
        QString name = ui->lineName->text();
        int age = ui->lineAge->text().toInt();
        QString gender = ui->lineGender->text();
        QString province = ui->lineProvince->text();

        addRowData(name, gender, age, province);
    });

    connect(ui->btnInsert, &QPushButton::clicked, this, [=]() {
        QString name = ui->lineName->text();
        int age = ui->lineAge->text().toInt();
        QString gender = ui->lineGender->text();
        QString province = ui->lineProvince->text();

        int row = ui->tableStudent->currentRow();
        insertRowData(row, name, gender, age, province);
    });

    connect(ui->btnDel, &QPushButton::clicked, this, [=]() {
        int currentRow = ui->tableStudent->currentRow();
        ui->tableStudent->removeRow(currentRow);
    });

    connect(ui->btnUpdate, &QPushButton::clicked, this, [=]() {
        QString name = ui->lineName->text();
        QString age = ui->lineAge->text();
        QString gender = ui->lineGender->text();
        QString province = ui->lineProvince->text();

        int currentRow = ui->tableStudent->currentRow();

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        QTableWidgetItem *ageItem = new QTableWidgetItem(age);
        QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
        QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

        nameItem->setTextAlignment(Qt::AlignCenter);
        ageItem->setTextAlignment(Qt::AlignCenter);
        genderItem->setTextAlignment(Qt::AlignCenter);
        provinceItem->setTextAlignment(Qt::AlignCenter);

        ui->tableStudent->setItem(currentRow, 0, nameItem);
        ui->tableStudent->setItem(currentRow, 1, genderItem);
        ui->tableStudent->setItem(currentRow, 2, ageItem);
        ui->tableStudent->setItem(currentRow, 3, provinceItem);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::addRowData(QString name, QString gender, int age, QString province)
{
    // 获取当前行数
    int count = ui->tableStudent->rowCount();

    // 设置当前行数
    ui->tableStudent->setRowCount(count + 1);

    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    ui->tableStudent->setItem(count, 0, nameItem);
    ui->tableStudent->setItem(count, 1, genderItem);
    ui->tableStudent->setItem(count, 2, ageItem);
    ui->tableStudent->setItem(count, 3, provinceItem);
}

void Widget::insertRowData(int row, QString name, QString gender, int age, QString province)
{
    ui->tableStudent->insertRow(row);

    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(age);
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    ui->tableStudent->setItem(row, 0, nameItem);
    ui->tableStudent->setItem(row, 1, genderItem);
    ui->tableStudent->setItem(row, 2, ageItem);
    ui->tableStudent->setItem(row, 3, provinceItem);
}

void Widget::handleSelectionRadioClicked()
{
    int checkedId = btnGroup->checkedId();

    if (checkedId == 0) {
        ui->tableStudent->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableStudent->setSelectionBehavior(QAbstractItemView::SelectItems);
    } else if (checkedId == 1) {
        ui->tableStudent->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableStudent->setSelectionBehavior(QAbstractItemView::SelectRows) ;
    }
}

void Widget::handleItemClicked(QTableWidgetItem *item)
{
    int row = item->row();

    QString name = ui->tableStudent->item(row, 0)->text();
    QString gender = ui->tableStudent->item(row, 1)->text();
    QString age = ui->tableStudent->item(row, 2)->text();
    QString province = ui->tableStudent->item(row, 3)->text();

    ui->lineName->setText(name);
    ui->lineGender->setText(gender);
    ui->lineAge->setText(age);
    ui->lineProvince->setText(province);
}


void Widget::on_btnStyleSheet_clicked()
{
    QString cellStyle = R"(
        QTableView {
            text-align: center;
            background-color: rgba(255, 255, 255, 0);
            alternate-background-color: #e3edf9;
            font: 14px;
            color: #677483;
            gridline-color: #ccddf0;
        }
    )";

    QString horizontalHeaderStyle = R"(
        QHeaderView::section {
            color: black;
            font: bold 14px "微软雅黑";
            text-align: center;
            height: 32px;
            background-color: #d1dff0;
            border: 1px solid #8faac9;
            border-left: none;
        }
    )";

    QString verticalHeaderStyle = R"(
        QHeaderView::section {
            color: black;
            font: bold 14px "微软雅黑";
            width: 60px;
            text-align: center;
            background-color: #d1dff0;
            border: 1px solid #8faac9;
            border-left: none;
        }
    )";

    ui->tableStudent->setStyleSheet(cellStyle);
    ui->tableStudent->horizontalHeader()->setStyleSheet(horizontalHeaderStyle);
    ui->tableStudent->verticalHeader()->setStyleSheet(verticalHeaderStyle);
}

