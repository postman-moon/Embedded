#ifndef PAGEDRAGEVENT_H
#define PAGEDRAGEVENT_H

#include <QWidget>
#include <QVBoxLayout>

#include "texteditx.h"

class PageDragEvent : public QWidget
{
    Q_OBJECT
public:
    explicit PageDragEvent(QWidget *parent = nullptr);

signals:
};

#endif // PAGEDRAGEVENT_H
