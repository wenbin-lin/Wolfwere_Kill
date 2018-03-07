#ifndef GAMEINFO_H
#define GAMEINFO_H


#include "character.h"
#include "basicinfo.h"
#include "mainwindow.h"
#include <string>
#include "Client.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <QtWidgets>
#include <QWidget>

#include <iostream>

using namespace std;


class MainWindow;

class PlayerInfo
{
private:
    std::string m_strPlayerName;
    TID m_ID;

public:
    int m_nch;
    state m_stateSelf;
    std::string m_strIdentity;

    PlayerInfo(std::string);
    PlayerInfo() = default;

    int get_ID(){return m_ID;}
    void set_ID(int i){m_ID=i;}

    std::string GetName();
    void DefIdentity();
    cBaseCharacter* pBaseIdentity;

};

class GameInfo
{
private:
    TID target;
    int Round;
    vector<state> playerstate;
    PlayerInfo PlayerSelf;
    MainWindow* pmainwindow;

public:
    GameInfo() :target(0), Round(0), playerstate(PlayerTotality){};

    void setpmainwindow(MainWindow* p){pmainwindow=p;};
    void Parse(const string & str, string &strComm, string &strPara);
    void DoParametres
    (
        int nComm,	//Case of Command
        const string & str	//Parametre of Command
    );
    void Feedback(enCommandList nResp, int target, string str="", eAction action = DoNothing);
};

#endif
