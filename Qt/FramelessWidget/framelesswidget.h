#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPoint>

enum Location {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    CENTER,
};

class FramelessWidget : public QWidget
{
    Q_OBJECT

public:
    FramelessWidget(QWidget *parent = nullptr);
    ~FramelessWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool isLeftPressed;     // 鼠标左键是否按下
    QPoint mousePos;        // 记录鼠标按下的位置
    Location location;

};
#endif // FRAMELESSWIDGET_H
