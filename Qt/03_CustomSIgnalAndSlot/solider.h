#ifndef SOLIDER_H
#define SOLIDER_H

#include <QObject>
#include <QDebug>

class Solider : public QObject
{
    Q_OBJECT
public:
    explicit Solider(QObject *parent = nullptr);

signals:

public slots:
    void fight();
    void fight(QString str);

};

#endif // SOLIDER_H
