#include "pagepaint.h"

PagePaint::PagePaint(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 创建高温曲线
    labHigh = new QLabel(this);
    labHigh->setText("");
    labHigh->setFrameShape(QFrame::Box);
    verticalLayout->addWidget(labHigh);

    // 创建低温曲线
    labLow = new QLabel(this);
    labLow->setText("");
    labLow->setFrameShape(QFrame::Box);
    verticalLayout->addWidget(labLow);

    updateTemp();

    // 安装事件过滤
    labHigh->installEventFilter(this);
    labLow->installEventFilter(this);
}

bool PagePaint::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Paint) {
        if (watched == labHigh) {
            paintHigh();
            qDebug() << "Paint labHigh";
        }

        if (watched == labLow) {
            paintLow();
            qDebug() << "Paint labLow";
        }
    } else if (event->type() == QEvent::MouseButtonPress) {
        updateTemp();
    }

    QWidget::eventFilter(watched, event);
}

void PagePaint::paintHigh()
{
    QPainter painter(labHigh);

    // 1. 计算 x 轴
    int paintX[7] = {0};
    for (int i = 0; i < 7; i++) {
        paintX[i] = labHigh->pos().x() + PADDING + (labHigh->width() - (PADDING * 2)) / 6 * i;
    }

    // 2. 计算 y 轴
    int tempSum = 0;
    int tempAverage;
    for (int i = 0; i < 7; i++) {
        tempSum += mHighTemp[i];
    }
    tempAverage = tempSum / 7;

    int paintY[7] = {0};
    int yCenter = labHigh->height() / 2;
    int increament = labHigh->height() / 20;
    for (int i = 0; i < 7; i++) {
        paintY[i] = yCenter - ((mHighTemp[i] - tempAverage) * increament);
    }

    // 3. 开始绘制
    QPen pen = painter.pen();
    pen.setWidth(2);
    pen.setColor(QColor(255, 0, 0));

    painter.setPen(pen);
    painter.setBrush(QColor(255, 0, 0));
    painter.setFont(QFont("Ubuntu", 14));


    // 3.1 绘制点、文本
    for (int i = 0; i < 7; i++) {
        painter.drawEllipse(QPoint(paintX[i], paintY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(paintX[i] - TEXT_OFFSET_X, paintY[i] - TEXT_OFFSET_Y), QString::number(mHighTemp[i]) + "℃");
    }

    // 3.2 绘制线
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            pen.setStyle(Qt::DotLine);  // 虚线
            painter.setPen(pen);
        } else {
            pen.setStyle(Qt::SolidLine);    // 实线
            painter.setPen(pen);
        }

        painter.drawLine(paintX[i], paintY[i], paintX[i + 1], paintY[i + 1]);
    }

}

void PagePaint::paintLow()
{
    QPainter painter(labLow);

    // 1. 计算 x 轴
    int paintX[7] = {0};
    for (int i = 0; i < 7; i++) {
        paintX[i] = labLow->pos().x() + PADDING + (labLow->width() - PADDING * 2) / 6 * i;
    }

    // 2. 计算 y 轴
    int tempSum = 0;
    int tempAverage;
    for (int i = 0; i < 7; i++) {
        tempSum += mLowTemp[i];
    }
    tempAverage = tempSum / 7;

    int paintY[7] = {0};
    int yCenter = labLow->height() / 2;
    int increament = labLow->height() / 20;
    for (int i = 0; i < 7; i++) {
        paintY[i] = yCenter - ((mLowTemp[i] - tempAverage) * increament);
    }

    // 3. 开始绘制
    QPen pen = painter.pen();
    pen.setWidth(2);
    pen.setColor(QColor(0, 0, 255));

    painter.setPen(pen);
    painter.setBrush(QColor(0, 0, 255));
    painter.setFont(QFont("Ubuntu", 14));

    // 3.1 绘制点、文本
    for (int i = 0; i < 7; i++) {
        painter.drawEllipse(QPoint(paintX[i], paintY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(paintX[i] - TEXT_OFFSET_X, paintY[i] - TEXT_OFFSET_Y), QString::number(mLowTemp[i]) + "℃");
    }

    // 3.2 绘制线
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
        } else {
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }

        painter.drawLine(paintX[i], paintY[i], paintX[i + 1], paintY[i + 1]);
    }
}

void PagePaint::updateTemp()
{
    for (int i = 0; i < 7; i++) {
        mHighTemp[i] = 20 + QRandomGenerator64::global()->generate() % 10;
        mLowTemp[i] = -5 + QRandomGenerator64::global()->generate() % 10;
    }

    labHigh->update();
    labLow->update();
}
