#include <a_samp>
#include <YSI\y_hooks>

/* Dialogs */
#define DG_INVALID -1
#define DG_STYLE_MSSGBOX 1
#define DG_STYLE_LIST 2

// soon... #define DG_STYLE_INPUT 3

#define MAX_DGs 100

/* Hair */
enum
{
	HAIR_TYPE_NONE = 0,
	HAIR_TYPE_AFRO,
	HAIR_TYPE_CLOWN,
	HAIR_TYPE_DREADLOCKS,
	HAIR_TYPE_ELVIS
};

/* Global variables */
new Using_Dialog[MAX_PLAYERS];
new bool:DG_OPENED[MAX_PLAYERS] = false;

/* Textdraws For dialogs */
new PlayerText:Box_Background[MAX_PLAYERS];
new PlayerText:close[MAX_PLAYERS];
new PlayerText:caption[MAX_PLAYERS];
new PlayerText:up_[MAX_PLAYERS];
new PlayerText:info[MAX_PLAYERS];
new PlayerText:left_[MAX_PLAYERS];
new PlayerText:right_[MAX_PLAYERS];
new PlayerText:down_[MAX_PLAYERS];
new PlayerText:button1[MAX_PLAYERS];
new PlayerText:button2[MAX_PLAYERS];

stock LoadTDPlayers(playerid)
{
	Box_Background[playerid] = CreatePlayerTextDraw(playerid, 329.000000, 151.000000, "_");
	PlayerTextDrawFont(playerid, Box_Background[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Box_Background[playerid], 0.645833, 15.000020);
	PlayerTextDrawTextSize(playerid, Box_Background[playerid], 298.500000, 231.000000);
	PlayerTextDrawSetOutline(playerid, Box_Background[playerid], 1);
	PlayerTextDrawSetShadow(playerid, Box_Background[playerid], 0);
	PlayerTextDrawAlignment(playerid, Box_Background[playerid], 2);
	PlayerTextDrawColor(playerid, Box_Background[playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, Box_Background[playerid], 1296911871);
	PlayerTextDrawBoxColor(playerid, Box_Background[playerid], 255);
	PlayerTextDrawUseBox(playerid, Box_Background[playerid], 1);
	PlayerTextDrawSetProportional(playerid, Box_Background[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Box_Background[playerid], 0);

	close[playerid] = CreatePlayerTextDraw(playerid, 437.000000, 148.000000, "x");
	PlayerTextDrawFont(playerid, close[playerid], 3);
	PlayerTextDrawLetterSize(playerid, close[playerid], 0.395832, 1.100000);
	PlayerTextDrawTextSize(playerid, close[playerid], 443.000000, 39.000000);
	PlayerTextDrawSetOutline(playerid, close[playerid], 0);
	PlayerTextDrawSetShadow(playerid, close[playerid], 0);
	PlayerTextDrawAlignment(playerid, close[playerid], 1);
	PlayerTextDrawColor(playerid, close[playerid], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, close[playerid], 166);
	PlayerTextDrawBoxColor(playerid, close[playerid], -1061109710);
	PlayerTextDrawUseBox(playerid, close[playerid], 0);
	PlayerTextDrawSetProportional(playerid, close[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, close[playerid], 1);

	caption[playerid] = CreatePlayerTextDraw(playerid, 220.000000, 151.000000, "Caption..");
	PlayerTextDrawFont(playerid, caption[playerid], 1);
	PlayerTextDrawLetterSize(playerid, caption[playerid], 0.250000, 1.299998);
	PlayerTextDrawTextSize(playerid, caption[playerid], 430.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, caption[playerid], 1);
	PlayerTextDrawSetShadow(playerid, caption[playerid], 0);
	PlayerTextDrawAlignment(playerid, caption[playerid], 1);
	PlayerTextDrawColor(playerid, caption[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, caption[playerid], 255);
	PlayerTextDrawBoxColor(playerid, caption[playerid], 50);
	PlayerTextDrawUseBox(playerid, caption[playerid], 0);
	PlayerTextDrawSetProportional(playerid, caption[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, caption[playerid], 0);

	up_[playerid] = CreatePlayerTextDraw(playerid, 329.000000, 169.000000, "_");
	PlayerTextDrawFont(playerid, up_[playerid], 1);
	PlayerTextDrawLetterSize(playerid, up_[playerid], 0.600000, -0.300018);
	PlayerTextDrawTextSize(playerid, up_[playerid], 299.000000, 221.000000);
	PlayerTextDrawSetOutline(playerid, up_[playerid], 1);
	PlayerTextDrawSetShadow(playerid, up_[playerid], 0);
	PlayerTextDrawAlignment(playerid, up_[playerid], 2);
	PlayerTextDrawColor(playerid, up_[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, up_[playerid], 255);
	PlayerTextDrawBoxColor(playerid, up_[playerid], -1061109625);
	PlayerTextDrawUseBox(playerid, up_[playerid], 1);
	PlayerTextDrawSetProportional(playerid, up_[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, up_[playerid], 0);

	info[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 175.000000, "Info...");
	PlayerTextDrawFont(playerid, info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, info[playerid], 0.266667, 1.000000);
	PlayerTextDrawTextSize(playerid, info[playerid], 435.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, info[playerid], 1);
	PlayerTextDrawSetShadow(playerid, info[playerid], 0);
	PlayerTextDrawAlignment(playerid, info[playerid], 1);
	PlayerTextDrawColor(playerid, info[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, info[playerid], 255);
	PlayerTextDrawBoxColor(playerid, info[playerid], -16777166);
	PlayerTextDrawUseBox(playerid, info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, info[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, info[playerid], 0);

	left_[playerid] = CreatePlayerTextDraw(playerid, 218.000000, 169.000000, "_");
	PlayerTextDrawFont(playerid, left_[playerid], 1);
	PlayerTextDrawLetterSize(playerid, left_[playerid], 0.600000, 9.600000);
	PlayerTextDrawTextSize(playerid, left_[playerid], 296.500000, -1.500000);
	PlayerTextDrawSetOutline(playerid, left_[playerid], 1);
	PlayerTextDrawSetShadow(playerid, left_[playerid], 0);
	PlayerTextDrawAlignment(playerid, left_[playerid], 2);
	PlayerTextDrawColor(playerid, left_[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, left_[playerid], 255);
	PlayerTextDrawBoxColor(playerid, left_[playerid], -1061109625);
	PlayerTextDrawUseBox(playerid, left_[playerid], 1);
	PlayerTextDrawSetProportional(playerid, left_[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, left_[playerid], 0);

	right_[playerid] = CreatePlayerTextDraw(playerid, 440.000000, 169.000000, "_");
	PlayerTextDrawFont(playerid, right_[playerid], 1);
	PlayerTextDrawLetterSize(playerid, right_[playerid], 0.600000, 9.600000);
	PlayerTextDrawTextSize(playerid, right_[playerid], 296.500000, -1.500000);
	PlayerTextDrawSetOutline(playerid, right_[playerid], 1);
	PlayerTextDrawSetShadow(playerid, right_[playerid], 0);
	PlayerTextDrawAlignment(playerid, right_[playerid], 2);
	PlayerTextDrawColor(playerid, right_[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, right_[playerid], 255);
	PlayerTextDrawBoxColor(playerid, right_[playerid], -1061109625);
	PlayerTextDrawUseBox(playerid, right_[playerid], 1);
	PlayerTextDrawSetProportional(playerid, right_[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, right_[playerid], 0);

	down_[playerid] = CreatePlayerTextDraw(playerid, 329.000000, 260.000000, "_");
	PlayerTextDrawFont(playerid, down_[playerid], 1);
	PlayerTextDrawLetterSize(playerid, down_[playerid], 0.600000, -0.300018);
	PlayerTextDrawTextSize(playerid, down_[playerid], 299.000000, 221.000000);
	PlayerTextDrawSetOutline(playerid, down_[playerid], 1);
	PlayerTextDrawSetShadow(playerid, down_[playerid], 0);
	PlayerTextDrawAlignment(playerid, down_[playerid], 2);
	PlayerTextDrawColor(playerid, down_[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, down_[playerid], 255);
	PlayerTextDrawBoxColor(playerid, down_[playerid], -1061109625);
	PlayerTextDrawUseBox(playerid, down_[playerid], 1);
	PlayerTextDrawSetProportional(playerid, down_[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, down_[playerid], 0);

	button1[playerid] = CreatePlayerTextDraw(playerid, 283.000000, 265.000000, "button1");
	PlayerTextDrawFont(playerid, button1[playerid], 1);
	PlayerTextDrawLetterSize(playerid, button1[playerid], 0.258332, 1.750000);
	PlayerTextDrawTextSize(playerid, button1[playerid], 321.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, button1[playerid], 1);
	PlayerTextDrawSetShadow(playerid, button1[playerid], 0);
	PlayerTextDrawAlignment(playerid, button1[playerid], 1);
	PlayerTextDrawColor(playerid, button1[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, button1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, button1[playerid], -1061109710);
	PlayerTextDrawUseBox(playerid, button1[playerid], 1);
	PlayerTextDrawSetProportional(playerid, button1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, button1[playerid], 1);

	button2[playerid] = CreatePlayerTextDraw(playerid, 340.000000, 265.000000, "button2");
	PlayerTextDrawFont(playerid, button2[playerid], 1);
	PlayerTextDrawLetterSize(playerid, button2[playerid], 0.258332, 1.750000);
	PlayerTextDrawTextSize(playerid, button2[playerid], 380.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, button2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, button2[playerid], 0);
	PlayerTextDrawAlignment(playerid, button2[playerid], 1);
	PlayerTextDrawColor(playerid, button2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, button2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, button2[playerid], -1061109710);
	PlayerTextDrawUseBox(playerid, button2[playerid], 1);
	PlayerTextDrawSetProportional(playerid, button2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, button2[playerid], 1);
	return 1;
}


/* SetPlayerMoney */
stock SetPlayerMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	return 1;
}

/* SetPlayerHair */
stock SetPlayerHair(playerid, hair_type, slot)
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

/* CreateDialog */
stock CreateDialog(playerid, DIALOG_ID, DIALOG_CAPTION[], DIALOG_INFO[], DIALOG_BTN1[], DIALOG_BTN2[])
{
	if(DG_OPENED[playerid]) return SendClientMessage(playerid, -1, "You are with a DG opened");
	Using_Dialog[playerid] = DIALOG_ID;
	DG_OPENED[playerid] = true;
	SelectTextDraw(playerid, 0xFF0000FF);
	PlayerTextDrawSetString(playerid, caption[playerid], DIALOG_CAPTION);
	PlayerTextDrawSetString(playerid, info[playerid], DIALOG_INFO);
	PlayerTextDrawSetString(playerid, button1[playerid], DIALOG_BTN1);
	PlayerTextDrawSetString(playerid, button2[playerid], DIALOG_BTN2);
	PlayerTextDrawShow(playerid, Box_Background[playerid]);
	PlayerTextDrawShow(playerid, close[playerid]);
	PlayerTextDrawShow(playerid, caption[playerid]);
	PlayerTextDrawShow(playerid, up_[playerid]);
	PlayerTextDrawShow(playerid, info[playerid]);
	PlayerTextDrawShow(playerid, left_[playerid]);
	PlayerTextDrawShow(playerid, right_[playerid]);
	PlayerTextDrawShow(playerid, down_[playerid]);
	PlayerTextDrawShow(playerid, button1[playerid]);
	PlayerTextDrawShow(playerid, button2[playerid]);
	CallRemoteFunction("OnDGCreated", "i", Using_Dialog[playerid]);
	return 1;
}

stock HideDialog(playerid)
{
	if(DG_OPENED[playerid])
	{
		CancelSelectTextDraw(playerid);
		PlayerTextDrawHide(playerid, Box_Background[playerid]);
		PlayerTextDrawHide(playerid, close[playerid]);
		PlayerTextDrawHide(playerid, caption[playerid]);
		PlayerTextDrawHide(playerid, up_[playerid]);
		PlayerTextDrawHide(playerid, info[playerid]);
		PlayerTextDrawHide(playerid, left_[playerid]);
		PlayerTextDrawHide(playerid, right_[playerid]);
		PlayerTextDrawHide(playerid, down_[playerid]);
		PlayerTextDrawHide(playerid, button1[playerid]);
		PlayerTextDrawHide(playerid, button2[playerid]);
		DG_OPENED[playerid] = false;
	}
	return 1;
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(_:playertextid != INVALID_TEXT_DRAW)
    {
    	if(playertextid == close[playerid])
    	{
    		HideDialog(playerid);
    	}
    	else if(playertextid == button1[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iii", playerid, true, Using_Dialog[playerid]);
    	}
    	else if(playertextid == button2[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iii", playerid, false, Using_Dialog[playerid]);
    	}
    }
	return 1;
}
hook OnPlayerConnect(playerid)
{
	LoadTDPlayers(playerid);
	return 1;
}

/* Callbacks */
forward OnDGCreated(DG_ID);
forward OnPlayerDGResponse(playerid, response, DG_ID);
