#include "texteditx.h"

TextEditX::TextEditX(QWidget *parent)
    : QTextEdit{parent}
{
    this->setAcceptDrops(true);
}

void TextEditX::dragEnterEvent(QDragEnterEvent *e)
{
    qDebug() << Q_FUNC_INFO;

    // 判断是正常的文件，表明用户可以在这个窗口部件上拖放对象。
    // 默认情况下,窗口部件是不接受拖动的。Qt会自动改变光标来向用户说明这个窗口部件是不是有效的放下点
    e->acceptProposedAction();
}

void TextEditX::dragLeaveEvent(QDragLeaveEvent *e)
{
    qDebug() << Q_FUNC_INFO;
}

void TextEditX::dragMoveEvent(QDragMoveEvent *e)
{
    qDebug() << Q_FUNC_INFO;
}

void TextEditX::dropEvent(QDropEvent *e)
{
    qDebug() << Q_FUNC_INFO;

    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;

    QString fileName = urls.first().toLocalFile();
    qDebug() << urls.first() << ":" << fileName;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        setPlainText(file.readAll());
    }
}

void TextEditX::wheelEvent(QWheelEvent *e)
{
    if (QApplication::keyboardModifiers() == Qt::ControlModifier) {
        if (e->delta() >0) {    // 放大
            this->zoomIn();
        } else {                // 缩小
            this->zoomOut();
        }
    } else {
        QTextEdit::wheelEvent(e);   // 调用父类的实现，否则无法实现文本的上下滚动
    }
}
