#ifndef PAGEPRESS_H
#define PAGEPRESS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>

class PagePress : public QWidget
{
    Q_OBJECT
public:
    explicit PagePress(QWidget *parent = nullptr);

signals:

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QWidget *widget;
    QLabel *lbl;
    QPoint pressPos;
    QPoint wdPos;
};

#endif // PAGEPRESS_H
