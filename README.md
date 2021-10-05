# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore
## mod-no-hearthstone-cooldown
### This is a module for [AzerothCore](http://www.azerothcore.org)

#### Features:
- It disables the Hearthstone cooldown

### This module currently requires:
- AzerothCore v4.0.0+

### How to install
1. Simply place the module under the `modules` folder of your AzerothCore source folder.
2. Re-run cmake and launch a clean build of AzerothCore

### (Optional) Edit module configuration
You can turn the module **on** and **off**, default it is **on**.
If you want to disable it, go to your server configuration folder (e.g. **etc**), copy `no-hearthstone-cooldown.conf.dist` to `no-hearthstone-cooldown.conf` and change 
`NoHearthstoneCooldown.Enable = 1`
to 
`NoHearthstoneCooldown.Enable = 0`

## Credits
* BytesGalore
* AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)
