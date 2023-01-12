#include "widget.h"
#include "wid_manage.h"
#include "lib/vts/vts.h"

#include <QApplication>

using vts::vlog;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vinit_c(vlog::e_info);

#if 1
    wid_manage k;
#else
//    Widget w;
//    w.show();
#endif

    return a.exec();
}
