#include "gameinfo.h"

void PlayerInfo::DefIdentity()
{
    switch (m_nch)
    {
    case werewolf:
        pBaseIdentity = new cWerewolf;
        m_strIdentity = "werewolf";
        break;
    case villager:
        pBaseIdentity = new cVillager;
        m_strIdentity = "Villager";
        break;
    case prophet:
        pBaseIdentity = new cProphet;
        m_strIdentity = "prophet";
        break;
    case witch:
        pBaseIdentity = new cWitch;
        m_strIdentity = "witch";
        break;
    case hunter:
        pBaseIdentity = new cHunter;
        m_strIdentity = "hunter";
        break;
    default:
        break;
    }
}


PlayerInfo::PlayerInfo(std::string strName)
    :m_strIdentity(), m_stateSelf()
{
    m_nch = -1;
    m_strPlayerName = strName;
    DefIdentity();
}


std::string PlayerInfo::GetName()
{
    return m_strPlayerName;
}

//Parse string
void GameInfo::Parse(const string & str, string &strComm, string &strPara)
{
    if (str.empty())
    {
        return;
    }
    strComm = str.substr(0, str.find("|"));
    strPara = str.substr(1 + str.find("|"));

}


//Do something to proceed parametres
void GameInfo::DoParametres
(
    int nComm,	//Case of Command
    const string & str	//Parametre of Command
)
{
    vector<bool> validtarget(PlayerTotality, false);

    switch (nComm) {
    case CM_SHOW:
        pmainwindow->addLine(str);
        break;
    case CM_KILL:
    {
        if (PlayerSelf.m_nch == werewolf
            &&PlayerSelf.m_stateSelf.bAlive)
        {
            cWerewolf* WerewolfPlayer = dynamic_cast<cWerewolf*>(PlayerSelf.pBaseIdentity);
            int end=0;
            while(end<str.size()){
                validtarget[int(str[end])-48]=true;
                end += 2;
            }

            pmainwindow->setButtons(CM_KILL,validtarget);

        }
        break;
    }

    case CM_BADGE:
    {
        if (PlayerSelf.m_stateSelf.bAlive)
        {
            int end=0;
            while(end<str.size()){
                validtarget[int(str[end])-48]=true;
                end += 2;
            }
            pmainwindow->setButtons(CM_BADGE,validtarget);
        }
        break;
    }
    case CM_EXILE:
    {
        if (PlayerSelf.m_stateSelf.bAlive)
        {
            int end=0;
            while(end<str.size()){
                validtarget[int(str[end])-48]=true;
                end += 2;
            }
            pmainwindow->setButtons(CM_EXILE,validtarget);
        }
        break;
    }

    case CM_INDICATE:
    {
        if (PlayerSelf.m_nch == prophet
            &&PlayerSelf.m_stateSelf.bAlive)
        {
            cProphet* prophetplayer = dynamic_cast<cProphet*>(PlayerSelf.pBaseIdentity);
            for (int i = 0;i < PlayerTotality;++i)
                validtarget[i] = playerstate[i].bAlive;
            validtarget[PlayerSelf.get_ID()]=false;

            pmainwindow->setButtons(CM_INDICATE,validtarget);

        }
        break;
    }
    case CM_WITCH:
    {
        if (PlayerSelf.m_nch == witch
            &&PlayerSelf.m_stateSelf.bAlive)
        {
            cWitch* WitchPlayer = dynamic_cast<cWitch*>(PlayerSelf.pBaseIdentity);
            int antidotetarget=0;
            QString msg;

            for (int i = 0;i < PlayerTotality;++i){
                validtarget[i] = WitchPlayer->IsOperateValid(WitchPlayer->UsePoison, i, playerstate);
                if(WitchPlayer->IsOperateValid(WitchPlayer->UseAntidote, i, playerstate))
                    antidotetarget=i;
            }
            msg = str2qstr(to_string(antidotetarget+1)) + "号玩家被狼人杀死";

            if(!WitchPlayer->UseAntidote)
                pmainwindow->addLine(msg,teamMsg);
            pmainwindow->setButtons(CM_WITCH,validtarget,WitchPlayer->get_poison(),WitchPlayer->get_antidote());
        }
        break;
    }
    case CM_HUNTER:
    {
        if (PlayerSelf.m_nch == hunter)
        {
            cHunter* HunterPlayer = dynamic_cast<cHunter*>(PlayerSelf.pBaseIdentity);
            for (int i = 0;i < PlayerTotality;++i)
                validtarget[i] = playerstate[i].bAlive;

            if (!PlayerSelf.m_stateSelf.bAlive)
            {
                pmainwindow->setButtons(CM_HUNTER,validtarget);
            }
        }
        break;
    }
    case CM_NOTE:
    {
        if (!PlayerSelf.m_stateSelf.bAlive)
        {
            pmainwindow->setButtons(CM_NOTE);

        }
        break;
    }

    case CM_CHARACTER:
    {
        string strID(str.substr(str.find("|") + 1, str.find(" "))),
            strCharacter(str.substr(str.find(" ") + 1));

        PlayerSelf.set_ID(stoi(strID));
        PlayerSelf.m_nch = stoi(strCharacter);
        pmainwindow->setId(PlayerSelf.get_ID());
        pmainwindow->setIdentity((enIdentity)PlayerSelf.m_nch);
        PlayerSelf.DefIdentity();
        break;
    }
    case CM_TALK:
    {
        pmainwindow->setButtons(CM_TALK);
        break;
    }
    case CM_XOTHER:
    {
        if (PlayerSelf.m_stateSelf.bBadged)
        {
            for (int i = 0;i < PlayerTotality;++i)
                validtarget[i] = playerstate[i].bAlive;
            pmainwindow->setButtons(CM_XOTHER,validtarget);
            PlayerSelf.m_stateSelf.bBadged = false;
        }
        break;
    }

    case CM_RESULT:
    {
        vector<int> vecIdentity(PlayerTotality,0);
        string identity,result;
        QString msg;
        identity = str.substr(0,str.find(" "));
        result = str.substr(str.find(" "));
        if(identity.size()==8)
        {
            for(int i=0;i<PlayerTotality;++i)
                vecIdentity[i]=identity[i]-48;
        }
        if(stoi(result)==1)
            msg = "村民获胜，请村民发表胜利感言";
        else
            msg = "狼人获胜，请开始你们的表演";
        pmainwindow->addLine(msg,progressMsg);
        pmainwindow->showIdentity(vecIdentity);
        pmainwindow->resetGame();
        break;
    }
    case CM_GROUP:
    {
        pmainwindow->setButtons(CM_GROUP);
        break;
    }
    case CM_SYNCA:
    {
        for (int i = 0;i < PlayerTotality;++i)
        {
            if (str[i] == '0'
                    &&playerstate[i].bAlive==true){
                cout<<i+1<<" die"<<endl;
                playerstate[i].bAlive = false;
                pmainwindow->die(i);
            }
            else
                if (str[i] == '1')
                    playerstate[i].bAlive = true;
        }
        PlayerSelf.m_stateSelf.bAlive = playerstate[PlayerSelf.get_ID()].bAlive;
        break;
    }
    case CM_SYNCD:
    {
        for (int i = 0;i < PlayerTotality;++i)
        {
            if (str[i] == '0')
                playerstate[i].bDying = false;
            else
                if (str[i] == '1')
                    playerstate[i].bDying = true;
        }
        PlayerSelf.m_stateSelf.bDying = playerstate[PlayerSelf.get_ID()].bDying;
        break;
    }
    case CM_IDRES:
    {
        if (PlayerSelf.m_nch == prophet
            &&PlayerSelf.m_stateSelf.bAlive)
        {
            string indicatee,result;
            indicatee = str.substr(0,str.find(" "));
            result = str.substr(str.find(" "));
            QString msg = "玩家";
            msg += QString::number((stoi(indicatee)+1),10);
            if(stoi(result)==0)
                msg += "是好人";
            else
                msg += "是狼";
            pmainwindow->addLine(msg,teamMsg);
        }
        break;
    }
    case CM_SYNCBADGE:
    {
        int police=stoi(str);
        for(int i=0;i<PlayerTotality;++i)
        {
            if(i==police){
                playerstate[i].bBadged=true;
                pmainwindow->showBadge(i);
            }
            else
                pmainwindow->hideBadge(i);
        }
        if(police==PlayerSelf.get_ID())
            PlayerSelf.m_stateSelf.bBadged=true;
        break;
    }
    case CM_VOTE:
    {
        string voter,votee;
        voter=str.substr(0,str.find('~'));
        votee=str.substr(str.find('~')+1);
        if(playerstate[stoi(voter)-1].bAlive)
        {
            QString voteresult= "玩家";
            voteresult += str2qstr(str.substr(0,str.find('~')));
            if(stoi(votee) > PlayerTotality)
                voteresult += "弃票";
            else
            {
                voteresult += "投了";
                voteresult+=str2qstr(votee);
            }

            pmainwindow->addLine(voteresult);
        }
        break;
    }
    case CM_PUBLIC:
    {
        pmainwindow->addLine(str,publicMsg);
        break;
    }
    case CM_TEAM:
    {
        pmainwindow->addLine(str,teamMsg);
        break;
    }
    default:
        break;
    }
    validtarget.~vector();
}


void GameInfo::Feedback(enCommandList nResp, int target, string str, eAction action) {


    string msg;
    switch (nResp)
    {
    case CM_SHOW:
        break;

    case CM_KILL:{
        cWerewolf* WerewolfPlayer = dynamic_cast<cWerewolf*>(PlayerSelf.pBaseIdentity);
        WerewolfPlayer->Kill(target, playerstate);
        msg = "_K|" + to_string(target);
        pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        break;
    }

    case CM_BADGE:{
        msg = "_B|"+to_string(PlayerSelf.get_ID()+1);
        msg += "~";
        msg += to_string(target+1);
        pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        break;
    }

    case CM_EXILE:{
        msg = "_E|"+to_string(PlayerSelf.get_ID()+1);
        msg += "~";
        msg += to_string(target+1);
        pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        break;
    }

    case CM_INDICATE:{
        msg = "_I|" + to_string(target);
        pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        break;
    }

    case CM_WITCH:{
        cWitch* WitchPlayer = dynamic_cast<cWitch*>(PlayerSelf.pBaseIdentity);
        if (action  == UsePoison)
        {
            WitchPlayer->Medication(WitchPlayer->UsePoison, target, playerstate);
            msg = "_P|" + to_string(target);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        else
        {
            if (action == UseAntidote)
            {
                for (int i = 0;i < PlayerTotality;++i){
                    if(WitchPlayer->IsOperateValid(WitchPlayer->UseAntidote, i, playerstate))
                        target=i;
                }

                msg = "_A|" + to_string(target);
                pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
                WitchPlayer->Medication(WitchPlayer->UseAntidote, target, playerstate);
            }
            else
            {
                msg = "_W|";
                pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
            }
        }
        break;
    }

    case CM_HUNTER:{
        cHunter* HunterPlayer = dynamic_cast<cHunter*>(PlayerSelf.pBaseIdentity);
        if (target != REFUZE ) {
            HunterPlayer->Shoot(target, playerstate, action);
            msg = "_H|" + to_string(target);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        else {
            msg = "_H|" + REFUZE;
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }

        break;
    }
    case CM_NOTE:{
        if (target != REFUZE) {
            msg = "_N|" + to_string(PlayerSelf.get_ID());
            msg += " : ";
            msg += str;
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }

        else {
            msg = "_ST|" + to_string(REFUZE);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        break;
    }
    case CM_CHARACTER:
        break;
    case CM_TALK:{
        if (target != REFUZE) {
            msg = "_T|Player " + to_string(PlayerSelf.get_ID() + 1);
            msg += " : ";
            msg += str;
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }

        else {
            msg = "_ST|";
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        break;
    }
    case CM_XOTHER:{
        if (target != REFUZE) {
            msg = "_X|" + to_string(target);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        else {
            msg = "_X|" + to_string(REFUZE);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        break;
    }
    case CM_RESULT:
        break;
    case CM_GROUP:
    {
        if (target != REFUZE) {
            msg = "_T|" + to_string(PlayerSelf.get_ID()+1);
            msg += " : ";
            msg += str;

            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }

        else {
            msg = "_ST|" + to_string(REFUZE);
            pmainwindow->client->SendMsg(msg.c_str(), LEN(msg));
        }
        break;
    }
    case CM_SYNCA:
        break;
    case CM_SYNCD:
        break;
    case CM_IDRES:
        break;
    case CM_VOTE:
        break;
    case CM_PUBLIC:
        break;
    case CM_TEAM:
        break;
    default:break;
    }


}
