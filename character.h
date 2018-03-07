#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "basicinfo.h"



//character base class
class cBaseCharacter
{
protected:
    virtual bool IsOperateValid() {};	//check the validility of operation of character

    virtual  ~cBaseCharacter() = default;
};

//cWerewolf
class cWerewolf : public cBaseCharacter
{
public:
    bool IsOperateValid(TID target, bool bAlive);
    void Kill(TID target, vector<state> PlayerState);					//kill the appointed target
};

//villager
class cVillager : public cBaseCharacter{};

//prophet
class cProphet : public cBaseCharacter
{
private:
    vector<int> PlayerCharOfProphet;										//the characters of players which have been checked

public:
    bool IsOperateValid(TID target, bool bAlive, TID ID);
    cProphet() :PlayerCharOfProphet(PlayerTotality, UnknownPlayer) {};
    void Check(TID target, vector<state> PlayerState, TPlayerChar Playerchar);				//check the character of target
};

class cWitch : public cBaseCharacter
{
private:
    bool IsAntidoteUsed;
    bool IsPoisonUsed;

public:
    enum eAction
    {
        UseAntidote,
        UsePoison,
        DoNothing
    };
    bool IsOperateValid(int action, TID target, vector<state> PlayerState);
    cWitch() :IsAntidoteUsed(false), IsPoisonUsed(false) {};
    void Medication(int action, TID target, vector<state> PlayerState);
    bool get_poison(){return IsPoisonUsed;}
    bool get_antidote() {return IsAntidoteUsed;}
};

class cHunter : public cBaseCharacter
{
public:
    bool IsOperateValid(TID target, bool bAlive, bool doshoot);
    void Shoot(TID target, vector<state> PlayerState, bool doshoot);				//shoot the character of target
};

class cCupido :public cBaseCharacter
{
private:
    bool IsCombineUsed;

public:
    bool IsOperateValid(TID target1, TID target2, vector<state> PlayerState);
    cCupido() :IsCombineUsed(false) {};
    void Combine(TID target1, TID target2, vector<state> PlayerState);		//combine two players
};

class cGuardian :public cBaseCharacter
{
private:
    TID LastGuarded;			//the player protected at last round

public:
    bool IsOperateValid(TID target, bool bAlive, TID ID);
    void Guard(TID target, vector<state> PlayerState);				//protect an appointed player
    cGuardian() :LastGuarded(PlayerTotality) {};
};


#endif
