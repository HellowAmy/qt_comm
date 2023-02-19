#include "lab_tips.h"

lab_tips::lab_tips(QWidget *parent,const QColor &col) : QLabel(parent)
{
    QPalette palette;
    palette.setColor(QPalette::WindowText,col);
    this->setFont(QFont("微软雅黑",14));
    this->setText("提示");
    this->setFrameShape(QFrame::StyledPanel);
    this->setAlignment(Qt::AlignCenter);
    this->setPalette(palette);
}

void lab_tips::open_copy()
{  this->setTextInteractionFlags(Qt::TextSelectableByMouse); }
