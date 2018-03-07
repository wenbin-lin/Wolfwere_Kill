#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <vector>
#include <iostream>
#include <QThread>
#include <QScrollBar>

#include "mytimer.h"
#include "playeravatar.h"
#include "Client.h"
#include "character.h"
#include <basicinfo.h>
#include <gameinfo.h>
#include <gamethread.h>

class GameThread;
class GameInfo;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    startGame();//游戏开始
    sendMsg();//返回发言消息
    sendVoting();//返回投票信息
    endStatement();//结束发言按钮
    opChoice();//返回技能操作信息
    timeUp();//时间到
    receive(QString qstr);//接受client信息

signals:

private:

    enIdentity identity;    
    int id;   
    MyTimer* mytimer;
    QLabel* progressLabel;
    QLabel* publicLabel;
    QLabel* teamLabel;
    QLabel* playerLabel;
    QLabel* ipLabel;
    QLineEdit* publicText;
    QLineEdit* teamText;
    QLineEdit* ipText;
    QPushButton* publicSend;
    QPushButton* teamSend;
    QListWidget* progressList;
    QListWidget* publicList;
    QListWidget* teamList;
    QLabel* idLabel;
    QLabel* numLabel;
    QPushButton* start;
    QPushButton* endState;
    QPushButton* handOver;
    QPushButton* tearUp;
    QPushButton* shot;
    QPushButton* notShot;
    QPushButton* poison;
    QPushButton* anti;
    QPushButton* giveUp;
    PlayerAvatar* player1;
    PlayerAvatar* player2;
    PlayerAvatar* player3;
    PlayerAvatar* player4;
    PlayerAvatar* player5;
    PlayerAvatar* player6;
    PlayerAvatar* player7;
    PlayerAvatar* player8;
    QFont font1;
    QFont font2;
    GameInfo* gInfo;
    GameThread* gThread;
    CClient* client;

    QThread* test;

public:
    void addLine(int n,std::string str,msgType type,bool isNotice=false);//添加发言或消息，添加是否为系统提示的bool值显示不同效果
    void addLine(std::string str,msgType type=progressMsg);//重载addLine，发布游戏进程时无需添加发言者信息
    void addLine(QString qstr,msgType type=progressMsg);//为增强对中文显示的支持添加以QString为参数的重载方式
    void setButtons(enCommandList commandType, vector<bool> validTarget = {}, bool isPoisoned = true, bool isAntidote = true);//设置按键
    void die(int n);//设置编号为n的玩家死亡 采用代理模式通过MainWindow操作PlayeyAvatar
    void hideBadge(int n);//编号为n的玩家不为警长 代理模式
    void showBadge(int n);//显示编号为n的玩家为警长 代理模式
    void hideAll();//隐藏所有按钮，用于设置初始状态和死亡设置
    void stopState();
    void setId(int n);
    void setIdentity(enIdentity enid);
    void setgInfo(GameInfo* info){gInfo = info;}
    void resetGame();
    void showIdentity(vector<int> vecIdentity);

private:
    Ui::MainWindow *ui;

    friend class GameInfo;
};

#endif // MAINWINDOW_H
