#ifndef PAGETIMEREVENT_H
#define PAGETIMEREVENT_H

#include <QWidget>
#include <QLabel>
#include <QTimerEvent>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#define USE_TIMER_EVENT

class PageTimerEvent : public QWidget
{
    Q_OBJECT
public:
    explicit PageTimerEvent(QWidget *parent = nullptr);

signals:

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void handleBtnClicked();
    void handleTimeOut();

private:
    QLabel *labRed;
    QLabel *labBlue;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnReset;

    QTimer *timerMove;

    int id1;
    int id2;
};

#endif // PAGETIMEREVENT_H
