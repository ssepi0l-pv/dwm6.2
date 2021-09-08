#!/usr/bin/env bash
# remember to chmod +x this script!

echo "write your AUR helper (ie: yay, paru, etc) >> "; read AUR_HELPER
echo $AUR_HELPER

PACKAGES=$(sed -nE 6,19p REQUIREMENTS_SCRIPT)
#sudo pacman -S $PACKAGES

