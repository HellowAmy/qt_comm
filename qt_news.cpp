#include "qt_news.h"

QString qt_news::get_info()
{
    return str_info;
}

qt_news::qt_news(QWidget *parent) : QWidget(parent)
{
    this->setMinimumHeight(v_mini);
    this->hide();//如果打开显示会有黑窗口闪屏

    wid_news = new QWidget(this);
    wid_news->move(0,v_begin);//v_space
    wid_news->show();

    v_font = QFont("微软雅黑",14);
}

QWidget *qt_news::init_news(QWidget *parent,bool self, QString time, QString type, QString content)
{
    is_self = self;
    str_news_time = time;
    str_info = to_info(type,self,str_news_time,content);
    wid_news->resize(parent->size());
    this->resize(parent->size());
    this->setParent(parent);
    this->show();
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
    //返回时间格式——(年-月-日 时:分:秒)
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    return time.toString("yyyy-MM-dd hh:mm:ss");
}

void qt_news::set_wid_high(QWidget *wid,int high)
{
    this->resize(this->width(),high + 45);
    wid->resize(wid->width(),high);
}

QString qt_news::to_info
        (QString type, bool self, QString time, QString content)
{
    QString str_self = "YES";
    if(self == false) str_self = "NO";

    return type + flg + str_self + flg+ time + flg + content;
}

void qt_news::draw_time(QPainter *show)
{
    //===== 绘制时间文本和线框 =====
    show->setPen(QPen(QColor(0xd79445),2));
    show->setFont(v_font);

    //坐标定点
    QPoint pos_up(0,v_space);
    QPoint pos_up_center(this->width()/2,v_space);
    QPoint pos_down(0,v_space+v_mini);
    QPoint pos_down_center(this->width()/2,v_space+v_mini);
    QRect rect_time(pos_up,pos_down_center);

    //右侧显示
    if(is_self)
    {
        pos_up = QPoint(this->width(),v_space);
        pos_down = QPoint(this->width(),v_space+v_mini);
        rect_time = QRect(pos_up_center,QSize(this->width()/2,v_mini));
    }

    //根据坐标画线
    QLine line_up(pos_up,pos_up_center);
    QLine line_down(pos_down,pos_down_center);

    //绘制三个线条和文本时间
    show->drawLine(line_up);
    show->drawLine(line_down);
    show->drawText(rect_time,Qt::AlignCenter,str_news_time);//文本时间
    //===== 绘制时间文本和线框 =====
}

qt_news_word::qt_news_word(QWidget *parent,QString word,bool self)
{
    //获取容器列表的控制权
    QWidget *wid_show = init_news(parent,self,get_time(),"WORD",word);

    //设置显示内容
    QLabel *lab = new QLabel(wid_show);
    lab->show();
    lab->setFrameShape(QFrame::Box);

    //对齐双方位置
    lab->resize(wid_show->width() / 2 ,v_mini);
    if(self) lab->move(wid_show->width() - lab->width(),0);

    //计算文字长度
    QString word_new;
    int count = line_wrap_max(word,word_new,lab->width()-10);

    //不同角色的显示对齐
    if(self == false)
    { lab->setAlignment(Qt::AlignLeft|Qt::AlignVCenter); }
    else
    {
        if(count > 1) lab->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        else lab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }

    //重设界面大小匹配文字(承载界面比显示控件大,需要同时设置才能正常显示)
    set_wid_high(lab,count * v_mini);

    //修改字体颜色
    QPalette pe;
    if(self) pe.setColor(QPalette::WindowText,0xe96366);
    else pe.setColor(QPalette::WindowText,0x95d59f);
    lab->setPalette(pe);
    lab->setFont(v_font);
    lab->setText(word_new);

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




#include <QPushButton>

qt_news_pic::qt_news_pic(QWidget *parent, const QPixmap &pix, QString path, bool self)
{
    if(pix.isNull()) return;

    //获取容器列表的控制权
    QWidget *wid_show = init_news(parent,self,get_time(),"SPIC",path);

    //设置缩放,限制到最合适的最大宽高比
    QPixmap temp = pix.scaled(parent->width()/2+parent->width()/4,350,Qt::KeepAspectRatio);

    //显示图片
    QLabel *lab_pic = new QLabel(wid_show);
    lab_pic->show();
    lab_pic->setPixmap(temp);
    if(self) lab_pic->move(wid_show->width()-temp.width(),0);

    //设置显示窗口大小
    lab_pic->resize(temp.width(),temp.height());
    wid_show->resize(wid_show->width(),temp.height());
    set_wid_high(lab_pic,temp.height());
}

qt_news_file::qt_news_file(QWidget *parent, QString filename, bool self)
{
    //获取容器列表的控制权
    QWidget *wid_show = init_news(parent,self,get_time(),"FILE",filename);
    is_self = self;
    v_filename = filename;

    //显示图片
    lab_box = new QLabel(wid_show);
    lab_box->show();
    lab_box->resize(wid_show->width(),40);
    lab_box->setAlignment(Qt::AlignCenter);
    lab_box->setFont(QFont("",14));

    //进度条
    v_prog = new QProgressBar(wid_show);
    v_prog->setValue(0);
    v_prog->resize(wid_show->width(),20);
    v_prog->setRange(0,100);
    v_prog->move(lab_box->pos()+QPoint(0,lab_box->height()-10));
    v_prog->show();

    //区分不同发送者
    if(self)
    {
        lab_box->setAlignment(Qt::AlignRight);
        lab_box->setText("<<< <<< [ "+v_filename+" ] [ "+v_status+" ]");
    }
    else
    {
        lab_box->setAlignment(Qt::AlignLeft);
        lab_box->setText("[ "+v_status+" ][ "+v_filename+" ] >>> >>>");
    }
    set_wid_high(lab_box,40*2+10);
}

void qt_news_file::set_status(QString status,int prog)
{
    if(is_self) lab_box->setText("<<< <<< [ "+v_filename+" ] [ "+status+" ]");
    else lab_box->setText("[ "+status+" ][ "+v_filename+" ] >>> >>>");
    v_prog->setValue(prog);
}
