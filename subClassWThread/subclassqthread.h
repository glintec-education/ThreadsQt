#ifndef SUBCLASSQTHREAD_H
#define SUBCLASSQTHREAD_H

#include <QMainWindow>

#include "workerthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class subClassQThread; }
QT_END_NAMESPACE

class subClassQThread : public QMainWindow
{
    Q_OBJECT

public:
    subClassQThread(QWidget *parent = nullptr);
    ~subClassQThread();

private slots:    

    void on_btnInfo_clicked();

    void onCurrentCount(int value);

    void on_btnStart_clicked();

private:
    Ui::subClassQThread *ui;
    WorkerThread *hiloTrabajador;
};
#endif // SUBCLASSQTHREAD_H
