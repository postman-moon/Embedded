#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground, true);
}

void PaintWidget::setShape(Shape shape)
{
    mShape = shape;

    update();
}

void PaintWidget::setPen(const QPen &pen)
{
    mPen = pen;
    update();
}

void PaintWidget::setBrush(const QBrush &brush)
{
    mBrush = brush;

    update();
}

void PaintWidget::setAntialias(bool antialias)
{
    mAntialias = antialias;

    update();
}

void PaintWidget::setTransformation(bool transformation)
{
    mTransformation = transformation;

    update();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70),
    };

    // QRect(int left, int top, int width, int height)
    QRect rect(10, 20, 80, 60);

    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;

    QPainter painter(this);
    painter.setPen(mPen);
    painter.setBrush(mBrush);
    painter.setRenderHint(QPainter::Antialiasing, mAntialias);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(QPoint(80, 0), QPoint(50, 50), QPoint(80, 80));

    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            painter.translate(x, y);

            if (mTransformation) {
                painter.translate(50, 50);
                painter.rotate(90);
                painter.translate(-50, -50);
            }

            switch (mShape) {
                case _Point:
                    painter.drawPoints(points, 4);
                break;

                case _Line:
                    painter.drawLine(points[0], points[2]);
                break;

                case _Polyline:
                    painter.drawPolyline(points, 4);
                break;

                case _Polygon:
                    painter.drawPolygon(points, 4);
                break;

                // 矩形、圆角矩形
                case _Rect:
                    painter.drawRect(rect);
                break;

                case _RoundeRect:
                    painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
                break;

                // 椭圆、圆
                case _Ellipse:
                    // 椭圆，制定矩形的左上角以及宽高
                    // painter.drawEllipse(QPoint(50, 50), 40, 30);
                    // 指定中心点和rx、ry
                    // painter.drawEllipse(QPoint(50, 50), 40, 40);
                    // 直接制定矩形
                    // painter.drawEllipse(rect);
                    painter.drawEllipse(10, 20, 80, 60);
                    break;

                // 圆弧、饼图、弦图
                case _Arc:
                    painter.drawArc(rect, startAngle, spanAngle);
                    break;


                case _Pie:
                    painter.drawPie(rect, startAngle, spanAngle);
                    break;

                case _Chord:
                    painter.drawChord(rect, startAngle, spanAngle);
                    break;

                // 路径
                case _Path:
                    painter.drawPath(path);
                    break;

                case _Text:
                    painter.drawText(rect, Qt::AlignCenter, "B站\n明王讲Qt");
                    break;

                case _Pixmap:
                    painter.drawPixmap(10, 10, QPixmap(":/images/qt_logo.png"));
                    break;
            }

            painter.restore();
        }
    }


}
