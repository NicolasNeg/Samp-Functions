#include <a_samp>
#include <YSI\y_hooks>

#define DG_INVALID -1

enum 
{
	DG_STYLE_INVALID = -1,
	DG_STYLE_NONE = 0,
	DG_STYLE_MSGBOX,
	DG_STYLE_LIST
	//DG_STYLE_INPUT,
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
new PlayerText:listitem_01[MAX_PLAYERS];
new PlayerText:listitem_02[MAX_PLAYERS];
new PlayerText:listitem_03[MAX_PLAYERS];
new PlayerText:listitem_04[MAX_PLAYERS];


stock AddSpace(text[])
{
	new string[40];
	if(strval(text) > 30)
	{
		format(string,sizeof(string), "%s\n", text);
	}
	return string;
}
stock DetectObjectList(playerid, text[])
{
	new cout;
	for(new i; i<strlen(text); i++)
	{
		if(text[i] == '\n') 
			cout ++;
	}
	printf("Conteo: %d", cout);
	AddListObject(playerid, cout, text);
	return 1;
}
stock DetectNewList(operacion, const text[])
{
	new cout;
	for(new i; i<text[i]; i++)
	{
		cout ++;
		if(text[i] == '\n') 
		{
			if(operacion == 1)
			{
				cout -= 2;
				return cout;
			}
			else if(operacion == 2)
			{
				cout ++;
				return cout;
			}
		}
	}
	return 1;
}

stock AddListObject(playerid, listitem, text[])
{
	new main[100];
	strmid(main, text, DetectNewList(2, text), 100);
	if(listitem == 0)
	{
		new _01[30];
		strmid(_01, text, 0, 100);
		PlayerTextDrawSetString(playerid, listitem_01[playerid], _01);
		PlayerTextDrawShow(playerid, listitem_01[playerid]);
	}
	else if(listitem == 1)
	{
		new _01[30];
		strmid(_01, text, 0, DetectNewList(1, text));
		PlayerTextDrawSetString(playerid, listitem_01[playerid], _01);
		PlayerTextDrawSetString(playerid, listitem_02[playerid], main);
		PlayerTextDrawShow(playerid, listitem_01[playerid]);
		PlayerTextDrawShow(playerid, listitem_02[playerid]);
	}
	else if(listitem == 2)
	{
		new _01[30],_02[30],_03[30],main_[30];
		strmid(_01, text, 0, DetectNewList(1, text));
		PlayerTextDrawSetString(playerid, listitem_01[playerid], _01);
		strmid(main_, text, DetectNewList(2, text), 100);
		strmid(_02, main_, 0, DetectNewList(1, main_));
		PlayerTextDrawSetString(playerid, listitem_02[playerid], _02);
		strmid(_03, main, DetectNewList(2, main), 100);
		PlayerTextDrawSetString(playerid, listitem_03[playerid], _03);
		PlayerTextDrawShow(playerid, listitem_01[playerid]);
		PlayerTextDrawShow(playerid, listitem_02[playerid]);
		PlayerTextDrawShow(playerid, listitem_03[playerid]);
	}
	/*else if(listitem == 3)
	{
		new _01[30],_02[30],_03[30],main_[30],main_02[30],_04[30];
		strmid(_01, text, 0, DetectNewList(1, text));
		PlayerTextDrawSetString(playerid, listitem_01[playerid], _01);
		strmid(main_, text, DetectNewList(2, text), 100);
		strmid(_02, main_, 0, DetectNewList(1, main_));
		PlayerTextDrawSetString(playerid, listitem_02[playerid], _02);
		strmid(main_02, main, DetectNewList(2, main), 100);
		strmid(_03, main_02, 0, DetectNewList(2, main_02));
		PlayerTextDrawSetString(playerid, listitem_03[playerid], _03);
		strmid(_04, main, DetectNewList(2, main), 100);
		PlayerTextDrawSetString(playerid, listitem_04[playerid], _04);
		PlayerTextDrawShow(playerid, listitem_01[playerid]);
		PlayerTextDrawShow(playerid, listitem_02[playerid]);
		PlayerTextDrawShow(playerid, listitem_03[playerid]);
		PlayerTextDrawShow(playerid, listitem_04[playerid]);
	} */
	return 1;
}
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

	listitem_01[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 175.000000, "listitem...");
	PlayerTextDrawFont(playerid, listitem_01[playerid], 3);
	PlayerTextDrawLetterSize(playerid, listitem_01[playerid], 0.266667, 1.000000);
	PlayerTextDrawTextSize(playerid, listitem_01[playerid], 435.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, listitem_01[playerid], 1);
	PlayerTextDrawSetShadow(playerid, listitem_01[playerid], 0);
	PlayerTextDrawAlignment(playerid, listitem_01[playerid], 1);
	PlayerTextDrawColor(playerid, listitem_01[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, listitem_01[playerid], 255);
	PlayerTextDrawBoxColor(playerid, listitem_01[playerid], -16777166);
	PlayerTextDrawUseBox(playerid, listitem_01[playerid], 0);
	PlayerTextDrawSetProportional(playerid, listitem_01[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, listitem_01[playerid], 1);

	listitem_02[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 195.000000, "listitem...");
	PlayerTextDrawFont(playerid, listitem_02[playerid], 3);
	PlayerTextDrawLetterSize(playerid, listitem_02[playerid], 0.266667, 1.000000);
	PlayerTextDrawTextSize(playerid, listitem_02[playerid], 435.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, listitem_02[playerid], 1);
	PlayerTextDrawSetShadow(playerid, listitem_02[playerid], 0);
	PlayerTextDrawAlignment(playerid, listitem_02[playerid], 1);
	PlayerTextDrawColor(playerid, listitem_02[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, listitem_02[playerid], 255);
	PlayerTextDrawBoxColor(playerid, listitem_02[playerid], -16777166);
	PlayerTextDrawUseBox(playerid, listitem_02[playerid], 0);
	PlayerTextDrawSetProportional(playerid, listitem_02[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, listitem_02[playerid], 1);

	listitem_03[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 216.000000, "listitem...");
	PlayerTextDrawFont(playerid, listitem_03[playerid], 3);
	PlayerTextDrawLetterSize(playerid, listitem_03[playerid], 0.266667, 1.000000);
	PlayerTextDrawTextSize(playerid, listitem_03[playerid], 435.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, listitem_03[playerid], 1);
	PlayerTextDrawSetShadow(playerid, listitem_03[playerid], 0);
	PlayerTextDrawAlignment(playerid, listitem_03[playerid], 1);
	PlayerTextDrawColor(playerid, listitem_03[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, listitem_03[playerid], 255);
	PlayerTextDrawBoxColor(playerid, listitem_03[playerid], -16777166);
	PlayerTextDrawUseBox(playerid, listitem_03[playerid], 0);
	PlayerTextDrawSetProportional(playerid, listitem_03[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, listitem_03[playerid], 1);

	listitem_04[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 239.000000, "listitem...");
	PlayerTextDrawFont(playerid, listitem_04[playerid], 3);
	PlayerTextDrawLetterSize(playerid, listitem_04[playerid], 0.266667, 1.000000);
	PlayerTextDrawTextSize(playerid, listitem_04[playerid], 435.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, listitem_04[playerid], 1);
	PlayerTextDrawSetShadow(playerid, listitem_04[playerid], 0);
	PlayerTextDrawAlignment(playerid, listitem_04[playerid], 1);
	PlayerTextDrawColor(playerid, listitem_04[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, listitem_04[playerid], 255);
	PlayerTextDrawBoxColor(playerid, listitem_04[playerid], -16777166);
	PlayerTextDrawUseBox(playerid, listitem_04[playerid], 0);
	PlayerTextDrawSetProportional(playerid, listitem_04[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, listitem_04[playerid], 1);
	return 1;
}

CloseDialog(playerid)
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
		PlayerTextDrawHide(playerid, listitem_01[playerid]);
		PlayerTextDrawHide(playerid, listitem_02[playerid]);
		PlayerTextDrawHide(playerid, listitem_03[playerid]);
		PlayerTextDrawHide(playerid, listitem_04[playerid]);
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
    		CloseDialog(playerid);
    	}
		else if(playertextid == listitem_01[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], true, 1);
    	}
		else if(playertextid == listitem_02[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], true, 2);
    	}
		else if(playertextid == listitem_03[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], true, 3);
    	}
		else if(playertextid == listitem_04[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], true, 4);
    	}
    	else if(playertextid == button1[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], true);
    	}
    	else if(playertextid == button2[playerid])
    	{
    		CallRemoteFunction("OnPlayerDGResponse", "iiii", playerid, Using_Dialog[playerid], false);
    	}
    }
    else CloseDialog(playerid);
	return 1;
}
hook OnPlayerConnect(playerid)
{
	LoadTDPlayers(playerid);
	return 1;
}

CreateDialog(playerid, DIALOG_ID, DG_STYLE, DIALOG_CAPTION[], DIALOG_INFO[], DIALOG_BTN1[], DIALOG_BTN2[])
{
	if(DG_OPENED[playerid]) return SendClientMessage(playerid, -1, "You are with a DG opened");
	switch(DG_STYLE)
	{
		case DG_STYLE_MSGBOX:
		{
			DG_OPENED[playerid] = true;
			AddSpace(DIALOG_INFO);
			Using_Dialog[playerid] = DIALOG_ID;
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
		}
		case DG_STYLE_LIST:
		{
			DG_OPENED[playerid] = true;
			Using_Dialog[playerid] = DIALOG_ID;
			DetectObjectList(playerid, DIALOG_INFO);
			SelectTextDraw(playerid, 0xFF0000FF);
			PlayerTextDrawSetString(playerid, caption[playerid], DIALOG_CAPTION);
			PlayerTextDrawSetString(playerid, button1[playerid], DIALOG_BTN1);
			PlayerTextDrawSetString(playerid, button2[playerid], DIALOG_BTN2);
			PlayerTextDrawShow(playerid, Box_Background[playerid]);
			PlayerTextDrawShow(playerid, close[playerid]);
			PlayerTextDrawShow(playerid, caption[playerid]);
			PlayerTextDrawShow(playerid, up_[playerid]);
			PlayerTextDrawShow(playerid, left_[playerid]);
			PlayerTextDrawShow(playerid, right_[playerid]);
			PlayerTextDrawShow(playerid, down_[playerid]);
			PlayerTextDrawShow(playerid, button1[playerid]);
			PlayerTextDrawShow(playerid, button2[playerid]);
		}
	}
	return 1;
}

forward OnDGCreated(DG_ID);
forward OnPlayerDGResponse(playerid, DG_ID, response, listitem);