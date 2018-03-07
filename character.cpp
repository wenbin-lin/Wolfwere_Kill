#include "character.h"

bool cWerewolf::IsOperateValid(TID target, bool IsAlive)
{
    if (target < PlayerTotality
        &&	 IsAlive)			//the target is still alive
        return true;
    else return false;
}

void cWerewolf::Kill(TID target, vector<state> PlayerState)
{
    if (cWerewolf::IsOperateValid(target, PlayerState[target].bAlive))
        PlayerState[target].bDying = true;
}

bool cProphet::IsOperateValid(TID target, bool IsAlive, TID ID)
{
    if (target < PlayerTotality
        && IsAlive				//the target is still alive
        && target != ID)		//not checking self
        return true;
    else return false;
}

void cProphet::Check(TID target, vector<state> PlayerState, TPlayerChar Playerchar)
{
    if (IsOperateValid(target, PlayerState[target].bAlive, Playerchar))
        PlayerCharOfProphet[target] = Playerchar;
}

bool cWitch::IsOperateValid(int action, TID target, vector<state> PlayerState)
{
    if (target < PlayerTotality)
        if( action == UseAntidote
            && !IsAntidoteUsed
            &&PlayerState[target].bDying		//the target is dying
            ||action ==UsePoison
            && !IsPoisonUsed
            &&PlayerState[target].bAlive)		//the target is still alive
        return true;
    return false;
}

void cWitch::Medication(int action, TID target, vector<state> PlayerState)
{
    if (IsOperateValid(action, target, PlayerState))
    {
        if (action == UseAntidote)
        {
            PlayerState[target].bDying = false;
            IsAntidoteUsed = true;
        }

        else
        {
            if (action == UsePoison)
            {
                PlayerState[target].bAlive = false;
                IsPoisonUsed = true;
            }
        }
    }
}


bool cHunter::IsOperateValid(TID target,bool IsAlive, bool doshoot)
{
    if (doshoot)						//hunter decides to shoot
        if (IsAlive)							//the target is still alive
            return true;
    return false;
}

void cHunter::Shoot(TID target, vector<state> PlayerState, bool doshoot)
{
    if (IsOperateValid(target, PlayerState[target].bAlive, doshoot))
        PlayerState[target].bAlive = false;
}
/*
bool cCupido::IsOperateValid(TID target1, TID target2, vector<state> PlayerState)
{
    if (!IsCombineUsed)
        if (target1 < PlayerTotality
            &&target2 < PlayerTotality
            &&target1 != target2
            &&PlayerState[target1].bAlive
            &&PlayerState[target2].bAlive)
            return true;
    return false;
}

void cCupido::Combine(TID target1, TID target2, vector<state> PlayerState)
{
    if (IsOperateValid(target1, target2, PlayerState))
    {
        PlayerState[target1].IsCombined = true;
        PlayerState[target2].IsCombined = true;
        IsCombineUsed = true;
    }
}

bool cGuardian::IsOperateValid(TID target, bool IsAlive, TID ID)
{
    if (LastGuarded < PlayerTotality)
    {
        if (target < PlayerTotality
            && target != ID
            && IsAlive)			//the target is still alive
            return true;
    }
    else
        if (target < PlayerTotality
            &&	 IsAlive)			//the target is still alive
            return true;
    else return false;
}

void cGuardian::Guard(TID target, vector<state> PlayerState)
{
    if (IsOperateValid(target, PlayerState[target].IsAlive, ID))
    {
        PlayerState[target].IsGuarded = true;
        LastGuarded = target;
    }
}
*/
