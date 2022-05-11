#!/usr/bin/env bash
# remember to chmod +x this script!

echo "write your AUR helper (ie: yay, paru, etc) >> "; read AUR_HELPER

PACKAGES=$(sed -n 6,19p REQUIREMENTS_SCRIPT)
sudo pacman -S $PACKAGES
AUR_PACKAGES=$(sed -n 22,27p REQUIREMENTS_SCRIPT)
$AUR_HELPER -S $AUR_PACKAGES

rm -f dwm.h config.h
cp -u layoutmenu.sh $HOME/.local/bin/
sudo make clean install

GOOD_INSTALL=$(echo $?)

if GOOD_INSTALL == 0: then
        echo -E "                     _       _
                            (_)     | |
         ___ ___  ___  _ __  _  ___ | |______ _ ____   __
         / __/ __|/ _ \ '_ \| |/ _ \| |______| '_ \ \ / /
         \__ \__ \  __/ |_) | | (_) | |      | |_) \ V /
         |___/___/\___| .__/|_|\___/|_|      | .__/ \_/
                      | |                    | |
                      |_|                    |_|

        "
else
        echo "something went wrong..."
