#!/bin/sh

if [ $(whoami) = "root" ]
then
        rm config.h
        make clean install
else
        echo "sudo me!"
fi
