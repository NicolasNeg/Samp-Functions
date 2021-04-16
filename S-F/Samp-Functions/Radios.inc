#include <a_samp> // credits for the samp team

#define INVALID_STATE_FREQ -1
#define FREQ_STATE_DISCONNECTED 0
#define FREQ_STATE_CONNECTED 1
#define FREQ_STATE_JOIN 2
#define FREQ_STATE_LEAVE 3
#define OFF_RADIO 4
#define ON_RADIO 5

forward OnPlayerChangeFreq(playerid, Float: freq, oldstate_, newstate_);

new Float:Frequence[MAX_PLAYERS];
new FreqState[MAX_PLAYERS];
new bool:Radio[MAX_PLAYERS];

stock Radio_State(playerid)
{
    if(Radio[playerid] == true)
    {
        Frequence[playerid] = 0.0;
        FreqState[playerid] = OFF_RADIO;
        Radio[playerid] = false;
        CallRemoteFunction("OnPlayerChangeFreq", "ifii", playerid, 0.0, ON_RADIO, OFF_RADIO);
    }
    else
    {
        FreqState[playerid] = ON_RADIO;
        Radio[playerid] = true;
        Frequence[playerid] = 0.0;
        CallRemoteFunction("OnPlayerChangeFreq", "ifii", playerid, 0.0, OFF_RADIO, ON_RADIO);
    }
    return 1;
}

stock GetFreq(playerid)
{
    return Frequence[playerid];
}

stock SendRadioMessage(playerid, Float: freq, const message[])
{
    new string[144];
    format(string,sizeof(string),"[Radio - %0.2f ]: %s - %s ", freq, pName(playerid), message);
    for(new i; i<MAX_PLAYERS; i++)
    {
        if(Frequence[i] == Frequence[playerid])
        {
            SendClientMessage(i, -1, string);
        }
    }
    return 1;
}

stock GetState(playerid)
{
    return FreqState[playerid];
}

stock SetFreq(playerid, Float: freq)
{
    Frequence[playerid] = freq;
    FreqState[playerid] = FREQ_STATE_JOIN;
    CallRemoteFunction("OnPlayerChangeFreq", "ifii", playerid, freq, FREQ_STATE_LEAVE, FREQ_STATE_JOIN);
    return 1;
}