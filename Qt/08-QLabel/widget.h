#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QTime>
#include <QPixmap>

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
    void on_btnGetText_clicked();

    void on_btnSetText_clicked();

    void on_btnAlignLeft_clicked();

    void on_btnAlignCenter_clicked();

    void on_btnAlignRight_clicked();

    void on_btnDisableWrap_clicked();

    void on_btnEnableWrap_clicked();

    void on_btnToggleImage_clicked();

private:
    Ui::Widget *ui;

    int index = 0;
};
#endif // WIDGET_H
