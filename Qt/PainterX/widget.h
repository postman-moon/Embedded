#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColorDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void shapeChanged();
    void penChanged();
    void onBtnPenColorClicked();
    void brushChanged();
    void onBtnBrushColorClicked();
    void antialiasChanged();
    void transformationChanged();

private:
    void initUI();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
