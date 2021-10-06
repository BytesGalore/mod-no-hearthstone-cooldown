/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

// Add player scripts
class NoHearthstoneCooldown : public PlayerScript, public WorldScript
{
public:
    NoHearthstoneCooldown(): PlayerScript("NoHearthstoneCooldown"), WorldScript("NoHearthstoneCooldown") {}

    bool OnBeforeTeleport(Player* player, uint32 /*mapid*/, float /*x*/, float /*y*/, float /*z*/, float /*orientation*/, uint32 /*options*/, Unit* /*target*/) override
    {
        ClearHearthstoneCooldown(player);
        return true; 
    }

    void OnLogin(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("NoHearthstoneCooldown.Announce", true))
        {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00No Hearthstone cooldown|r module.");
        }
        ClearHearthstoneCooldown(player);
    }

    void OnAfterConfigLoad(bool /*reload*/) override 
    { 
        m_bNHCModuleEnabled = sConfigMgr->GetOption<bool>("NoHearthstoneCooldown.Enable", true);
    }

private:
    void ClearHearthstoneCooldown(Player* player)
    {
        if (m_bNHCModuleEnabled)
        {
            // only clear the cooldown if the player actually casted the Hearthstone spell
            if (player->FindCurrentSpellBySpellId(m_nSpellIDHearthstone))
            {
                // we remove the cooldown from the list of the player current cooldowns
                player->RemoveSpellCooldown(m_nSpellIDHearthstone, true);
                player->RemoveSpellCooldown(m_nSpellIDNoPlaceLikeHome, true);
                // then we clear the cooldown and send an update to the player client 
                player->SendClearCooldown(m_nSpellIDHearthstone, player);
                player->SendClearCooldown(m_nSpellIDNoPlaceLikeHome, player);
            }
        }
    }

    bool m_bNHCModuleEnabled = false;
    // https://www.wowhead.com/spell=8690/hearthstone
    const uint32 m_nSpellIDHearthstone = 8690;
    // https://tbc.wowhead.com/spell=39937/theres-no-place-like-home
    const uint32 m_nSpellIDNoPlaceLikeHome = 39937;
};

// Add all scripts in one
void AddNoHearthstoneCooldownScripts()
{
    new NoHearthstoneCooldown();
}
