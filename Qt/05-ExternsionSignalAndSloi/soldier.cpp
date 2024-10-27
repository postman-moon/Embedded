#include "soldier.h"

Soldier::Soldier(QObject *parent)
    : QObject{parent}
{}

void Soldier::fight()
{
    qDebug() << "fight";
}

void Soldier::fight(QString str)
{
    qDebug() << "fight" << str;
}

void Soldier::escape()
{
    qDebug() << "escapse";
}
