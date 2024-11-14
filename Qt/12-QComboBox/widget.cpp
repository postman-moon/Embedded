#include "widget.h"
#include "ui_widget.h"

QStringList gdCityList = {"广州市", "深圳市", "珠海市", "东莞市"};
QStringList zjCityList = {"杭州市", "宁波市", "温州市", "绍兴市"};
QStringList sdCityList = {"济南市", "青岛市", "烟台市", "威海市"};
QStringList hbCityList = {"石家庄市", "保定市", "廊坊市", "衡水市"};
QStringList nmCityList = {"呼和浩特市", "包头市", "呼伦贝尔市", "赤峰市"};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 添加省份
    ui->cboProvince->addItem("广东省");
    ui->cboProvince->addItem("浙江省");
    ui->cboProvince->addItem("山东省");
    ui->cboProvince->addItem("河北省");
    ui->cboProvince->addItem("内蒙古自治区");

    // 为省份添加图标
    ui->cboProvince->setItemIcon(0, QIcon(":/images/shengdanwa.png"));
    ui->cboProvince->setItemIcon(1, QIcon(":/images/shengdanye.png"));
    ui->cboProvince->setItemIcon(2, QIcon(":/images/xiaxue.png"));
    ui->cboProvince->setItemIcon(3, QIcon(":/images/xing.png"));
    ui->cboProvince->setItemIcon(4, QIcon(":/images/xingxing.png"));

    ui->cboCity->addItems(gdCityList);
    ui->lineName->setText("张三");

    connect(ui->cboProvince, SIGNAL(currentIndexChanged(int)), this, SLOT(onCboProvinceChanged(int)));

    // 学校
    connect(ui->cboUniversity, SIGNAL(currentIndexChanged(int)), this, SLOT(handleChanged(int)));
    // 城市
    connect(ui->cboCity, SIGNAL(currentIndexChanged(int)), this, SLOT(handleChanged(int)));

    connect(ui->lineName, &QLineEdit::textChanged, this, &Widget::handleLineChange);

    QString name = ui->lineName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    ui->lineResult->setText(QString("%1毕业于%2,来自于%3%4").arg(name)
                                .arg(university)
                                .arg(province)
                                .arg(city));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onCboProvinceChanged(int index)
{
    ui->cboCity->clear();

    switch (index) {
        case 0:
            ui->cboCity->addItems(gdCityList);
            break;

        case 1:
            ui->cboCity->addItems(zjCityList);
            break;

        case 2:
            ui->cboCity->addItems(sdCityList);
            break;

        case 3:
            ui->cboCity->addItems(hbCityList);
            break;

        case 4:
            ui->cboCity->addItems(nmCityList);
            break;

        default:
            break;
    }

    QString name = ui->lineName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    ui->lineResult->setText(QString("%1毕业于%2,来自于%3%4").arg(name)
                           .arg(university)
                           .arg(province)
                           .arg(city));
}

void Widget::handleChanged(int index)
{
    QString name = ui->lineName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    ui->lineResult->setText(QString("%1毕业于%2,来自于%3%4").arg(name)
                               .arg(university)
                               .arg(province)
                               .arg(city));
}

void Widget::handleLineChange(QString str)
{
    QString name = ui->lineName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    ui->lineResult->setText(QString("%1毕业于%2,来自于%3%4").arg(name)
                                .arg(university)
                                .arg(province)
                                .arg(city));
}
