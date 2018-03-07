#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include <QTime>
#include <QPalette>
#include <basicinfo.h>

#include <iostream>

using namespace std;

class MyTimer : public QWidget
{
    Q_OBJECT

public:
    explicit MyTimer(QWidget *parent = 0);
    MyTimer(timerType type, QWidget *parent = 0);
     ~MyTimer();

public:
    void resetTimer(timerType type);
    int getType();
    void stop();

signals:
    timeOut();

private slots:
    void timerUpdate();

private:
    timerType tType;
    int sec;
    QString timerName;
    QString time;
    QLabel *timeShow;

protected:
    QTimer* timer;
};

#endif // MYTIMER_H
