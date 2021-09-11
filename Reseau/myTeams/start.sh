#!/bin/bash

function no_ctrlc() {
    echo "Redémarrage annulé !"
    exit
}

until ./myteams_server 2340 2>> server.log; do
    echo "Server crashed with exit code $?. Respawning in 6 seconde" >> crash.log
    trap no_ctrlc INT
    sleep 6
done