#include <a_samp>
#include <YSI\y_hooks>

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

hook OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	GetVehicleInfo(playerid);
	return 1;
}



forward OnVehicleDamage(driver,vehicleid, Float:health);