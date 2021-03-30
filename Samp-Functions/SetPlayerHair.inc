#include <a_samp>
#include <YSI\y_hooks>

/* Hair */
enum
{
	HAIR_TYPE_NONE = 0,
	HAIR_TYPE_AFRO,
	HAIR_TYPE_CLOWN,
	HAIR_TYPE_DREADLOCKS,
	HAIR_TYPE_ELVIS
};


stock IsValidSlot(playerid, slot)
{
	if(IsPlayerAttachedObjectSlotUsed(playerid, slot)) return false;
	else return true;
}

SetPlayerHair(playerid, hair_type, slot)
{
	switch(hair_type)
	{
		case HAIR_TYPE_AFRO:
		{
			RemovePlayerAttachedObject(playerid, slot);
			SetPlayerAttachedObject(playerid,slot,18640,2,0.092999,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_CLOWN:
		{
			RemovePlayerAttachedObject(playerid, slot);
			SetPlayerAttachedObject(playerid,slot,19274,2,0.111999,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_DREADLOCKS:
		{
			RemovePlayerAttachedObject(playerid, slot);
			SetPlayerAttachedObject(playerid,slot,19136,2,0.116999,0.013000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		case HAIR_TYPE_ELVIS: 
		{
			RemovePlayerAttachedObject(playerid, slot);
			SetPlayerAttachedObject(playerid,slot,18975,2,0.142000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000,1.000000,1.000000);
		}
		default:
		{
			print("ERROR: Undefined hair type.");
		}
	}
	return 1;
}