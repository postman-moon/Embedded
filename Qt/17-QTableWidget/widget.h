#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QButtonGroup>

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

    void addRowData(QString name, QString gender, int age, QString Province);
    void insertRowData(int row, QString name, QString gender, int age, QString province);

public slots:
    void handleSelectionRadioClicked();
    void handleItemClicked(QTableWidgetItem *item);

private slots:
    void on_btnStyleSheet_clicked();

private:
    Ui::Widget *ui;
    QButtonGroup *btnGroup;

};
#endif // WIDGET_H
