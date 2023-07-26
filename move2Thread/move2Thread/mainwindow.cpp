#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dowork.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "ManinWindow constructor running in GUI thread " << QThread::currentThread();
    qDebug() << "Current thread in ManinWindow constructor " << QThread::currentThread();
    doWorkThread = new QThread (this);

    connect(doWorkThread, &QThread::finished, this, &MainWindow::threadFinish);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BtnStart_clicked()
{
//    qDebug() << " ";
    DoWork *worker = new DoWork;  //living in main thread
    worker->moveToThread(doWorkThread);

    connect(doWorkThread, &QThread::started, worker, &DoWork::doCounting);
    connect(worker, &DoWork::currentCount, this, &MainWindow::currentCount);
    connect(worker, &DoWork::countDone, this, &MainWindow::countDone);
    connect(doWorkThread, &QThread::finished, worker, &DoWork::deleteLater);


    doWorkThread->start();
}

void MainWindow::on_BtnInfo_clicked()
{
    qDebug() << "Thread running: " << doWorkThread->isRunning();
}

void MainWindow::countDone()
{
    qDebug() << "Widget, count Done: " ;
    doWorkThread->exit();  //kill the loop explicitly
}

void MainWindow::currentCount(int value)
{
    ui->progressBar->setValue(value);
    ui->label->setText(QString::number(value));

}

void MainWindow::threadFinish()
{
    qDebug() << "Thread finished: " << thread();
    qDebug() << "Thread finished. Current thread: " << QThread::currentThread();
}
