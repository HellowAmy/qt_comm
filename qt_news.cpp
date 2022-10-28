#include "qt_news.h"

qt_news::qt_news(QWidget *parent) : QWidget(parent)
{
    this->setMinimumHeight(v_mini);
    this->hide();//如果打开显示会有黑窗口闪屏

    wid_news = new QWidget(this);
    wid_news->move(v_space,v_begin);
    wid_news->show();

    v_font = QFont("微软雅黑",14);
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

QString qt_news::get_self_str(bool self)
{
    if(self) return "yes";
    else return "no";
}

QWidget *qt_news::get_news_wid()
{
    return wid_news;
}

void qt_news::paintEvent(QPaintEvent *)
{
    QPainter *show = new QPainter(this);
    this->draw_time(show);
    show->end();
}

QString qt_news::get_time()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

    //返回时间格式——(年-月-日 时:分:秒)
    return time.toString("yyyy-MM-dd hh:mm:ss");
}

QString qt_news::to_info
        (QString type, bool self, QString time, QString content)
{
    QString str_self = "YES";
    if(self == false) str_self = "NO";

    return flg + type + flg + str_self + flg+ time + flg + content + flg;
}

void qt_news::draw_time(QPainter *show)
{
    //===== 绘制时间文本和线框 =====
    show->setPen(QPen(QColor(0xd79445),2));
    show->setFont(v_font);

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

    this->set_self(self);
    this->set_news_time(this->get_time());

    //获取容器列表的控制权
    QWidget *wid_show = get_news_wid();
    wid_show->resize(this->size());

    //界面高度
    int high_lab = 30;
    int high_show = 40 + v_space;

    //设置显示内容
    QLabel *lab = new QLabel(wid_show);
    lab->show();

    //对齐双方位置
    lab->resize(this->width() / 2 ,high_lab);
    if(self) lab->move(lab->pos() + QPoint(120+20,0));

    //计算文字长度
    QString word_new;
    int count = line_wrap_max(word,word_new,345);

    //不同角色的显示对齐
    if(self == false)
    {
        lab->setAlignment
                (Qt::AlignLeft|Qt::AlignVCenter);
    }
    else
    {
        if(count > 1) lab->setAlignment
                (Qt::AlignLeft|Qt::AlignVCenter);
        else lab->setAlignment
                (Qt::AlignRight|Qt::AlignVCenter);
    }

    //重设界面大小匹配文字
    lab->resize(lab->width(),count * high_lab);
    this->resize(this->width(),high_show + count * high_lab);

    //修改字体颜色

    QPalette pe;
    if(self) pe.setColor(QPalette::WindowText,0xe96366);
    else pe.setColor(QPalette::WindowText,0x95d59f);
    lab->setPalette(pe);
    lab->setFont(v_font);

    lab->setText(word_new);
    QString str_self;

    //消息格式：##[类型]##[对方]##[时间]##[内容]##
    v_info = to_info(type,self,str_news_time,word);
}

QString qt_news_word::to_string_info()
{
    return v_info;
}

void qt_news_word::set_word(QString word)
{
    v_word = word;
}

int qt_news_word::size_calculate(QString word)
{
    //计算文字所需长度
    QFontMetrics font_s(v_font);
    return font_s.horizontalAdvance(word);
}

int qt_news_word::line_wrap_max
    (const QString &str_old,QString &str_new, int max)
{
    str_new = "";
    int count = 0;
    QString str_now = str_old;

    //对自身字符进行切割，直到小于最大值不能换行
    QFontMetrics font_s(v_font);
    for(int i=0;i<str_now.size();i++)
    {
        if(max < font_s.horizontalAdvance(str_now,i))
        {
            str_new += str_now.mid(0,i-1);
            str_new += "\n";
            str_now = str_now.mid(i-1);
            count++;
            i = 0;
        }
    }

    //如何剩余多余文字则进行收尾
    if(str_now.size() > 0)
    {
        count++;
        str_new += str_now;
    }

    return count;
}


