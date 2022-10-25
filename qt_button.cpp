#include "qt_button.h"

qt_button::qt_button(QWidget *parent)
    : QPushButton{parent}
{
    this->resize(100,50);
    this->setWindowFlag(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->setFont(QFont("华文彩云",12));

    v_pen.setColor(QColor(Qt::black));
}

void qt_button::set_txt(QString txt)
{
    v_txt=txt;
}

void qt_button::set_txt_color(QColor col)
{
    v_col=col;
}

void qt_button::set_pen(QPen pen)
{
    v_pen=pen;
}

QString qt_button::get_txt()
{
    return v_txt;
}

void qt_button::paintEvent(QPaintEvent *)
{
    QPainter *show=new QPainter(this);
    show->setPen(v_pen);
    show->setRenderHint(QPainter::Antialiasing);

    QRect rect(v_space,v_space,
               this->width()-v_space-1,this->height()-v_space-1);
    QRect rect2(v_space*2,v_space*2,
                this->width()-v_space*3-1,this->height()-v_space*3-1);

    //设置窗口圆角，百分比
    show->drawRoundedRect(rect,50,50,Qt::RelativeSize);
    show->drawRoundedRect(rect2,50,50,Qt::RelativeSize);

    //设置字体颜色
    if(v_col.isValid())
    {
        show->setPen(QPen(v_col));
        show->drawText(this->rect(),Qt::AlignCenter,v_txt);
        show->setPen(v_pen);
    }
    else show->drawText(this->rect(),Qt::AlignCenter,v_txt);

    show->end();
}

void qt_button::enterEvent(QEvent *event)
{
    v_pen.setColor(QColor(0xcb5959));
    this->update();

    QPushButton::enterEvent(event);
}

void qt_button::mouseReleaseEvent(QMouseEvent *event)
{
    v_pen.setColor(QColor(0xcb5959));
    this->update();

    QPushButton::mousePressEvent(event);
}

void qt_button::leaveEvent(QEvent *event)
{
    v_pen.setColor(QColor(Qt::black));
    this->update();

    QPushButton::leaveEvent(event);
}

void qt_button::mousePressEvent(QMouseEvent *event)
{
    v_pen.setColor(QColor(0xd5a0a0));
    this->update();
    emit fa_press();

    QPushButton::mousePressEvent(event);
}


