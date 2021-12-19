#include "widget.h"
#include "principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal p;
    p.show();
    //Widget w;
    //w.show();

    return a.exec();
}
