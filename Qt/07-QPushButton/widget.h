#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnStart_clicked();

    void on_btnConnect_clicked();

    void on_btnSignal_clicked();

    void on_btnSignal_pressed();

    void on_btnSignal_released();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H