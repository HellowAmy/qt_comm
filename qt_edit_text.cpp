#include "qt_edit_text.h"

qt_edit_text::qt_edit_text(QWidget *parent)
    : QTextEdit{parent}
{
    this->setFont(QFont("仿宋",16));//设置字体
    this->setFrameShape(QFrame::NoFrame);//无边框
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Base,QColor(0,0,0,0));//全透明背景（需要自定义添加背景）
    this->setPalette(palette);//设置画板

//    this->setFocusPolicy(Qt::StrongFocus);
}

void qt_edit_text::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == 16777220)//枚举失效--手动匹配:Qt::Key_Enter
    {
        emit fa_press_enter();
    }
    else QTextEdit::keyPressEvent(event);
}

