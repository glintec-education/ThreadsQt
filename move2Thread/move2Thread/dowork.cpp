#include "dowork.h"
#include <QVariant>
#include <QThread>
#include <QDebug>


DoWork::DoWork()
{
    qDebug()<< "DoWork constructor running in thread : " << QThread::currentThread();
}

DoWork::~DoWork()
{
    qDebug()<< "DoWork destroyed in thread : " << QThread::currentThread();

}

void DoWork::doCounting()
{
    qDebug()<< "DoWork counting method running in thread : " << QThread::currentThread();

    long int N = 1000000001;
    for(int i=0; i < N; i++)
    {
        double percentage = (i/(N*1.0)) * 100.0;
//        qDebug()<< "Percentage: " << percentage;
        if((i%10000) == 0)
        {
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }

    }

    emit countDone();
}
