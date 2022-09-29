#include "wid_edit.h"

wid_edit::wid_edit(QWidget *parent)
    : QWidget{parent}
{
    this->resize(200,45);

    //设置输入框的间隔，数值越大间隔越小
    int space=10;
    v_edie = new qt_edit(this);
    v_edie->move(45 + this->width()/space,0);
    v_edie->resize(this->size() - QSize(this->width()/space,this->height()/space));
    v_edie->setText("123456");

    //提示
    lab_txt = new QLabel(this);
    lab_txt->move(0,0);
    lab_txt->setText("提示:");
    lab_txt->resize(45,45);

    v_pen.setWidth(v_size);
    v_pen.setColor(QColor(0xe0e0e0));

    //设置字体
    QFont font;
    font.setPointSize(14);
    font.setFamily("仿宋");
    this->setFont(font);

    //设置背景
    QPalette palette;
    palette.setColor(QPalette::Base,(QColor(0,0,0,0)));//全透明背景（需要自定义添加背景）
    this->setPalette(palette);//设置画板
}

void wid_edit::set_passwd(bool ok)
{
    if(ok) v_edie->setEchoMode(QLineEdit::Password);
    else v_edie->setEchoMode(QLineEdit::Normal);
}

void wid_edit::set_txt(QString txt)
{
    v_edie->setText(txt);
}

void wid_edit::set_size(int size)
{
    v_edie->setFont(QFont("仿宋",size));
}

void wid_edit::set_txt_lab(QString txt)
{
    lab_txt->setText(txt);
}

QString wid_edit::get_txt()
{
    return v_edie->text();
}

void wid_edit::paintEvent(QPaintEvent *)
{
    QPainter *show=new QPainter(this);
    show->setPen(v_pen);
    show->drawLine(0,this->height()-1,this->width(),this->height()-1);
    show->end();
}
