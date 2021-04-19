/*

SEX MODULE

If you want sex in samp, you need this!
Use Pawn.CMD BECAUSE PAWN.CMD CHAD!!111

Creds: Artic.

*/

#include <a_samp>
#include <Pawn.CMD>

#define ROLE_ACTIVE 1
#define ROLE_PASIVE 2

// ———— ENUMS
enum enum_sex
{
	// — status per player
	bool:sex_sexing,			// — in sex
	sex_requesting,				// — request sex :smirk:
	sex_with,					// — playerid in sex time
	sex_role,					// — pasive or active role
	sex_cum,					// — cum cant
	Float:sex_process, 			// — process to cum
}
new player_sex[MAX_PLAYERS][enum_sex];

// ———— PUBLIC CALLBACKS
public OnPlayerConnect(playerid)
{

	// —— Clear vars
	new 
		temp_sex[enum_sex]
	;
	player_sex[playerid] = temp_sex;
	// — desbug.
	player_sex[playerid][sex_with] = INVALID_PLAYER_ID;
	player_sex[playerid][sex_requesting] = INVALID_PLAYER_ID;
	
	#if defined Sex_OnPlayerConnect
		return Sex_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect Sex_OnPlayerConnect
#if defined Sex_OnPlayerConnect
	forward Sex_OnPlayerConnect(playerid);
#endif

#if defined PAWNCMD_INC_

CMD:sex(playerid, params[])
{
	if (!params[0])
		return SendClientMessage(playerid, 0xC0C0C0FF, "You need to specify a valid playerid.");

	if (!IsPlayerConnected(params[0]))
		return SendClientMessage(playerid, 0xC0C0C0FF, "Invalid playerid.");

	if (player_sex[params[0]][sex_sexing])
		return SendClientMessage(playerid, 0xC0C0C0FF, "Specified player is already fucking :sob:");

	player_sex[params[0]][sex_requesting] = playerid;

	SendClientMessage(playerid, 0x9D2121FF, "Now you need to wait until player response.");

	new str_request[90];
	format(str_request, sizeof str_request, "Hey! %d wants to fuck you. (/deny - /acept)", playerid);
	SendClientMessage(params[0], -1, str_request);
	return 1;
}

CMD:accept(playerid)
{
	if (!IsPlayerConnected(player_sex[playerid][sex_requesting]))
		return SendClientMessage(playerid, -1, "Nobody wants to fuck you...");

	new sex_friend = player_sex[playerid][sex_requesting];
	SendClientMessage(playerid, -1, "welcome to the sex bro");
	SendClientMessage(sex_friend, -1, "welcome to the sex bro");

	SetSexRoles(playerid, sex_friend);

	return 1;
}

#endif	

stock SetSexRoles(playerid, fucktime)
{	
	new sexxx = random(2) + 1;
	player_sex[playerid][sex_role] = sexxx;
	player_sex[fucktime][sex_role] = (sexxx == ROLE_ACTIVE) ? (ROLE_PASIVE) : (ROLE_ACTIVE);

	new str[35];
	format(str, sizeof str, "hehe you´re %s", (sexxx == ROLE_ACTIVE) ? ("active") : ("pasive :flushed:"));
	SendClientMessage(playerid, -1, str);
	str[0] = EOS;
	format(str, sizeof str, "hehe you´re %s", (sexxx == ROLE_ACTIVE) ? ("pasive :flushed:") : ("active"));
	SendClientMessage(fucktime, -1, str);
	return 1;
}