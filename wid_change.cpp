#include "wid_change.h"

wid_change::wid_change(QWidget *parent)
    : QWidget{parent}
{

}

void wid_change::open_translucent(double min, double max)
{
    v_max=max;
    v_min=min;
    is_open_glass=true;
}

void wid_change::open_lessframe()
{
    this->setWindowFlag(Qt::FramelessWindowHint);//无边框
    is_open_lessframe=true;
}

void wid_change::open_round(QPoint rounded, QPen pen)
{
    this->setWindowFlag(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    pos_round=rounded;
    v_pen=pen;
    is_open_rounded=true;
}

void wid_change::open_backdrop(QString path)
{
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    pic_backdrop=path;
    is_open_backdrop=true;
}

void wid_change::mouseMoveEvent(QMouseEvent *e)
{
    //=====开启无边框移动=====
    if(is_open_lessframe)
    {
        //判断防止抖动和LeftButton点击
        if(e->buttons() == Qt::LeftButton && is_press)
        {
            is_press=true;
            this->move(e->pos()-pos_global+this->pos());
        }
    }
    //=====开启无边框移动=====

    QWidget::mouseMoveEvent(e);
}

void wid_change::mousePressEvent(QMouseEvent *event)
{
    //=====开启无边框移动=====
    if(is_open_lessframe)
    {
        is_press = true;//允许移动——防止抖动
        pos_global = event->pos();//记录点击位置
    }
    //=====开启无边框移动=====

    QWidget::mousePressEvent(event);
}

void wid_change::mouseReleaseEvent(QMouseEvent *e)
{
    //=====开启无边框移动=====
    if(is_open_lessframe) is_press = false;//禁止移动——防止抖动
    //=====开启无边框移动=====

    QWidget::mouseReleaseEvent(e);
}

void wid_change::enterEvent(QEvent *e)
{
    //=====开启半透明=====
    if(is_open_glass) this->setWindowOpacity(v_max);
    //=====开启半透明=====

    QWidget::enterEvent(e);
}

void wid_change::leaveEvent(QEvent *e)
{
    //=====开启半透明=====
    if(is_open_glass) this->setWindowOpacity(v_min);
    //=====开启半透明=====

    QWidget::leaveEvent(e);
}

void wid_change::paintEvent(QPaintEvent *)
{
    //=====开启圆角=====
    if(is_open_rounded)
    {
        QPainter *show=new QPainter(this);
        show->setRenderHint(QPainter::Antialiasing);//设置锯齿，不然边框会有明显抗锯齿
        show->setBrush(Qt::white);
        show->setPen(v_pen);
        show->drawRoundedRect(this->rect(),pos_round.x(),pos_round.y(),Qt::RelativeSize);
        show->end();
    }
    //=====开启圆角=====

    //=====开启背景图片=====
    if(is_open_backdrop)
    {
        QPainter *show=new QPainter(this);
        show->drawPixmap(0,0,QPixmap(pic_backdrop));
        show->end();
    }
    //=====开启背景图片=====
}
