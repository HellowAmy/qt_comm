#ifndef QT_BUTTON_H
#define QT_BUTTON_H

#include <QWidget>
#include <QPushButton>
//#include <QEnterEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QEvent>

class qt_button : public QPushButton
{
    Q_OBJECT
public:
    explicit qt_button(QWidget *parent = nullptr);
    void set_txt(QString txt);//设置文字内容
    void set_txt_color(QColor col);//设置文字颜色
    void set_pen(QPen pen);//设置画笔
    QString get_txt();//返回文字内容

signals:
    emit void fa_press();//点击信号

protected:
    int v_space=5;
    QString v_txt;
    QPen v_pen;
    QColor v_col;

    void paintEvent(QPaintEvent *) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *) override;
};

#endif // QT_BUTTON_H
