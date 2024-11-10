#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
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
    void on_btnGetSelection_clicked();
    void btnClick();

    void on_rbMale4_toggled(bool checked);

private:
    Ui::Widget *ui;
    QButtonGroup *btnGroupGender;
    QButtonGroup *btnGroupEdu;
};
#endif // WIDGET_H
