/*
    include Verificacao Plataforma

    Esse include foi inicialmente criado pelo Jekmant, e ultimamente tem sido difícil
    encontrá-lo na internet. Então, decidi fazer melhorias e disponibilizá-lo para 
    vocês.

    © [2024] [Calasans]. Todos os direitos reservados.

    Discord: ocalasans
    Youtube: Calasans
    Instagram: ocalasans

    SA:MP Programming Comunnity©: https://abre.ai/samp-spc
*/

#if defined _verificacao_plataforma
    #undef _verificacao_plataforma
#endif
//
#if defined _verificacao_plataform_included
    #endinput
#endif
#define _verificacao_plataform_included
//
#if !defined _samp_included || !defined _INC_open_mp
    #error "A biblioteca `a_samp` ou `open.mp` nao foi ativada. Por favor, ative-a no inicio do seu Gamemode, Ex: `#include <a_samp>`"
#endif
//
#if !defined PAWNRAKNET_INC_
    #error "A biblioteca `Pawn.RakNet` nao foi ativada. Por favor, ative-a no seu Gamemode, Ex: `#include <Pawn.RakNet>`"
#endif
//
#if !defined gpci && !defined _INC_open_mp
    native gpci(playerid, buffer[], size = sizeof(buffer));
#endif

/*
$$$$$$$\             $$$$$$\  $$\           $$\                                               $$\       $$$$$$$\             $$$$$$\  $$\           $$\   $$\     $$\                               
$$  __$$\           $$  __$$\ \__|          \__|                                              $$ |      $$  __$$\           $$  __$$\ \__|          \__|  $$ |    \__|                              
$$ |  $$ | $$$$$$\  $$ /  \__|$$\ $$$$$$$\  $$\  $$$$$$$\  $$$$$$\   $$$$$$\   $$$$$$$\       $$ |      $$ |  $$ | $$$$$$\  $$ /  \__|$$\ $$$$$$$\  $$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
$$ |  $$ |$$  __$$\ $$$$\     $$ |$$  __$$\ $$ |$$  _____|$$  __$$\ $$  __$$\ $$  _____|      \__|      $$ |  $$ |$$  __$$\ $$$$\     $$ |$$  __$$\ $$ |\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$ |  $$ |$$$$$$$$ |$$  _|    $$ |$$ |  $$ |$$ |$$ /      $$ /  $$ |$$$$$$$$ |\$$$$$$\        $$\       $$ |  $$ |$$$$$$$$ |$$  _|    $$ |$$ |  $$ |$$ |  $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |  $$ |$$   ____|$$ |      $$ |$$ |  $$ |$$ |$$ |      $$ |  $$ |$$   ____| \____$$\       $$ |      $$ |  $$ |$$   ____|$$ |      $$ |$$ |  $$ |$$ |  $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
$$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ |  $$ |$$ |\$$$$$$$\ \$$$$$$  |\$$$$$$$\ $$$$$$$  |      $$ |      $$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ |  $$ |$$ |  \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\_______/  \_______|\__|      \__|\__|  \__|\__| \_______| \______/  \_______|\_______/       \__|      \_______/  \_______|\__|      \__|\__|  \__|\__|   \____/ \__| \______/ \__|  \__|\_______/ 
*/

#define VPI_tamanho_pacote 3
#define VPI_chave_android "ED40ED0E8089CC44C08EE9580F4C8C44EE8EE990"

/*
$$\    $$\                    $$\                               $$\                 $$\       $$\    $$\                    $$\           $$\       $$\                     
$$ |   $$ |                   \__|                              \__|                $$ |      $$ |   $$ |                   \__|          $$ |      $$ |                    
$$ |   $$ |$$$$$$\   $$$$$$\  $$\  $$$$$$\ $$\    $$\  $$$$$$\  $$\  $$$$$$$\       $$ |      $$ |   $$ |$$$$$$\   $$$$$$\  $$\  $$$$$$\  $$$$$$$\  $$ | $$$$$$\   $$$$$$$\ 
\$$\  $$  |\____$$\ $$  __$$\ $$ | \____$$\\$$\  $$  |$$  __$$\ $$ |$$  _____|      \__|      \$$\  $$  |\____$$\ $$  __$$\ $$ | \____$$\ $$  __$$\ $$ |$$  __$$\ $$  _____|
 \$$\$$  / $$$$$$$ |$$ |  \__|$$ | $$$$$$$ |\$$\$$  / $$$$$$$$ |$$ |\$$$$$$\        $$\        \$$\$$  / $$$$$$$ |$$ |  \__|$$ | $$$$$$$ |$$ |  $$ |$$ |$$$$$$$$ |\$$$$$$\  
  \$$$  / $$  __$$ |$$ |      $$ |$$  __$$ | \$$$  /  $$   ____|$$ | \____$$\       $$ |        \$$$  / $$  __$$ |$$ |      $$ |$$  __$$ |$$ |  $$ |$$ |$$   ____| \____$$\ 
   \$  /  \$$$$$$$ |$$ |      $$ |\$$$$$$$ |  \$  /   \$$$$$$$\ $$ |$$$$$$$  |      $$ |         \$  /  \$$$$$$$ |$$ |      $$ |\$$$$$$$ |$$$$$$$  |$$ |\$$$$$$$\ $$$$$$$  |
    \_/    \_______|\__|      \__| \_______|   \_/     \_______|\__|\_______/       \__|          \_/    \_______|\__|      \__| \_______|\_______/ \__| \_______|\_______/ 
*/

const VPI_sincronizacao_pers = 221;
const VPI_iniciar_android = 0x10;

enum enum_player_android {
    bool:VPI_Android,
    bool:VPI_Mira_Automatica
}
static VPI_player_android[MAX_PLAYERS][enum_player_android];

/*
 $$$$$$\              $$\                                         $$\        $$$$$$\    $$\     $$\                                     
$$  __$$\             $$ |                                        $$ |      $$  __$$\   $$ |    $$ |                                    
$$ /  $$ |$$\   $$\ $$$$$$\    $$$$$$\   $$$$$$\   $$$$$$$\       $$ |      $$ /  $$ |$$$$$$\   $$$$$$$\   $$$$$$\   $$$$$$\   $$$$$$$\ 
$$ |  $$ |$$ |  $$ |\_$$  _|  $$  __$$\ $$  __$$\ $$  _____|      \__|      $$ |  $$ |\_$$  _|  $$  __$$\ $$  __$$\ $$  __$$\ $$  _____|
$$ |  $$ |$$ |  $$ |  $$ |    $$ |  \__|$$ /  $$ |\$$$$$$\        $$\       $$ |  $$ |  $$ |    $$ |  $$ |$$$$$$$$ |$$ |  \__|\$$$$$$\  
$$ |  $$ |$$ |  $$ |  $$ |$$\ $$ |      $$ |  $$ | \____$$\       $$ |      $$ |  $$ |  $$ |$$\ $$ |  $$ |$$   ____|$$ |       \____$$\ 
 $$$$$$  |\$$$$$$  |  \$$$$  |$$ |      \$$$$$$  |$$$$$$$  |      $$ |       $$$$$$  |  \$$$$  |$$ |  $$ |\$$$$$$$\ $$ |      $$$$$$$  |
 \______/  \______/    \____/ \__|       \______/ \_______/       \__|       \______/    \____/ \__|  \__| \_______|\__|      \_______/ 
*/

public OnGameModeInit()
{
    print(" ");
    print("__________________________________________________________________");
    print("||==============================================================||");
    print("||                                                              ||");
    print("||            Verificar Plataforma | Check Platform             ||");
    print("||                                                              ||");
    print("||             8b           d8         88888888ba               ||");
    print("||             `8b         d8'         88      `8b              ||");
    print("||              `8b       d8'          88      ,8P              ||");
    print("||               `8b     d8'           88aaaaaa8P'              ||");
    print("||                `8b   d8'  aaaaaaaa  88=======                ||");
    print("||                 `8b d8'   ========  88                       ||");
    print("||                  `888'              88                       ||");
    print("||                   `8'               88                       ||");
    print("||                                                              ||");
    print("||                                                              ||");
    print("||                                                              ||");
    print("||                         By: Jekmant                          ||");
    print("||                      Updated: Calasans                       ||");
    print("||                  Discord: abre.ai/samp-spc                   ||");
    print("||                                                              ||");
    print("||==============================================================||");
    print("__________________________________________________________________");
    print(" ");
    //
    #if defined VPI_print_gamemodeinit
        return VPI_print_gamemodeinit();
    #else
        return true;
    #endif
}

public OnPlayerConnect(playerid)
{
    new VPI_string[64];
    //
    #if defined gpci && !defined _INC_open_mp
    gpci(playerid, VPI_string, sizeof VPI_string);
    #endif
    //
    #if defined _INC_open_mp
    GPCI(playerid, VPI_string, sizeof VPI_string);
    #endif
    //
    if(!strcmp(VPI_string, VPI_chave_android))
        VPI_player_android[playerid][VPI_Android] = true;
    //
    else
        VPI_player_android[playerid][VPI_Android] = false;
    //
    #if defined VPI_playerconnect
        return VPI_playerconnect(playerid);
    #else
        return true;
    #endif
}

public OnPlayerDisconnect(playerid, reason)
{
    VPI_player_android[playerid][VPI_Android] = false;
    VPI_player_android[playerid][VPI_Mira_Automatica] = false;
    //
    #if defined VPI_playerdisconnect
        return VPI_playerdisconnect(playerid, reason);
    #else
        return true;
    #endif
}

IRawPacket:VPI_sincronizacao_pers(playerid, BitStream:bs)
{
    new bytes, rpcid;
    //
    BS_GetNumberOfBytesUsed(bs, bytes);
    //
    if(bytes < VPI_tamanho_pacote)
        return false;
    //
    BS_ReadValue(bs, PR_IGNORE_BITS, 8, PR_UINT8, rpcid);
    //
    if(rpcid == VPI_iniciar_android)
    {
        new autoaim;
        //
        BS_ReadValue(bs, PR_UINT8, autoaim);
        //
        VPI_player_android[playerid][VPI_Android] = true;
        VPI_player_android[playerid][VPI_Mira_Automatica] = bool:autoaim;
    }
    return true;
}

/*
$$$$$$$$\                                                                $$\       $$$$$$$$\                              $$\     $$\                               
$$  _____|                                                               $$ |      $$  _____|                             $$ |    \__|                              
$$ |   $$\   $$\ $$$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\   $$$$$$$\       $$ |      $$ |   $$\   $$\ $$$$$$$\   $$$$$$$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
$$$$$\ $$ |  $$ |$$  __$$\ $$  _____|$$  __$$\ $$  __$$\ $$  _____|      \__|      $$$$$\ $$ |  $$ |$$  __$$\ $$  _____|\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$  __|$$ |  $$ |$$ |  $$ |$$ /      $$ /  $$ |$$$$$$$$ |\$$$$$$\        $$\       $$  __|$$ |  $$ |$$ |  $$ |$$ /        $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |   $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$   ____| \____$$\       $$ |      $$ |   $$ |  $$ |$$ |  $$ |$$ |        $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
$$ |   \$$$$$$  |$$ |  $$ |\$$$$$$$\ \$$$$$$  |\$$$$$$$\ $$$$$$$  |      $$ |      $$ |   \$$$$$$  |$$ |  $$ |\$$$$$$$\   \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\__|    \______/ \__|  \__| \_______| \______/  \_______|\_______/       \__|      \__|    \______/ \__|  \__| \_______|   \____/ \__| \______/ \__|  \__|\_______/ 
*/

stock GetPlayerPlataformInfo(playerid, &bool:mobile, &bool:aimlock) {
    mobile = VPI_player_android[playerid][VPI_Android];
    aimlock = VPI_player_android[playerid][VPI_Mira_Automatica];
}

/*
 $$$$$$\    $$\     $$\                                 $$$$$$$\             $$$$$$\  $$\           $$\   $$\     $$\                               
$$  __$$\   $$ |    $$ |                                $$  __$$\           $$  __$$\ \__|          \__|  $$ |    \__|                              
$$ /  $$ |$$$$$$\   $$$$$$$\   $$$$$$\   $$$$$$\        $$ |  $$ | $$$$$$\  $$ /  \__|$$\ $$$$$$$\  $$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
$$ |  $$ |\_$$  _|  $$  __$$\ $$  __$$\ $$  __$$\       $$ |  $$ |$$  __$$\ $$$$\     $$ |$$  __$$\ $$ |\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$ |  $$ |  $$ |    $$ |  $$ |$$$$$$$$ |$$ |  \__|      $$ |  $$ |$$$$$$$$ |$$  _|    $$ |$$ |  $$ |$$ |  $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |  $$ |  $$ |$$\ $$ |  $$ |$$   ____|$$ |            $$ |  $$ |$$   ____|$$ |      $$ |$$ |  $$ |$$ |  $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
 $$$$$$  |  \$$$$  |$$ |  $$ |\$$$$$$$\ $$ |            $$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ |  $$ |$$ |  \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
 \______/    \____/ \__|  \__| \_______|\__|            \_______/  \_______|\__|      \__|\__|  \__|\__|   \____/ \__| \______/ \__|  \__|\_______/ 
*/

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit VPI_print_gamemodeinit
#if defined VPI_print_gamemodeinit
    forward VPI_print_gamemodeinit();
#endif
//
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect VPI_playerconnect
#if defined VPI_playerconnect
    forward VPI_playerconnect(playerid);
#endif
//
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect VPI_playerdisconnect
#if defined VPI_playerdisconnect
    forward VPI_playerdisconnect(playerid, reason);
#endif
