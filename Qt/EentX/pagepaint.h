#ifndef PAGEPAINT_H
#define PAGEPAINT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>
#include <QPainter>
#include <QPoint>
#include <QRandomGenerator>
#include <QDebug>

#define PADDING         50
#define INCREAMENT      8   // 温度曲线像素增量
#define POINT_RADIUS    4   // 曲线描点的大小
#define TEXT_OFFSET_X   12  // 温度文本相对于点的偏移
#define TEXT_OFFSET_Y   10  // 温度文本相对于点的偏移

class PagePaint : public QWidget
{
    Q_OBJECT
public:
    explicit PagePaint(QWidget *parent = nullptr);

signals:

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void paintHigh();
    void paintLow();

    void updateTemp();

private:
    QLabel *labHigh;    // 高温曲线
    QLabel *labLow;     // 低温曲线

    int mHighTemp[7] = {0};
    int mLowTemp[7] = {0};
};

#endif // PAGEPAINT_H
