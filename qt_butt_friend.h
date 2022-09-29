#ifndef QT_BUTT_FRIEND_H
#define QT_BUTT_FRIEND_H

#include <QWidget>
#include <QPushButton>
#include <QEnterEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>

#include "qt_button.h"

class qt_butt_friend : public qt_button
{
    Q_OBJECT
public:
    explicit qt_butt_friend(QWidget *parent = nullptr);
    void set_back(QString pic);//设置背景图片

signals:

protected:

    QString pic_bake;
    void paintEvent(QPaintEvent *) override;

};

#endif // QT_BUTT_FRIEND_H
