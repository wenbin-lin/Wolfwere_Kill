#ifndef PLAYERAVATAR_H
#define PLAYERAVATAR_H

#include <QWidget>
#include <QtWidgets>
#include <QPalette>
#include <basicinfo.h>
#include <iostream>

using namespace std;

class PlayerAvatar : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerAvatar(QWidget *parent = 0);
    PlayerAvatar(int n,QWidget *parent = 0);
    ~PlayerAvatar();

public:
    void playerDie();
    void playerShowBadge();
    void playerHideBadge();
    void playerShowIdentity(int n);

public:
    QPushButton* voting;
    QLabel* player;
    QLabel* badge;
    QLabel* number;
    QLabel* dead;
    int id;

signals:

public slots:
};

#endif // PLAYERAVATAR_H
