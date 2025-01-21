#ifndef PAGEENTERLEAVE_H
#define PAGEENTERLEAVE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>

#include "labelx.h"

class PageEnterLeave : public QWidget
{
    Q_OBJECT
public:
    explicit PageEnterLeave(QWidget *parent = nullptr);

signals:

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QLabel *lab;
};

#endif // PAGEENTERLEAVE_H
