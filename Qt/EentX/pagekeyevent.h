#ifndef PAGEKEYEVENT_H
#define PAGEKEYEVENT_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QDebug>

class PageKeyEvent : public QWidget
{
    Q_OBJECT
public:
    explicit PageKeyEvent(QWidget *parent = nullptr);

signals:

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QLabel *labKey;
};

#endif // PAGEKEYEVENT_H
