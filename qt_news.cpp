#include "qt_news.h"

qt_news::qt_news(QWidget *parent) : QWidget(parent)
{
    this->setMinimumHeight(v_mini);
    this->show();

    wid_news = new QWidget(this);
    wid_news->move(v_space,v_begin);
    wid_news->show();
}

void qt_news::set_size(int wide, int high)
{
    this->resize(wide,high);
}

void qt_news::set_self(bool self)
{
    is_self = self;
}

void qt_news::set_news_time(QString time)
{
    str_news_time = time;
}

QWidget *qt_news::get_news_wid()
{
    return wid_news;
}

void qt_news::paintEvent(QPaintEvent *)
{
    QPainter *show = new QPainter(this);
    this->draw_time(show);
    show->drawRect(this->rect());//边框
    show->end();
}

QString qt_news::get_time()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

    //返回时间格式——(年-月-日 时:分:秒)
    return time.toString("yyyy-MM-dd hh:mm:ss");
}

void qt_news::draw_time(QPainter *show)
{
    //===== 绘制时间文本和线框 =====
    show->setPen(QPen(QColor(0x4c5765),2));
    show->setFont(QFont("微软雅黑",14));

    //设置线条标记点
    int off = this->width()/4;
    int down = v_space + v_mini;
    int left = v_space + off;
    int right = this->width() - v_space - off;
    QPoint pos_center(this->width()/2,down);//共用中心偏移点

    //左侧
    QPoint pos_org(left,v_space);
    QPoint pos_off_up(right,v_space);
    QPoint pos_down(left,down);
    QPoint pos_margin(this->width() - v_space,down);

    //右侧
    QPoint pos_org_re(this->width() - off,v_space);
    QPoint pos_off_up_re(off + v_space,v_space);
    QPoint pos_down_re(this->width() - off,down);
    QPoint pos_margin_re(v_space,down);

    //默认左侧显示
    QLine line_up(pos_org,pos_off_up);
    QLine line_vert(pos_org,pos_down);
    QLine line_down(pos_center,pos_margin);
    QRect rect(pos_org,pos_off_up + QPoint(0,v_mini));

    //右侧显示
    if(is_self == false)
    {
        line_up = QLine(pos_org_re,pos_off_up_re);
        line_vert = QLine(pos_org_re,pos_down_re);
        line_down = QLine(pos_center,pos_margin_re);
        rect = QRect(pos_org_re,pos_off_up_re + QPoint(0,v_mini));
    }

    //绘制三个线条和文本时间
    show->drawLine(line_up);
    show->drawLine(line_down);
    show->drawLine(line_vert);
    show->drawText(rect,Qt::AlignCenter,str_news_time);
    //===== 绘制时间文本和线框 =====
}

qt_news_word::qt_news_word(QWidget *parent)
{

}

qt_news_word::qt_news_word(QString word,bool self)
{
    v_word = word;
    this->setMaximumHeight(100);
//    this->resize(50,100);
    this->set_self(self);
    this->set_news_time(this->get_time());

    QWidget *wid_show = get_news_wid();
//    wid_show->hide();
    wid_show->resize(this->size());
    QLabel *lab = new QLabel(wid_show);
    lab->setText(word);
    lab->show();
}

QString qt_news_word::to_string_info()
{
    QString str;
    return str;
}

void qt_news_word::set_word(QString word)
{
    v_word = word;
}
