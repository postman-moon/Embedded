#ifndef PAGECONTEXT_H
#define PAGECONTEXT_H

#include <QObject>
#include <QWidget>
#include <QContextMenuEvent>
#include <QAction>
#include <QDebug>
#include <QMenu>

class PageContext : public QWidget
{
    Q_OBJECT
public:
    explicit PageContext(QWidget *parent = nullptr);

signals:

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void slotAction();

private:
    QAction *cut;
    QAction *copy;
    QAction *paster;
    QAction *toUpper;
    QAction *toLower;
    QAction *hide;

};

#endif // PAGECONTEXT_H
