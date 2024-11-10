#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->cbApple, &QCheckBox::stateChanged, this, &Widget::onStateChange);
    connect(ui->cbBanana, &QCheckBox::stateChanged, this, &Widget::onStateChange);
    connect(ui->cbOrange, &QCheckBox::stateChanged, this, &Widget::onStateChange);
    connect(ui->cbPeach, &QCheckBox::stateChanged, this, &Widget::onStateChange);
    connect(ui->cbPear, &QCheckBox::stateChanged, this, &Widget::onStateChange);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onStateChange()
{
    QString str;

    bool appleChecked = ui->cbApple->isChecked();
    bool bananaChecked = ui->cbBanana->isChecked();
    bool orangeChecked = ui->cbOrange->isChecked();
    bool peachChecked = ui->cbPeach->isChecked();
    bool pearChecked = ui->cbPear->isChecked();

    if (appleChecked && bananaChecked && orangeChecked && peachChecked && pearChecked) {            // 全选
        ui->cbAll->setCheckState(Qt::Checked);
    } else if (!(appleChecked || bananaChecked || orangeChecked || peachChecked || pearChecked)) {  // 全部未选中
        ui->cbAll->setCheckState(Qt::Unchecked);
    } else {                                                                                        // 部分选中
        ui->cbAll->setCheckState(Qt::PartiallyChecked);
    }

    if (appleChecked) {
        str += ui->cbApple->text() += " ";
    }

    if (bananaChecked) {
        str += ui->cbBanana->text() += " ";
    }

    if (orangeChecked) {
        str += ui->cbOrange->text() += " ";
    }

    if (peachChecked) {
        str += ui->cbPeach->text() += " ";
    }

    if (pearChecked) {
        str += ui->cbPear->text() += " ";
    }

    ui->lineEdit->setText(str);

}

void Widget::on_cbAll_clicked()
{
    // 这里需要将“全选”按钮的三态设置为false
    // 也就是在鼠标点击时，只允许在checked和unchecked之间切换，不允许出现半选状态
    ui->cbAll->setTristate(false);

    Qt::CheckState state = ui->cbAll->checkState();

    if (state == Qt::Checked) {
        ui->cbApple->setChecked(true);
        ui->cbBanana->setChecked(true);
        ui->cbOrange->setChecked(true);
        ui->cbPeach->setChecked(true);
        ui->cbPear->setChecked(true);
    } else if(state == Qt::Unchecked) {
        ui->cbApple->setChecked(false);
        ui->cbBanana->setChecked(false);
        ui->cbOrange->setChecked(false);
        ui->cbPeach->setChecked(false);
        ui->cbPear->setChecked(false);
    }
}

