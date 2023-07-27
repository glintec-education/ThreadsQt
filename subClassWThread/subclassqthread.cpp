#include "subclassqthread.h"
#include "ui_subclassqthread.h"
#include <QDebug>

subClassQThread::subClassQThread(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::subClassQThread)
{
    ui->setupUi(this);
    qDebug() << "Ui thtread; " << QThread::currentThread();

    hiloTrabajador = new WorkerThread(this);
    connect(hiloTrabajador, &WorkerThread::currentCount, this, &subClassQThread::onCurrentCount);

    connect(hiloTrabajador, &QThread::started, [](){
            qDebug() << "Thread started";
        });

    connect(hiloTrabajador, &QThread::finished, [](){
        qDebug() << "Thread finished";
    });
}

subClassQThread::~subClassQThread()
{
    delete ui;
}



void subClassQThread::on_btnInfo_clicked()
{
    qDebug() << "Thread is finished: " << hiloTrabajador->isRunning();
}

void subClassQThread::onCurrentCount(int value)
{
    ui->progressBar->setValue(value);
    ui->label->setText(QString::number(value));

}

void subClassQThread::on_btnStart_clicked()
{
    hiloTrabajador->start();
}
