#ifndef LAB_TIPS_H
#define LAB_TIPS_H

#include <QWidget>
#include <QLabel>

//!
//! 功能:只是改变字体颜色,用法与QLabel一致
//!
class lab_tips : public QLabel
{
    Q_OBJECT
public:
    explicit lab_tips(QWidget *parent = nullptr,const QColor &col = Qt::darkYellow);
    void open_copy();
signals:

protected:

};

#endif // LAB_TIPS_H
