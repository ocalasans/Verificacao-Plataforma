//Esta include foi feita inicialmente por Jekmant.

/*
        Include atualizado & otimizado por Walkerxinho7.

        Discord: walkerxinho7 ou Walkerxinho7#9124
        Youtube: Walkerxinho
        Instagram: ocalasans
*/

#include <a_samp>
#include <Pawn.RakNet>

#if defined _IdentificarPlataforma_included
	#endinput
#endif
#define _IdentificarPlataforma_included

#if !defined gpci
    native gpci(playerid, buffer[], size = sizeof(buffer));
#endif

//Não mexa em nada aqui
#define TAMANHO_PACOTE     3
#define CHAVE_ANDROID     "ED40ED0E8089CC44C08EE9580F4C8C44EE8EE990"
const ID_SINCRONIZACAO_PERS = 221;
const WK7_INICIAR_ANDROID = 0x10;

enum PlayerAndroid
{
    bool:TaNoAndroid,
    bool:MiraAutomatica
}
new PlayerAndroidInfo[MAX_PLAYERS][PlayerAndroid];
//
public OnPlayerConnect(playerid)
{
    new string[64];
	gpci(playerid, string, sizeof string);
    if(!strcmp(string, CHAVE_ANDROID))
		PlayerAndroidInfo[playerid][TaNoAndroid] = true;
	else
		PlayerAndroidInfo[playerid][TaNoAndroid] = false;

    #if defined mob_OnPlayerConnect
		return mob_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect mob_OnPlayerConnect
#if defined mob_OnPlayerConnect
	forward mob_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
    PlayerAndroidInfo[playerid][TaNoAndroid] = false;
    PlayerAndroidInfo[playerid][MiraAutomatica] = false;

    #if defined mob_OnPlayerDisconnect
		return mob_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect mob_OnPlayerDisconnect
#if defined mob_OnPlayerDisconnect
	forward mob_OnPlayerDisconnect(playerid, reason);
#endif

IRawPacket:ID_SINCRONIZACAO_PERS(playerid, BitStream:bs)
{
	new bytes, rpcid;
	BS_GetNumberOfBytesUsed(bs, bytes);
	if(bytes < TAMANHO_PACOTE) return 0;

	BS_ReadValue(bs, 
		PR_IGNORE_BITS, 8,
		PR_UINT8, rpcid);

	if(rpcid == WK7_INICIAR_ANDROID)
	{
		new autoaim;
		BS_ReadValue(bs, PR_UINT8, autoaim);

        PlayerAndroidInfo[playerid][TaNoAndroid] = true;
		PlayerAndroidInfo[playerid][MiraAutomatica] = bool:autoaim;
	}
	return 1;
}
stock bool:IsPlayerAndroid(playerid)
{
    return PlayerAndroidInfo[playerid][TaNoAndroid];
}
stock bool:IsPlayerHaveAutoaim(playerid)
{
    return PlayerAndroidInfo[playerid][MiraAutomatica];
}
//fim
