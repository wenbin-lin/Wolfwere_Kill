#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include "Client.h"
#include "basicinfo.h"
#include "mainwindow.h"

class GameThread : public QThread
{
    Q_OBJECT
public:
    explicit GameThread(QObject *parent = 0);
    GameThread(CClient* cli, QObject* rec, QObject *parent = 0);
    void run();
    void endThread();

private:
    CClient* client;
    QObject* receiver;

signals:
    send(QString str);

public slots:
};

#endif // GAMETHREAD_H
