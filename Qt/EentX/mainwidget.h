#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

#include "pageenterleave.h"
#include "pagepress.h"
#include "pagekeyevent.h"
#include "pagetimerevent.h"
#include "pagedragevent.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void handleBtnClicked();

private:
    QWidget *navWidget;
    QWidget *mainWidget;
    QStackedWidget *stackedWidget;
    QButtonGroup *btnGroup;

    PageEnterLeave *pageEnterLeave;
    PagePress *pagePress;
    PageKeyEvent *pageKeyEvent;
    PageTimerEvent *pageTimerEvent;
    PageDragEvent *pageDragEvent;

    void initNav();
    void initMain();
};
#endif // MAINWIDGET_H
