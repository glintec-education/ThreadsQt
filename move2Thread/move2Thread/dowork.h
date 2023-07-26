#ifndef DOWORK_H
#define DOWORK_H

#include <QObject>

class DoWork : public QObject
{

    Q_OBJECT
public:
    DoWork();
    ~DoWork();


signals:
    void currentCount(int value); //enviada por la interfaz
    void countDone(); //termina la cuenta

public slots:
    void doCounting();
};

#endif // DOWORK_H
