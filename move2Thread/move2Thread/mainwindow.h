#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BtnStart_clicked();

    void on_BtnInfo_clicked();

    void countDone();
    void currentCount(int value);
    void threadFinish();  //when the thread is finished

private:
    Ui::MainWindow *ui;
    QThread *doWorkThread;
};
#endif // MAINWINDOW_H
