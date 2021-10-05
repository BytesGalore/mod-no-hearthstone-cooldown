/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "Item.h"

// Add player scripts
class NoHearthstoneCooldown : public PlayerScript
{
public:
    NoHearthstoneCooldown(): PlayerScript("NoHearthstoneCooldown") {}

    bool OnBeforeTeleport(Player* player, uint32 /*mapid*/, float /*x*/, float /*y*/, float /*z*/, float /*orientation*/, uint32 /*options*/, Unit* /*target*/) override
    {
        auto* spell = player->FindCurrentSpellBySpellId(8690);
        if (spell)
        {
            player->RemoveSpellCooldown(8690, true);
            player->RemoveSpellCooldown(39937, true);
            player->SendClearCooldown(8690, player);
            player->SendClearCooldown(39937, player);
        }
        return true; 
    }

    void OnLogin(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("NoHearthstoneCooldown.Enable", false))
        {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00No Hearthstone cooldown|rmodule!");
            
            player->RemoveSpellCooldown(8690, true);
            player->RemoveSpellCooldown(39937, true);
            player->SendClearCooldown(8690, player);
            player->SendClearCooldown(39937, player);
        }

    }
};

// Add all scripts in one
void AddNoHearthstoneCooldownScripts()
{
    new NoHearthstoneCooldown();
}
