#include "pagepress.h"

PagePress::PagePress(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *lab = new QLabel(this);
    lab->setText("鼠标按下/移动/释放");
    lab->setFrameShape(QFrame::Box);
    lab->setFixedHeight(50);
    lab->setAlignment(Qt::AlignCenter);
    lab->setStyleSheet("background-color: skyblue; color: white; font-size: 24px");

    verticalLayout->addWidget(lab);
}
