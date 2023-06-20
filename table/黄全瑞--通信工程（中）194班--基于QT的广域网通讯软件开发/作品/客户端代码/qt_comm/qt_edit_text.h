#ifndef QT_EDIT_TEXT_H
#define QT_EDIT_TEXT_H

#include <QWidget>
#include <QTextEdit>
#include <QPainter>
#include <QKeyEvent>


//!
//! 功能:提高一个QTextEdit相识的同风格控件类
//!
class qt_edit_text : public QTextEdit
{
    Q_OBJECT
public:
    explicit qt_edit_text(QWidget *parent = nullptr);

signals:   
    emit void fa_press_enter();

protected:
    void keyPressEvent(QKeyEvent *event) override;


};

#endif // QT_EDIT_TEXT_H
