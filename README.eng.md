## Include VerificacaoPlataforma SA:MP

This is a code snippet designed to check whether the player is using a `mobile` or a `computer`. Read the categories below to stay informed.

-----------------------

### How to install?

You should download the include. After doing so, you need to place the include in the folder (pawno > include). Once you have done that, open the pwn file of your Gamemode and insert the following code below your other includes:
```pawn
#include <VerificacaoPlataforma>
```

-----------------------

### Required include

* [Pawn.RakNet](https://github.com/katursis/Pawn.RakNet).

> [!WARNING]
> If the user has not activated the [Pawn.RakNet](https://github.com/katursis/Pawn.RakNet) library, they will receive an error number `111`.

-----------------------

### How does it work?

Once the player connects to the server, the include automatically checks which platform they are using, whether it's `mobile` or `computer`, with the assistance of [Pawn.RakNet](https://github.com/katursis/Pawn.RakNet). To verify the player's platform, simply use the boolean function `IsPlayerPlataform`. Below are some examples:

With the `if`:
```pawn
CMD:platform(playerid)
{
    if(IsPlayerPlataform(playerid))
        SendClientMessage(playerid, 0xFFFFFFFF, "You are connected via the Mobile platform.");
    //
    else if(!IsPlayerPlataform(playerid)) // Could be just else.
        SendClientMessage(playerid, 0xFFFFFFFF, "You are connected via the Computer platform.");
    //
    return true;
}
```

Without the `if`:
```pawn
CMD:platform(playerid)
{
    new string[128];
    //
    format(string, sizeof(string), "You are connected via the %s platform.", IsPlayerPlataform(playerid) ? ("Mobile") : ("Computer"));
    SendClientMessage(playerid, 0xFFFFFFFF, string);
    //
    return true;
}
```

-----------------------

This include also has a function called `IsPlayerHaveAutoAim`. This function is designed to check whether the player has automatic aiming enabled or if it is without automatic aiming, commonly known as `LockOn`. Below are some examples:

With the `if`:
```pawn
CMD:aim(playerid)
{
    if(IsPlayerHaveAutoAim(playerid))
        SendClientMessage(playerid, 0xFFFFFFFF, "Your auto-aim is Enabled.");
    //
    else if(!IsPlayerHaveAutoAim(playerid)) // Could be just else.
        SendClientMessage(playerid, 0xFFFFFFFF, "Your auto-aim is Disabled.");
    //
    return true;
}
```

Without the `if`:
```pawn
CMD:aim(playerid)
{
    new string[128];
    //
    format(string, sizeof(string), "Your auto-aim is %s.", IsPlayerHaveAutoAim(playerid) ? ("Enabled") : ("Disabled"));
    SendClientMessage(playerid, 0xFFFFFFFF, string);
    //
    return true;
}
```

-----------------------

### Contact Information

Instagram: [ocalasans](https://instagram.com/ocalasans)   
YouTube: [Calasans](https://www.youtube.com/@ocalasans)   
Discord: ocalasans   
Community: [SA:MP Programming Community©](https://abre.ai/samp-spc)
