#include "labelx.h"

LabelX::LabelX() {}

static int cnt = 1;

void LabelX::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    // qDebug() << "enterEvent:" << cnt++;
    this->setText(QString("EnterEvent: %1").arg(cnt++));
}

void LabelX::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    // qDebug() << "leaveEvent:" << cnt++;
    this->setText(QString("LeaveEvent: %1").arg(cnt++));
}
