#!/bin/sh

if [ $(whoami) = "root" ]
then
        make clean install
else
        echo "sudo me!"
fi
if [ $(echo $?) = 0 ]
then
	echo "all done."
else
	echo "something went wrong..."	
fi
