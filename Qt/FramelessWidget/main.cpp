#include "framelesswidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FramelessWidget w;
    w.show();
    return a.exec();
}
