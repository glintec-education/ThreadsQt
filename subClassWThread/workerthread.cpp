#include "workerthread.h"
#include <QDebug>
#include <QVariant>
WorkerThread::WorkerThread(QObject *parent) : QThread(parent)
{
    qDebug() << "Worker thread constructor " << QThread::currentThread();

}

WorkerThread::~WorkerThread()
{
    qDebug() << "Worker thread destructor" << QThread::currentThread();
}

void WorkerThread::run()
{
    qDebug() << "Run Method in thread: " << QThread::currentThread();
    for(int i=0; i < 1000000000; i++)
    {
        if((i%100000) == 0){
            double percentage = (i/1000000000.0)*100.0;
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }


    //for create an event loop bcs this way doesnt create an event loop
//    exec();
}
