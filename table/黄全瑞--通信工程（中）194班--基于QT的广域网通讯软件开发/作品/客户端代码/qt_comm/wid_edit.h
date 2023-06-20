#ifndef WID_EDIT_H
#define WID_EDIT_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include <QLineEdit>
#include <QPalette>
#include <QLabel>

#include "qt_edit.h"

class wid_edit : public QWidget
{
    Q_OBJECT
public:
    explicit wid_edit(QWidget *parent = nullptr);

    void set_passwd(bool ok);//输入框密码模式
    void set_txt(QString txt);//设置文字
    void set_size(int size);//设置字体大小
    void set_txt_lab(QString txt);//设置提示文字
    QString get_txt();//获取文字

signals:

protected:
    void paintEvent(QPaintEvent *e) override;//重绘背景

    qt_edit *v_edie;
    QLabel *lab_txt;
    QPen v_pen;


    int v_size=1;
};

#endif // WID_EDIT_H
