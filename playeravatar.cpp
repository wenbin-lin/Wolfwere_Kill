#include "playeravatar.h"

PlayerAvatar::PlayerAvatar(QWidget *parent) : QWidget(parent)
{  
}

PlayerAvatar::PlayerAvatar(int n,QWidget *parent) : QWidget(parent)
{
    id = n;
    QString num = QString::number(id,10);
    QFont font1;
    QFont font2;
    font1.setBold(true);
    font2.setBold(true);
    font1.setPointSize(80);
    font2.setPointSize(20);
    player = new QLabel(parent);
    player->setObjectName("player");
    player->setPixmap(QPixmap(":/image/avatar.jpg"));
    player->setScaledContents(true);
    player->resize(150,150);
    player->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    player->move(30+((n+4)%4)*430,20+((n+1)/5)*720);
    voting = new QPushButton(this->player);
    voting->setStyleSheet("background-color: rgb(0,150,255)");
    voting->setText(tr("票"));
    voting->setFont(font2);
    voting->setGeometry(0,0,50,50);
    voting->hide();
    voting->setObjectName("V"+num);
    connect(voting,SIGNAL(clicked(bool)),parent,SLOT(sendVoting()));
    badge = new QLabel(this->player);
    badge->setText(tr("警"));
    badge->setGeometry(100,100,50,50);
    badge->setFont(font2);
    badge->setStyleSheet("background-color: rgb(255,150,0)");
    badge->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    badge->hide();
    number = new QLabel(this->player);
    number->setStyleSheet("background:yellow");
    number->setText(QString::number(id+1,10));
    number->setFont(font2);
    number->setGeometry(0,100,50,50);
    number->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

PlayerAvatar::~PlayerAvatar()
{
    delete player;
}

void PlayerAvatar::playerDie()
{
    voting->hide();
    badge->hide();
    dead = new QLabel(tr("死"),this->player);
    dead->setGeometry(0,0,50,50);
    dead->setStyleSheet("background:red");
    QFont font;
    font.setBold(true);
    font.setPixelSize(30);
    dead->setFont(font);
    dead->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    dead->show();
}

void PlayerAvatar::playerHideBadge()
{
    badge->hide();
}

void PlayerAvatar::playerShowBadge()
{
    badge->show();
}

void PlayerAvatar::playerShowIdentity(int n)
{
    switch (n) {
    case 0:
    {
        number->setText(tr("狼"));
        break;
    }
    case 1:
    {
        number->setText(tr("民"));
        break;
    }
    case 2:
    {
        number->setText(tr("预"));
        break;
    }
    case 3:
    {
        number->setText(tr("巫"));
        break;
    }
    case 4:
    {
        number->setText(tr("猎"));
        break;
    }
    default:
        break;
    }
}
