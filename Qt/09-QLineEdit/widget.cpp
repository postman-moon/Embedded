#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnEchoNormal_clicked()
{
    ui->lineEcho->clear();
    ui->lineEcho->setEchoMode(QLineEdit::Normal);
    ui->lineEcho->setPlaceholderText("Normal");
}


void Widget::on_btnEchoPassword_clicked()
{
    ui->lineEcho->clear();
    ui->lineEcho->setEchoMode(QLineEdit::Password);
    ui->lineEcho->setPlaceholderText("Password");
}


void Widget::on_btnEchoNo_clicked()
{
    ui->lineEcho->clear();
    ui->lineEcho->setEchoMode(QLineEdit::NoEcho);
    ui->lineEcho->setPlaceholderText("NoEcho");
}


void Widget::on_btnEchoPasswordEchoOnEdit_clicked()
{
    ui->lineEcho->clear();
    ui->lineEcho->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->lineEcho->setPlaceholderText("PasswordEchoOnEdit");
}


void Widget::on_btnEchoPrint_clicked()
{
    QMessageBox::information(this, "回显模式", ui->lineEcho->text());
}


void Widget::on_btnAlignLeft_clicked()
{
    ui->lineAlign->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}


void Widget::on_btnAlignCenter_clicked()
{
    ui->lineAlign->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
}


void Widget::on_btnAlignRight_clicked()
{
    ui->lineAlign->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}


void Widget::on_btnAccessReadWrite_clicked()
{
    ui->lineAccess->setReadOnly(false);
    ui->lineAccess->setPlaceholderText("ReadWrite");
}


void Widget::on_btnAccessReadOnly_clicked()
{
    ui->lineAccess->setReadOnly(true);
    ui->lineAccess->setPlaceholderText("ReadOnly");
}


void Widget::on_btnAccessDisabled_clicked()
{
    ui->lineAccess->setEnabled(false);
    ui->lineAccess->setPlaceholderText("Disabled");
}


void Widget::on_btnAccessEnabled_clicked()
{
    ui->lineAccess->setEnabled(true);
    ui->lineAccess->setPlaceholderText("Enabled");
}


void Widget::on_btnMaskNone_clicked()
{
    ui->lineMask->setInputMask("");
}


void Widget::on_btnMaskPhone_clicked()
{
    // 9 - 表示要求输入0-9的数字
    // ; - 表示格式字符串结束
    // # - 表示无输入时，显示的字符占位字符
    ui->lineMask->setInputMask("99999999999;#");
}


void Widget::on_btnMaskLicense_clicked()
{
    // > - 转换为大写
    // A - 代表要求输入英文字母
    // ; - 表示格式字符串结束
    // # - 表示无输入时，显示的字符占位字符
    ui->lineMask->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
}




void Widget::on_lineAdd1_textChanged(const QString &arg1)
{
    int sum = arg1.toInt() + ui->lineAdd2->text().toInt();
    ui->lineSum->setText(QString::number(sum));
}


void Widget::on_lineAdd2_textChanged(const QString &arg1)
{
    int sum = arg1.toInt() + ui->lineAdd1->text().toInt();
    ui->lineSum->setText(QString::number(sum));
}



void Widget::on_lineSub1_editingFinished()
{
    int result = ui->lineSub1->text().toInt() - ui->lineSub2->text().toInt();
    ui->lineResult->setText(QString::number(result));
}


void Widget::on_lineSub2_editingFinished()
{
    int result = ui->lineSub1->text().toInt() - ui->lineSub2->text().toInt();
    ui->lineResult->setText(QString::number(result));
}

