# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore
## mod-no-hearthstone-cooldown
### This is a module for [AzerothCore](http://www.azerothcore.org)

# Module info

- Name: No Hearthstone cooldown
- Author: BytesGalore
- Module:
  + Repository: https://github.com/BytesGalore/mod-no-hearthstone-cooldown
  + Download: https://github.com/BytesGalore/mod-no-hearthstone-cooldown/archive/refs/heads/main.zip
- License: AGPL

# Module integration

- **AzerothCore hash/commit compliance:** [5af98783](https://github.com/azerothcore/azerothcore-wotlk/commit/5af98783c9f61f059914b3304bb26785502a6924)
- Includes configuration (.conf)?: Yes, copied by CMake
- Includes SQL patches?: No
- Core hooks used:
    + PlayerScript: OnLogin
    + PlayerScript: OnBeforeTeleport
    + WorldScript: OnAfterConfigLoad

# Description
A module that simply skips the cooldown of the Hearthstone
#### Features:
- It resets the Hearthstone cooldown immediately

### This module currently requires:
- AzerothCore v4.0.0+

### How to install
1. Simply place the module under the `modules` folder of your AzerothCore source folder.
2. Re-run cmake and launch a clean build of AzerothCore
3. that's all

### (Optional) Edit module configuration
- You can turn the module **on** and **off**, default it is **on**
- You can also turn the announcement of the module on player-login **on** and **off**, default it is **on**
- If you want change the settings, go to your server configuration folder (e.g. **etc**), copy `mod_no_hearthstone_cooldown.conf.dist` to `mod_no_hearthstone_cooldown.conf` and edit the settings

## Credits
* [BytesGalore](https://github.com/BytesGalore) (author of the module)
* AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)
