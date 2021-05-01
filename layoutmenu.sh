#!/bin/bash

# Not working ATM. Shows layouts until Tamami layout.

cat <<EOF | xmenu
[]= Tiled Layout	0
><> Floating Layout	1
[M] Monocle Layout	2
[@] Fibonacci Layout	3
[\\] Dwindle Layout	4
|M| Centered Layout	5
>M> Center Fl Layout	6
|+| Tatami Layout	7
EOF
