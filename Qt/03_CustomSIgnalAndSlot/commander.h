#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>

// 1. 只有继承自 QObject 类
class Commander : public QObject
{
    // 2. 并且要添加这一个宏，才能正常使用Qt提供的信号槽机制
    Q_OBJECT
public:
    explicit Commander(QObject *parent = nullptr);

    // 3. 在 signals 下就可以添加自定义的信号
signals:
    void go();
    void go(QString);

};

#endif // COMMANDER_H
