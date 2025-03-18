#include "pagedragevent.h"

PageDragEvent::PageDragEvent(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(10, 10, 10, 10);

    // 添加一个自定义文本框
    TextEditX *textEditX = new TextEditX(this);
    textEditX->setPlaceholderText("支持文件拖放的方式，来打开文件");

    verticalLayout->addWidget(textEditX);
}
