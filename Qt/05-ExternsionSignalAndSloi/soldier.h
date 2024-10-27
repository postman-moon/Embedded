#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>
#include <QDebug>

class Soldier : public QObject
{
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);

signals:

public slots:
    void fight();
    void fight(QString str);

    void escape();
};

#endif // SOLDIER_H
