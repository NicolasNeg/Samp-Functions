#include <a_samp>
#include <YSI\y_hooks>

// Cash 
new PlayerText:cash_td[MAX_PLAYERS];
new Player_Cash[MAX_PLAYERS];
new bool:Cash_Show[MAX_PLAYERS];
#define MAX_CASH 99999999
#define MAX_CHAR_CASH 9

stock LoadTD(playerid)
{
	cash_td[playerid] = CreatePlayerTextDraw(playerid, 499.000000, 100.000000, "$00000000");
	PlayerTextDrawFont(playerid, cash_td[playerid], 3);
	PlayerTextDrawLetterSize(playerid, cash_td[playerid], 0.579165, 2.399998);
	PlayerTextDrawTextSize(playerid, cash_td[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, cash_td[playerid], 1);
	PlayerTextDrawSetShadow(playerid, cash_td[playerid], 0);
	PlayerTextDrawAlignment(playerid, cash_td[playerid], 1);
	PlayerTextDrawColor(playerid, cash_td[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, cash_td[playerid], 255);
	PlayerTextDrawBoxColor(playerid, cash_td[playerid], 50);
	PlayerTextDrawUseBox(playerid, cash_td[playerid], 0);
	PlayerTextDrawSetProportional(playerid, cash_td[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, cash_td[playerid], 0);
	return 1;
}

stock GetPlayerCash(playerid)
{
	return Player_Cash[playerid];
}

stock GivePlayerCash(playerid, money)
{
	if(money > MAX_CASH) return printf("Max cash limit (%d)", MAX_CASH);
	else
	{
		Player_Cash[playerid] += money;
		//
		new string[MAX_CHAR_CASH];
		format(string,sizeof(string),"$%i", GetPlayerCash(playerid));
		PlayerTextDrawSetString(playerid, cash_td[playerid], string);
		//
		CallRemoteFunction("OnPlayerCashUpdate", "ii", playerid, money);
	}
	return 1;
}

stock SetPlayerCash(playerid, money)
{
	if(money > MAX_CASH) return printf("Max cash limit (%d)", MAX_CASH);
	else
	{
		Player_Cash[playerid] = money;
		new string[MAX_CHAR_CASH];
		format(string,sizeof(string),"$%i", money);
		PlayerTextDrawSetString(playerid, cash_td[playerid], string);
	
		CallRemoteFunction("OnPlayerCashUpdate", "ii", playerid, money);
	}
	return 1;
}

stock IsCashShowed(playerid)
{
	return Cash_Show[playerid];
}

stock ResetCash(playerid)
{
	return Player_Cash[playerid] = 0;
}

stock HideCash(playerid)
{
	Cash_Show[playerid] = false;
	PlayerTextDrawHide(playerid, cash_td[playerid]);
	return 1;
}

stock ShowCash(playerid)
{
	Cash_Show[playerid] = true;
	PlayerTextDrawShow(playerid, cash_td[playerid]);
	return 1;
}

// Vehicles...
stock GetVehicleInfo(playerid)
{
	new vehicleid = GetVehicleModel(GetPlayerVehicleID(playerid));
	new Float:health;
	GetVehicleHealth(vehicleid, health);
	CallRemoteFunction("OnVehicleDamage", "iif", playerid, vehicleid, health);
}

stock IsPlayerInAnyInterior(playerid)
{
	if(GetPlayerInterior(playerid) == 0) return false;
	return true;
}

/* SetPlayerMoney */
stock SetPlayerMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	return 1;
}

// stock DebugLog(const text[]) crear archivo .txt con lo que quieras imprimir.
hook OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	GetVehicleInfo(playerid);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	LoadTD(playerid);
	return 1;
}

forward OnVehicleDamage(driver,vehicleid, Float:health);
forward OnPlayerCashUpdate(playerid, money);
