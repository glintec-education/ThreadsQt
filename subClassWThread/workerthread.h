#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread( QObject *parent = nullptr);
    ~WorkerThread();

signals:
    void currentCount(int value);

public slots:



    // QThread interface
protected:
    void run();
};

#endif // WORKERTHREAD_H
