#/bin/bash

gnome-terminal --window -t ZAPPY_SERVER          -- ./zappy_server -p 4242 -x 10 -y 10 -n team1 team2 team3 -c 10 -f 1
gnome-terminal --window -t ZAPPY_GUI    -- ./zappy_gui -h 127.0.0.1 -p 4242