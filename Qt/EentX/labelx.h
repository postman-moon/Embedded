#ifndef LABELX_H
#define LABELX_H

#include <QLabel>
#include <QDebug>

class LabelX : public QLabel
{
    Q_OBJECT
public:
    LabelX();

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

};

#endif // LABELX_H
