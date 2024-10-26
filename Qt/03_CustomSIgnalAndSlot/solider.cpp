#include "solider.h"

Solider::Solider(QObject *parent)
    : QObject{parent}
{}

void Solider::fight()
{
    qDebug() << "fight";
}

void Solider::fight(QString str)
{
    qDebug() << "fight" << str;
}
