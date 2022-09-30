#ifndef QT_EDIT_TEXT_H
#define QT_EDIT_TEXT_H

#include <QWidget>
#include <QTextEdit>
#include <QPainter>

class qt_edit_text : public QTextEdit
{
    Q_OBJECT
public:
    explicit qt_edit_text(QWidget *parent = nullptr);

signals:

};

#endif // QT_EDIT_TEXT_H
