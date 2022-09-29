#ifndef WID_MANAGE_H
#define WID_MANAGE_H

#include <QWidget>

#include "wid_login.h"
#include "wid_friends_list.h"

class wid_manage : public QWidget
{
    Q_OBJECT
public:
    explicit wid_manage(QWidget *parent = nullptr);
    ~wid_manage();

signals:

protected:
    wid_login *v_login;
    wid_friends_list *v_friends_list;

};

#endif // WID_MANAGE_H
