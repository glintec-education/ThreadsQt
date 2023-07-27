#include "subclassqthread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subClassQThread w;
    w.show();
    return a.exec();
}
