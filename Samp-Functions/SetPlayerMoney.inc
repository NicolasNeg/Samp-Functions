#include <a_samp>
#include <YSI\y_hooks>



/* SetPlayerMoney */
stock SetPlayerMoney(playerid, money)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);
	return 1;
}