#! /bin/bash

gnome-terminal -e "bash -ic \"bash prog1.sh;exec bash\""
gnome-terminal -e "bash -ic \"bash prog2.sh;exec bash\""
gnome-terminal -e "bash -ic \"bash prog3.sh;exec bash\""
