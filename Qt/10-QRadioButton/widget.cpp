#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    btnGroupGender = new QButtonGroup(this);
    btnGroupGender->addButton(ui->rbMale4, 0);
    btnGroupGender->addButton(ui->rbFemale4, 1);

    btnGroupEdu = new QButtonGroup(this);
    btnGroupEdu->addButton(ui->rbDoctor4, 10);
    btnGroupEdu->addButton(ui->rbMaster4, 11);
    btnGroupEdu->addButton(ui->rbBachelor4, 12);
    btnGroupEdu->addButton(ui->rbOther4, 13);

    // 设置默认值
    ui->rbMale4->setChecked(true);
    ui->rbDoctor4->setChecked(true);

    connect(ui->rbMale4, &QPushButton::clicked, this, &Widget::btnClick);
    connect(ui->rbFemale4, &QPushButton::clicked, this, &Widget::btnClick);
    connect(ui->rbDoctor4, &QPushButton::clicked, this, &Widget::btnClick);
    connect(ui->rbMaster4, &QPushButton::clicked, this, &Widget::btnClick);
    connect(ui->rbBachelor4, &QPushButton::clicked, this, &Widget::btnClick);
    connect(ui->rbOther4, &QPushButton::clicked, this, &Widget::btnClick);

    ui->rbFemale4->setChecked(true);
    ui->rbDoctor4->setChecked(true);
    btnClick();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnGetSelection_clicked()
{
    QString str;

    // 性别
    if (ui->rbMale3->isChecked()) {
        str += ui->rbMale3->text();
    } else if (ui->rbFemale3->isChecked()) {
        str += ui->rbFemale3->text();
    }

    // 学历
    if (ui->rbDoctor3->isChecked()) {
        str += ui->rbDoctor3->text();
    } else if (ui->rbMaster3->isChecked()) {
        str += ui->rbMaster3->text();
    } else if (ui->rbBachelor3->isChecked()) {
        str += ui->rbBachelor3->text();
    } else if (ui->rbOther3->isChecked()) {
        str += ui->rbOther3->text();
    }

    // 显示到文本框
    ui->lineResult3->setText(str);
}

void Widget::btnClick()
{
    QString str;

    int checkedGenderId = btnGroupGender->checkedId();
    if (checkedGenderId == 0) {
        str += "男";
    } else if (checkedGenderId == 1) {
        str += "女";
    }

    int checkedEduId = btnGroupEdu->checkedId();
    if (checkedEduId == 10) {
        str += "博士";
    } else if (checkedEduId == 11) {
        str += "硕士";
    } else if (checkedEduId == 12) {
        str += "本科";
    } else if (checkedEduId == 13) {
        str += "其他";
    }


    ui->lineResult4->setText(str);
}


void Widget::on_rbMale4_toggled(bool checked)
{
    qDebug() << "checked:" << checked;
}

