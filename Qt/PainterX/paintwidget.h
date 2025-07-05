#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>

// 形状类型枚举，用于表示 QPainter 中支持绘制的各种图形元素
enum Shape {
    _Point,        // 点：绘制一个像素点，通常用于表示单个位置或标记

    _Line,         // 线段：绘制一条直线，常用于连接两个点、边界、辅助线等

    _Polyline,      //
    _Polygon,

    _Rect,         // 矩形：绘制一个普通矩形，可用于绘制边框、框体等
    _RoundeRect,   // 圆角矩形：类似矩形，但四个角带有圆角，常用于按钮、卡片背景等
    _Ellipse,      // 椭圆/圆：在指定矩形区域内绘制一个椭圆，若宽高相等则为圆

    _Arc,          // 弧线：绘制一个圆弧，不闭合，常用于仪表盘、进度指示等
    _Pie,          // 饼图扇形：从圆心开始绘制一个扇形区域，常用于饼状图
    _Chord,        // 弦形：连接弧线两端形成一个闭合区域，但不是扇形（没有圆心线）

    _Path,         // 路径：可以组合线条、曲线、弧线等形成复杂图形，适合绘制自由图形或复杂轮廓

    _Text,         // 文本：绘制一段文字，可指定字体、对齐方式、位置等，常用于标签、注释

    _Pixmap        // 图像：绘制一张位图（图片），支持格式如 PNG、JPG，可用作背景或图标
};


class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialias(bool antialias);
    void setTransformation(bool transformation);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    Shape mShape;

    QPen mPen;

    QBrush mBrush;

    bool mAntialias;
    bool mTransformation;

};

#endif // PAINTWIDGET_H
