#include <a_samp>

enum
{
	HAIR_TYPE_NONE = 0,
	HAIR_TYPE_AFRO,
	HAIR_TYPE_CLOWN,
	HAIR_TYPE_DREADLOCKS,
	HAIR_TYPE_ELVIS
};

/* SetPlayerMoney */
stock SetPlayerMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	return 1;
}

stock SetPlayerHair(playerid, hair_type, slot)
{
	switch(hair_type)
	{
		case HAIR_TYPE_AFRO:
		{
			SetPlayerAttachedObject(playerid,slot,18640,2,0.092999,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_CLOWN:
		{
			SetPlayerAttachedObject(playerid,slot,19274,2,0.111999,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_DREADLOCKS:
		{
			SetPlayerAttachedObject(playerid,slot,19136,2,0.116999,0.013000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_ELVIS: 
		{
			SetPlayerAttachedObject(playerid,slot,18975,2,0.142000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		default:
		{
			print("ERROR: Undefined hair type.");
		}
	}
	return 1;
}