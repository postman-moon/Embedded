#ifndef TEXTEDITX_H
#define TEXTEDITX_H

#include <QWidget>
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDebug>
#include <QMimeData>
#include <QApplication>

class TextEditX : public QTextEdit
{
    Q_OBJECT
public:
    explicit TextEditX(QWidget *parent = nullptr);

signals:

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dragLeaveEvent(QDragLeaveEvent *e);
    void dragMoveEvent(QDragMoveEvent *e);
    void dropEvent(QDropEvent *e);

    void wheelEvent(QWheelEvent *e) override;
};

#endif // TEXTEDITX_H
