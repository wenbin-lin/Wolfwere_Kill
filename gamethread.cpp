#include "gamethread.h"

GameThread::GameThread(QObject *parent) : QThread(parent)
{
}

GameThread::GameThread(CClient* cli, QObject *rec, QObject *parent): QThread(parent)
{
    client = cli;
    receiver = rec;
}

void GameThread::run()
{
    connect(this,SIGNAL(send(QString)),receiver,SLOT(receive(QString)));
    char Command[MAX_SIZE];
    string strComm;
    do {
        if(client->RecvMsg(Command, MAX_SIZE)==0)
        {
            string str(Command);
            if(!str.empty())
                strComm = str.substr(0, str.find("|"));
            cout<<str<<endl;
            QString qstr = str2qstr(str);
            emit send(qstr);
        }
        msleep(50);
    } while (strComm != "_R");
    client->Close();
    this->exec();
}

void GameThread::endThread()
{
    this->exec();
}
