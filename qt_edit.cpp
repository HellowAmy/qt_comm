#include "qt_edit.h"

qt_edit::qt_edit(QWidget *parent)
    : QLineEdit{parent}
{
    this->setFrame(false);//去边框
    this->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);//居中——水平+垂直

    //设置字体
    this->setFont(QFont("仿宋",16));

    //设置背景
    QPalette palette;
    palette.setColor(QPalette::Base,(QColor(0,0,0,0)));//全透明背景（需要自定义添加背景）
    this->setPalette(palette);//设置画板
}
