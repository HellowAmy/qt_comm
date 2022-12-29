#include "widget.h"
#include "wid_manage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 1
    wid_manage k;
#else
//    Widget w;
//    w.show();
#endif

    return a.exec();
}
