#include "mywindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    // 1. QApplication 是 qt 框架提供的应用程序类
    // 作用： 负责Qt事件的处理，比如鼠标点击事件，键盘的输入事件
    QApplication a(argc, argv);

    // 2. 创建自己的窗口对象，并调用其show方法，将窗口显示出来
    MyWindow w;
    w.show();

    qDebug() << "参数个数：" << argc;
    qDebug() << "参数1：" << argv[0];
    qDebug() << "参数2：" << argv[1];
    qDebug() << "参数3：" << argv[2];

    // 3. 调用QApplication的exec方法，应用程序就阻塞在这里，就会进入事件循环的处理，直到应用程序退出（比如点击了窗口的右上角的关闭按钮）
    return a.exec();
}
