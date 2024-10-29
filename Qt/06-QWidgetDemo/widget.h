#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QDebug>

#include "subwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnGetSize_clicked();

    void on_btnSetSize_clicked();

    void on_btnSetFixedSize_clicked();

    void on_btnSetMaxSize_clicked();

    void on_btnSetMinSize_clicked();

    void on_btnMove_clicked();

    void on_btnSetIcon_clicked();

    void on_btnSetTitle_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
