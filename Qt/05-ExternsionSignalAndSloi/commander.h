#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>

class Commander : public QObject
{
    Q_OBJECT
public:
    explicit Commander(QObject *parent = nullptr);

signals:
    void go();
    void go(QString);

    void move();
};

#endif // COMMANDER_H
