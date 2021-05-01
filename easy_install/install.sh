#!/bin/bash

if [ $(whoami) = "root" ]
then
        make clean install
        cp layoutmenu.sh /usr/bin/layoutmenu
else
        echo "Sudo me!"
fi

if [ $(echo $?) = 0 ]
then
        echo "All done!"
else
        echo "Something went wrong..."
fi
