#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    identity = villager;//for test
    id = 0;
    mytimer = new MyTimer(statementTimer,this);
    mytimer->stop();

    ui->setupUi(this);
    setMinimumSize(1500,900);
    setMaximumSize(1500,900);
    setWindowTitle("Werewolf_Kill");

    font1.setBold(true);//字体设置
    font1.setPointSize(15);
    font2.setBold(true);
    font2.setPointSize(12);

    progressLabel = new QLabel(this);//标识
    progressLabel->setText(tr("游戏进程"));
    progressLabel->setFont(font1);
    progressLabel->setStyleSheet("background:gray");

    publicLabel = new QLabel(this);
    publicLabel->setText(tr("公共频道"));
    publicLabel->setFont(font1);
    publicLabel->setStyleSheet("background:gray");

    teamLabel = new QLabel(this);
    teamLabel->setText(tr("团队频道"));
    teamLabel->setFont(font1);
    teamLabel->setStyleSheet("background:gray");

    publicText = new QLineEdit(this);//消息编辑框for public
    publicText->setFixedHeight(30);
    publicText->setStyleSheet("background-color: rgb(255,255,255,150)");
    publicText->setFont(font2);
    publicSend = new QPushButton(this);
    publicSend->setText(tr("发送"));
    publicSend->setFont(font1);
    publicSend->setStyleSheet("background:gray");
    publicSend->setFixedSize(50,30);

    teamText = new QLineEdit(this);//消息编辑框for team
    teamText->setFixedHeight(30);
    teamText->setStyleSheet("background-color: rgb(255,255,255,150)");
    teamText->setFont(font2);
    teamSend = new QPushButton(this);
    teamSend->setText(tr("发送"));
    teamSend->setFont(font1);
    teamSend->setStyleSheet("background:gray");
    teamSend->setFixedSize(50,30);

    progressList = new QListWidget(this);//游戏进程
    progressList->setStyleSheet("background-color: rgb(0,0,0,50)");

    publicList = new QListWidget(this);//公共频道
    publicList->setStyleSheet("background-color: rgb(0,0,0,50)");

    teamList = new QListWidget(this);//团队频道
    teamList->setStyleSheet("background-color: rgb(0,0,0,50)");

    playerLabel = new QLabel(this);//玩家信息
    playerLabel->setText(tr("游戏身份"));
    playerLabel->setFont(font1);
    playerLabel->setStyleSheet("background:gray");
    playerLabel->setFixedHeight(30);
    idLabel = new QLabel(this);
    setIdentity(identity);
    idLabel->setStyleSheet("background:yellow");
    idLabel->setFixedHeight(30);
    numLabel = new QLabel(this);
    setId(id);
    numLabel->setStyleSheet("background:yellow");
    numLabel->setFixedHeight(30);

    poison = new QPushButton(this);
    poison->setText(tr("毒"));
    poison->setFont(font1);
    poison->setStyleSheet("background:yellow");
    poison->setFixedSize(50,50);
    poison->hide();
    anti = new QPushButton(this);
    anti->setText(tr("救"));
    anti->setFont(font1);
    anti->setStyleSheet("background:yellow");
    anti->setFixedSize(50,50);
    anti->hide();
    giveUp = new QPushButton(this);
    giveUp->setText(tr("弃"));
    giveUp->setFont(font1);
    giveUp->setStyleSheet("background:yellow");
    giveUp->setFixedSize(50,50);
    giveUp->hide();

    shot = new QPushButton(this);
    shot->setText(tr("枪"));
    shot->setFont(font1);
    shot->setStyleSheet("background:yellow");
    shot->setFixedSize(50,50);
    shot->hide();
    notShot = new QPushButton(this);
    notShot->setText(tr("弃"));
    notShot->setFont(font1);
    notShot->setStyleSheet("background:yellow");
    notShot->setFixedSize(50,50);
    notShot->hide();
    handOver = new QPushButton(this);
    handOver->setText(tr("转"));
    handOver->setFont(font1);
    handOver->setStyleSheet("background:yellow");
    handOver->setFixedSize(50,50);
    handOver->hide();
    tearUp = new QPushButton(this);
    tearUp->setText(tr("撕"));
    tearUp->setFont(font1);
    tearUp->setStyleSheet("background:yellow");
    tearUp->setFixedSize(50,50);
    tearUp->hide();

    start = new QPushButton(this);
    start->setText(tr("开始游戏"));
    start->setFont(font1);
    start->setStyleSheet("background:gray");
    start->setFixedSize(110,30);
    connect(start,SIGNAL(clicked(bool)),this,SLOT(startGame()));

    ipText = new QLineEdit(this);//端口编辑框
    ipText->setFixedSize(180,30);
    ipText->setStyleSheet("background-color: rgb(255,255,255,150)");
    ipText->setFont(font2);
    ipText->setText(tr("59.66.135.45"));

    ipLabel = new QLabel(this);
    ipLabel->setText(tr("IP"));
    ipLabel->setFixedSize(30,30);
    ipLabel->setStyleSheet("background:gray");
    ipLabel->setFont(font1);

    endState = new QPushButton(this);
    endState->setText(tr("结束发言"));
    endState->setFont(font1);
    endState->setStyleSheet("background:gray");
    endState->setFixedSize(110,30);

    QWidget *widget = new QWidget(this);
    QGridLayout* mainLayout = new QGridLayout();//mainLayout

    QGridLayout* opLayout = new QGridLayout();//layout for operations
    opLayout->addWidget(playerLabel,0,0,1,3);
    opLayout->addWidget(idLabel,2,0,1,3);
    opLayout->addWidget(numLabel,1,0,1,3);
    opLayout->addWidget(shot,3,0);
    opLayout->addWidget(notShot,3,2);
    opLayout->addWidget(poison,3,0);
    opLayout->addWidget(anti,3,1);
    opLayout->addWidget(giveUp,3,2);
    opLayout->addWidget(handOver,3,0);
    opLayout->addWidget(tearUp,3,2);
    opLayout->addWidget(endState,4,1,1,2);
    opLayout->addWidget(start,4,1,1,2);
    opLayout->addWidget(ipText,3,0,1,2);
    opLayout->addWidget(ipLabel,3,2,1,1);
    opLayout->setSpacing(70);
    opLayout->setContentsMargins(0,0,0,0);
    opLayout->setRowStretch(0,1);
    opLayout->setRowStretch(1,1);
    opLayout->setRowStretch(2,1);
    opLayout->setRowStretch(3,1);
    opLayout->setRowStretch(4,1);
    opLayout->setColumnStretch(0,1);
    opLayout->setColumnStretch(1,1);
    opLayout->setColumnStretch(2,1);

    QGridLayout* msgLayout = new QGridLayout();//layout for msg
    msgLayout->addWidget(progressLabel,0,0);
    msgLayout->addWidget(publicLabel,0,1,1,2);
    msgLayout->addWidget(teamLabel,0,3,1,2);
    msgLayout->addWidget(progressList,1,0);
    msgLayout->addWidget(publicList,1,1,1,2);
    msgLayout->addWidget(teamList,1,3,1,2);
    msgLayout->addWidget(publicText,2,1);
    msgLayout->addWidget(publicSend,2,2);
    msgLayout->addWidget(teamText,2,3);
    msgLayout->addWidget(teamSend,2,4);
    msgLayout->addLayout(opLayout,0,5,3,1);
    msgLayout->setColumnStretch(0,12);
    msgLayout->setColumnStretch(1,19);
    msgLayout->setColumnStretch(2,1);
    msgLayout->setColumnStretch(3,11);
    msgLayout->setColumnStretch(4,1);
    msgLayout->setColumnStretch(5,12);
    msgLayout->setRowStretch(0,1);
    msgLayout->setRowStretch(1,30);
    msgLayout->setRowStretch(2,1);
    msgLayout->setSpacing(0);
    msgLayout->setContentsMargins(0,200,0,200);

    player1 = new PlayerAvatar(0,this);//玩家头像
    player2 = new PlayerAvatar(1,this);
    player3 = new PlayerAvatar(2,this);
    player4 = new PlayerAvatar(3,this);
    player5 = new PlayerAvatar(4,this);
    player6 = new PlayerAvatar(5,this);
    player7 = new PlayerAvatar(6,this);
    player8 = new PlayerAvatar(7,this);

    player1->setObjectName("player0");
    player2->setObjectName("player1");
    player3->setObjectName("player2");
    player4->setObjectName("player3");
    player5->setObjectName("player4");
    player6->setObjectName("player5");
    player7->setObjectName("player6");
    player8->setObjectName("player7");

    mainLayout->addLayout(msgLayout,0,0);
    mainLayout->setSpacing(0);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    publicSend->setObjectName("publicSend");//connect for lineedit and enter
    teamSend->setObjectName("teamSend");
    publicText->setObjectName("publicText");
    teamText->setObjectName("teamText");
    connect(publicSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
    connect(teamSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
    connect(publicText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
    connect(teamText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
    connect(endState,SIGNAL(clicked(bool)),this,SLOT(endStatement()));
    handOver->setObjectName("handOver");
    tearUp->setObjectName("tearUp");
    shot->setObjectName("shot");
    notShot->setObjectName("notShot");
    poison->setObjectName("poison");
    anti->setObjectName("anti");
    giveUp->setObjectName("giveUp");
    connect(handOver,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(tearUp,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(shot,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(notShot,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(poison,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(anti,SIGNAL(clicked(bool)),this,SLOT(opChoice()));
    connect(giveUp,SIGNAL(clicked(bool)),this,SLOT(opChoice()));

    stopState();//设置初始状态发言关闭
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::sendMsg()
{
    QString name = sender()->objectName();
    if(name=="publicSend"||name=="publicText")
    {
        QString qstr = this->publicText->text();
        string str=qstr2str(qstr);
        this->publicText->clear();
        gInfo->Feedback(CM_TALK,0,str);
    }
    else if(name=="teamSend"||name=="teamText")
    {
        QString qstr = this->teamText->text();
        string str=qstr2str(qstr);
        this->teamText->clear();
        gInfo->Feedback(CM_GROUP,0,str);
    }
}

MainWindow::sendVoting()
{
    QString name = sender()->objectName();
    QString num = name.mid(1,1);
    int n = num.toInt();
    mytimer->stop();
    switch(mytimer->getType())
    {
    case(wolfVoting):
    {
        gInfo->Feedback(CM_KILL,n);
        break;
    }
    case(badgeTimer):
    {
        gInfo->Feedback(CM_XOTHER,n);
        break;
    }
    case(votingTimer):
    {
        gInfo->Feedback(CM_EXILE,n);
        break;
    }
    case(prophetTimer):
    {
        gInfo->Feedback(CM_INDICATE,n);
        break;
    }
    case(witchTimer):
    {
        gInfo->Feedback(CM_WITCH,n,"",UsePoison);
        break;
    }
    case(hunterTimer):
    {
        gInfo->Feedback(CM_HUNTER,n);
        break;
    }
    case(badgeVoting):
    {
        gInfo->Feedback(CM_BADGE,n);
    }
    default:
        break;
    }
    hideAll();
}

MainWindow::timeUp()
{
    mytimer->stop();
    switch(mytimer->getType())
    {
    case(votingTimer):
    {
        gInfo->Feedback(CM_EXILE,REFUZE);
        break;
    }
    case(statementTimer):
    {
        gInfo->Feedback(CM_TALK,REFUZE);
        stopState();
        break;
    }
    case(wolfDiscussion):
    {
        gInfo->Feedback(CM_GROUP,REFUZE);
        stopState();
        break;
    }
    case(wolfVoting):
    {
        gInfo->Feedback(CM_KILL,REFUZE);
        break;
    }
    case(witchTimer):
    {
        gInfo->Feedback(CM_WITCH,REFUZE);
        break;
    }
    case(prophetTimer):
    {
        gInfo->Feedback(CM_INDICATE,REFUZE);
        break;
    }
    case(badgeTimer):
    {
        gInfo->Feedback(CM_BADGE,REFUZE);
        break;
    }
    case(noteTimer):
    {
        gInfo->Feedback(CM_NOTE,REFUZE);
        stopState();
        break;
    }
    case(hunterTimer):
    {
        gInfo->Feedback(CM_HUNTER,REFUZE);
        break;
    }
    case(badgeVoting):
    {
        gInfo->Feedback(CM_BADGE,REFUZE);
        break;
    }
    default:
        break;
    }
    hideAll();
}

MainWindow::endStatement()
{
    switch(mytimer->getType())
    {
    case(statementTimer):
    {
        gInfo->Feedback(CM_TALK,REFUZE);
        stopState();
        break;
    }
    case(wolfDiscussion):
    {
        gInfo->Feedback(CM_GROUP,REFUZE);
        stopState();
        break;
    }
    case(noteTimer):
    {
        gInfo->Feedback(CM_NOTE,REFUZE);
        stopState();
        break;
    }
    default:
        break;
    }
    mytimer->stop();
    hideAll();
}

MainWindow::opChoice()
{
    QString name = sender()->objectName();
    string temp = qstr2str(name);
    if(name=="handOver")
    {
    }
    else if(name=="tearUp")
    {
        gInfo->Feedback(CM_XOTHER,REFUZE);
        mytimer->stop();
        hideAll();
    }
    else if(name=="shot")
    {
    }
    else if(name=="notShot")
    {
        gInfo->Feedback(CM_HUNTER,REFUZE);
        mytimer->stop();
        hideAll();
    }
    else if(name=="poison")
    {
    }
    else if(name=="anti")
    {
        gInfo->Feedback(CM_WITCH,REFUZE,"",UseAntidote);
        mytimer->stop();
        hideAll();
    }
    else if(name=="giveUp")
    {
        gInfo->Feedback(CM_XOTHER,REFUZE);
        mytimer->stop();
        hideAll();
    }
}

MainWindow::startGame()
{
    ipLabel->hide();
    ipText->hide();
    start->hide();
    QString qip = ipText->text();
    string ip = qstr2str(qip);
    gInfo = new GameInfo;
    gInfo->setpmainwindow(this);
    client = new CClient(DONTWAIT);
    client->Connect(8080, ip.c_str());
    gThread = new GameThread(client,this);
    gThread->start();
}

MainWindow::receive(QString qstr)
{
    int nComm;
    string strComm,strPara;
    string str=qstr2str(qstr);
    gInfo->Parse(str,strComm,strPara);

    for(int i=0;i<vecCommandList.size();++i)
        if(strComm==vecCommandList[i])
            nComm=i;

    gInfo->DoParametres(nComm,strPara);
}

void MainWindow::addLine(int n, string str, msgType type, bool isNotice)
{
    QString num = QString::number(n);
    QString msg = str2qstr(str);
    QListWidgetItem* temp = new QListWidgetItem();
    temp->setFont(font2);
    temp->setTextColor(Qt::yellow);
    if(isNotice==true)
        temp->setTextColor(QColor(255,100,0));
    temp->setText(num+tr("号：")+msg);
    if(type==publicMsg)
    {
        this->publicList->addItem(temp);
        publicList->scrollToBottom();
    }
    if(type==teamMsg)
    {
        this->teamList->addItem(temp);
        teamList->scrollToBottom();
    }
}

void MainWindow::addLine(string str, msgType type)
{
    QListWidgetItem* temp = new QListWidgetItem();
    temp->setFont(font2);
    temp->setTextColor(Qt::yellow);
    temp->setText(str2qstr(str));
    if(type==progressMsg)
    {
        this->progressList->addItem(temp);
        progressList->scrollToBottom();//添加消息后将滚动条自动移动到底部
    }
    else if(type==publicMsg)
    {
        this->publicList->addItem(temp);
        publicList->scrollToBottom();
    }
    else if(type==teamMsg)
    {
        cout<<str<<"CNM"<<endl;
        this->teamList->addItem(temp);
        teamList->scrollToBottom();
    }
}

void MainWindow::addLine(QString qstr, msgType type)
{
    QListWidgetItem* temp = new QListWidgetItem();
    temp->setFont(font2);
    temp->setTextColor(Qt::yellow);
    temp->setText(qstr);
    if(type==progressMsg)
    {
        this->progressList->addItem(temp);
        progressList->scrollToBottom();//添加消息后将滚动条自动移动到底部
    }
    else if(type==publicMsg)
    {
        this->publicList->addItem(temp);
        publicList->scrollToBottom();
    }
    else if(type==teamMsg)
    {
        this->teamList->addItem(temp);
        teamList->scrollToBottom();
    }
}

void MainWindow::setButtons(enCommandList commandType, vector<bool> validTarget, bool isPoisoned, bool isAntidote)
{
    switch(commandType)
    {
    case(CM_KILL):
    {
        mytimer->resetTimer(wolfVoting);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("杀"));
                findChild<QPushButton*>(childName)->show();
            }
        }
        break;
    }
    case(CM_BADGE):
    {
        mytimer->resetTimer(badgeVoting);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                cout<<validTarget[i]<<" ";
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("警"));
                findChild<QPushButton*>(childName)->show();
            }
            cout<<endl;
        }
        break;
    }
    case(CM_EXILE):
    {
        mytimer->resetTimer(votingTimer);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("票"));
                findChild<QPushButton*>(childName)->show();
            }
        }
        break;
    }
    case(CM_INDICATE):
    {
        mytimer->resetTimer(prophetTimer);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("查"));
                findChild<QPushButton*>(childName)->show();
            }
        }
        break;
    }
    case(CM_WITCH):
    {
        mytimer->resetTimer(witchTimer);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("毒"));
                findChild<QPushButton*>(childName)->show();
            }
        }
        if(!isPoisoned)
            poison->show();
        if(!isAntidote)
            anti->show();
        giveUp->show();
        break;
    }
    case(CM_HUNTER):
    {
        mytimer->resetTimer(hunterTimer);//考虑到猎人暴露，设置预操作
        shot->show();
        notShot->show();
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText("枪");
                findChild<QPushButton*>(childName)->show();
            }
        }
        break;
    }
    case(CM_NOTE):
    {
        mytimer->resetTimer(noteTimer);
        connect(publicSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
        connect(publicText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
        connect(endState,SIGNAL(clicked(bool)),this,SLOT(endStatement()));
        break;
    }
    case(CM_TALK):
    {
        mytimer->resetTimer(statementTimer);
        connect(publicSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
        connect(publicText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
        connect(endState,SIGNAL(clicked(bool)),this,SLOT(endStatement()));
        break;
    }
    case(CM_XOTHER):
    {
        mytimer->resetTimer(badgeTimer);
        handOver->show();
        tearUp->show();
        for(int i=0;i<PlayerTotality;++i)
        {
            if(validTarget[i])
            {
                QString childName = "V";
                childName+=QString::number(i,10);
                findChild<QPushButton*>(childName)->setText(tr("转"));
                findChild<QPushButton*>(childName)->show();
            }
        }
        break;
    }
    case(CM_GROUP):
    {
        mytimer->resetTimer(wolfDiscussion);
        connect(teamSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
        connect(teamText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
        connect(endState,SIGNAL(clicked(bool)),this,SLOT(endStatement()));
        break;
    }
    default:
        break;
    }
}

void MainWindow::die(int n)
{
    QString childName = "player";
    childName+=QString::number((n),10);
    findChild<PlayerAvatar*>(childName)->playerDie();
}

void MainWindow::hideBadge(int n)
{
    QString childName = "player";
    childName+=QString::number((n),10);
    findChild<PlayerAvatar*>(childName)->playerHideBadge();
}

void MainWindow::showBadge(int n)
{
    QString childName = "player";
    childName+=QString::number((n),10);
    findChild<PlayerAvatar*>(childName)->playerShowBadge();
}

void MainWindow::hideAll()
{
    handOver->hide();
    tearUp->hide();
    shot->hide();
    notShot->hide();
    poison->hide();
    anti->hide();
    giveUp->hide();
    player1->voting->hide();
    player2->voting->hide();
    player3->voting->hide();
    player4->voting->hide();
    player5->voting->hide();
    player6->voting->hide();
    player7->voting->hide();
    player8->voting->hide();
}

void MainWindow::stopState()
{
    disconnect(publicSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
    disconnect(teamSend,SIGNAL(clicked()),this,SLOT(sendMsg()));
    disconnect(publicText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
    disconnect(teamText,SIGNAL(returnPressed()),this,SLOT(sendMsg()));
    disconnect(endState,SIGNAL(clicked(bool)),this,SLOT(endStatement()));
}

void MainWindow::setId(int n)
{
    id=n;
    QString qstrofNum = QString::number(id+1,10);
    QString htmlFont = QString(tr("<strong><font color=black size=5>你的编号：<font color=black size=6>"))+qstrofNum;
    numLabel->setText(htmlFont);
}

void MainWindow::setIdentity(enIdentity enid)
{
    identity = enid;
    switch(identity)
    {
    case werewolf:
    {
        idLabel->setText("<strong><font color=black size=5>你的身份：<font color=black size=6>狼人");
        break;
    }
    case villager:
    {
        idLabel->setText("<strong><font color=black size=5>你的身份：<font color=black size=6>村民");
        break;
    }
    case prophet:
    {
        idLabel->setText("<strong><font color=black size=5>你的身份：<font color=black size=6>预言家");
        break;
    }
    case witch:
    {
        idLabel->setText("<strong><font color=black size=5>你的身份：<font color=black size=6>女巫");
        break;
    }
    case hunter:
    {
        idLabel->setText("<strong><font color=black size=5>你的身份：<font color=black size=6>猎人");
        break;
    }
    default:
    {
        break;
    }
    }
}

void MainWindow::showIdentity(vector<int> vecIdentity)
{
    for(int i=0;i<PlayerTotality;++i)
    {
        QString childName = "player";
        childName+=QString::number(i,10);
        findChild<PlayerAvatar*>(childName)->playerShowIdentity(vecIdentity[i]);
    }
}

void MainWindow::resetGame()
{
    gThread->endThread();
    client->Close();
    ipText->show();
    ipLabel->show();
    start->show();
}
