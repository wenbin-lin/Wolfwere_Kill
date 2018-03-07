#ifndef BASICINFO_H
#define BASICINFO_H

#include<vector>
#include<string>
#include<QtWidgets>

using namespace std;

#define PlayerTotality 8				//the total amount of players
#define CharacterTotality 7				//the total amount of character
#define UnknownPlayer -1				//the players whose characters are unknown
#define LEN(s) 1+s.size()
#define REFUZE 951
#define MAX_SIZE 200

typedef unsigned int TID;				//to describe player's ID number (start from 0)
typedef unsigned int TPlayerChar;		//to describe player's character(look up "enum character" for specific info)

enum enResponseList
{
    RM_KILL, RM_TALK, RM_ANTIDOTE, RM_BADGE,
    RM_EXILE, RM_INDICATE, RM_NOTE, RM_POISON,
    RM_WITCH, RM_NAME, RM_XOHTER, RM_HUNTER,
    RM_GROUP, RM_VOTE
};

extern vector<string> vecCommandList;

enum enCommandList
{
    CM_SHOW, CM_KILL, CM_BADGE, CM_EXILE,
    CM_INDICATE, CM_WITCH,
    CM_HUNTER, CM_NOTE, CM_CHARACTER, CM_TALK,
    CM_XOTHER, CM_RESULT, CM_GROUP, CM_SYNCA,
    CM_SYNCD, CM_IDRES,CM_VOTE,
    CM_SYNCBADGE,CM_STOP,CM_PUBLIC,CM_TEAM
};

enum enIdentity
{
    werewolf, villager, prophet, witch, hunter, cupido, guardian
};

enum eAction
{
    UseAntidote,
    UsePoison,
    DoNothing
};


enum msgType
{
    progressMsg, publicMsg ,teamMsg
};

enum stateType
{
    publicState,teamState
};

enum timerType
{
    votingTimer,statementTimer,wolfDiscussion,wolfVoting,witchTimer,prophetTimer,badgeTimer,noteTimer,hunterTimer,badgeVoting
};

struct state							//to describe the state of player
{
    bool bAlive;						//true stands for live, false stands for death
    bool bDying;						//true stands for being going to die or being killed by werewolf
    //bool IsCombined;					//true stands for being combined with another player by Cupido
    //bool IsGuarded;						//true stands for being protected from killing of werewolf by guardian
    bool bBadged;						//true stands for being the police
    state() :bAlive(true), bDying(false)
        //, IsCombined(false), IsGuarded(false)
        , bBadged(false)
    {};
};

QString str2qstr(const string str);

string qstr2str(const QString qstr);

#endif // BASICINFO_H
