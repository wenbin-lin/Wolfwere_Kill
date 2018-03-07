#include "mytimer.h"
#include "ui_mainwindow.h"

MyTimer::MyTimer(QWidget *parent) : QWidget(parent)
{
}

MyTimer::MyTimer(timerType type,QWidget *parent) : QWidget(parent)
{
    startTimer(1000);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MyTimer::timerUpdate);
    timer->start(1000);
    timeShow = new QLabel(parent);
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);
    timeShow->setPalette(palette);
    timeShow->setStyleSheet("background-color: rgb(0,0,0,0)");
    timeShow->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    QFont font;
    font.setBold(true);
    font.setPointSize(15);
    timeShow->setFont(font);
    timeShow->setGeometry(600,180,300,50);
    timeShow->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    timeShow->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    tType = type;
    resetTimer(type);
    connect(this,SIGNAL(timeOut()),this->parent(),SLOT(timeUp()));
}

MyTimer::~MyTimer()
{
    delete timeShow;
}

void MyTimer::timerUpdate()
{
    if(sec>0)
        sec--;
    if(sec==0)
    {
        timeShow->hide();
        timeOut();
        return;
    }
    QString str = QString::number(sec,10);
    timeShow->setText(timerName+str);
    timeShow->show();
}

void MyTimer::resetTimer(timerType type)
{
    disconnect(timer,&QTimer::timeout,this,&MyTimer::timerUpdate);
    connect(this,SIGNAL(timeOut()),this->parent(),SLOT(timeUp()));
    tType = type;
    switch (type) {
    case (statementTimer):
    {
        sec=60;
        timerName = tr("发言倒计时:");
        break;
    }
    case (votingTimer):
    {
        sec=15;
        timerName = tr("投票倒计时:");
        break;
    }
    case (wolfDiscussion):
    {
        sec=60;
        timerName = tr("狼人讨论倒计时：");
        break;
    }
    case (wolfVoting):
    {
        sec=15;
        timerName = tr("狼人投票倒计时：");
        break;
    }
    case (witchTimer):
    {
        sec=15;
        timerName = tr("女巫操作倒计时：");
        break;
    }
    case (prophetTimer):
    {
        sec=15;
        timerName = tr("预言家操作倒计时：");
        break;
    }
    case (badgeTimer):
    {
        sec=15;
        timerName = tr("警徽操作倒计时：");
        break;
    }
    case (noteTimer):
    {
        sec=60;
        timerName = tr("遗言倒计时：");
        break;
    }
    case (hunterTimer):
    {
        sec=15;
        timerName = tr("猎人操作倒计时：");
        break;
    }
    case(badgeVoting):
    {
        sec=15;
        timerName = tr("警长竞选投票倒计时：");
        break;
    }
    default:
        break;
    }
    connect(timer,&QTimer::timeout,this,&MyTimer::timerUpdate);
}

int MyTimer::getType()
{
    return tType;
}

void MyTimer::stop()
{
    disconnect(timer,&QTimer::timeout,this,&MyTimer::timerUpdate);
    disconnect(this,SIGNAL(timeOut()),this->parent(),SLOT(timeUp()));
    timeShow->hide();
}
