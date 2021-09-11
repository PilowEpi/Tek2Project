#!/bin/bash

## Bin check

if [ -e ./myteams_cli ]; then
    echo -e "Client Ok : Ready for Test"
else
    echo -e "Client not found; Please make the client binary"; exit 84
fi

if [ -e ./myteams_server ]; then
    echo -e "Server Ok : Ready for Test"
else
    echo -e "Server not found; Please make the client Server"; exit 84
fi

verify () {
    if [ "$1" = "$2" ]; then
        echo -e "$3 :\e[92m OK\e[0m"
    else
        echo -e "$3 :\e[91m FAILED\e[0m"
    fi
}

verifyReturn () {
    if [ $1 -eq $2 ]; then
        echo -e "$3 :\e[92m OK\e[0m"
    else
        FILES=$(cat -e $5)
        echo -e "\n$3 :\e[91m FAILED\e[0m\n"
        echo -e "\e[93mgrep failed : \e[0m\"$4\""
        echo -e "\e[93mfile : \e[0m\"$FILES\""
        kill $SERVER_PID

        rm -f ./data/users.dat
        rm -f ./data/teams.dat
        exit 84
    fi
}

grepUUIDby() {
    UUID=$(grep $1 ./tests/functionnal/log_server.log | cut -d '(' -f 2 | cut -d ')' -f 1)
    echo $UUID
}

verifyUUID () {
    UUID=$(grepUUIDby "$2")
    client_return="`grep "$UUID" ./tests/functionnal/log_server.log`"
    verifyReturn $? $3 "$1 $2" $UUID "./tests/functionnal/log_server.log"
}

connectAndKill() {
    clientArray=( 1 2 3 4 5 6 7 8 9 10 )
    clientPid=()
    for client in "${clientArray[@]}"
    do
        echo "/login \"multi_$client\"" | ./myteams_cli \"127.0.0.1\" 4441 2> /dev/null &
        verifyUUID "Multi user : $client" "multi_$client" 0
    done
}

echo -e "\e[93m\nServer Starting ...\e[0m\n"

./myteams_server 4441 2> ./tests/functionnal/log_server.log &
SERVER_PID=$!


sleep 3
echo -e "\e[92mServer Launched !\e[0m pid : $SERVER_PID"


echo -e "\e[93m\nSimple Server Connection Test\e[0m\n"

client_cmd="`cat ./tests/functionnal/user_1.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
client_return="`grep "User $UUID_TESTER logged in." ./tests/functionnal/log_server.log`"
UUID_TESTER=$(grepUUIDby "tester")
verifyReturn $? 0 "Log in | log out" "User $UUID_TESTER logged in." "./tests/functionnal/log_server.log"

client_cmd="`cat ./tests/functionnal/user_2.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
client_return="`grep "User $UUID_TESTER logged in." ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "Spam functions" "User $UUID_TESTER logged in." "./tests/functionnal/log_server.log"


client_cmd="`cat ./tests/functionnal/user_2.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
client_return="`grep "User $UUID_TESTER logged in." ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "Wrong login | logout" "User $UUID_TESTER logged in." "./tests/functionnal/log_server.log"

echo -e "\e[93m\nCreation test\e[0m\n"

client_cmd="`cat ./tests/functionnal/create_teams.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
client_return="`grep "testTeams" ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "Creation of a Teams" "testTeams" "./tests/functionnal/log_server.log"

TEAM_UUID=$(grepUUIDby "testTeams")

echo "test UUID : $TEAM_UUID"

client_cmd=$(echo -e "/login \"tester\"\n/subscribe \"$TEAM_UUID\"\n/use \"$TEAM_UUID\"\n/create \"testChannel\" \"test\"\n/logout" | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_client.log)
client_return="`grep "testChannel" ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "Creation of a Channel" "testChannel" "./tests/functionnal/log_server.log"

CHANNEL_UUID=$(grepUUIDby "testChannel")

client_cmd=$(echo -e "/login \"tester\"\n/use \"$TEAM_UUID\" \"$CHANNEL_UUID\"\n/create \"testThread\" \"test\"\n/logout" | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_client.log)
client_return="`grep "testThread" ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "Creation of a Thread" "testThread" "./tests/functionnal/log_server.log"

THREAD_UUID=$(grepUUIDby "testThread")

echo -e "\nUUID list :\n"
echo "Team : $TEAM_UUID"
echo "Channel : $CHANNEL_UUID"
echo "Thread : $THREAD_UUID"

echo -e "\e[93m\nUUID Test\e[0m\n"

client_cmd="`cat ./tests/functionnal/user_1.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
client_return="`grep "User $UUID_TESTER logged in." ./tests/functionnal/log_server.log`"
UUID_TESTER=$(grepUUIDby "tester")
verifyReturn $? 0 "UUID tester" "User $UUID_TESTER logged in." "./tests/functionnal/log_server.log"

client_cmd="`cat ./tests/functionnal/user_2.txt | ./myteams_cli \"127.0.0.1\" 4441 2> ./tests/functionnal/log_client.log`"
verifyUUID "UUID" "tester_2" 0

server_return="`grep "User tester_error logged in." ./tests/functionnal/log_server.log`"
verifyReturn $? 1 "No UUID by tester_error" "User tester_error logged in." "./tests/functionnal/log_server.log"

echo -e "\e[93m\nAll client functions test\e[0m\n"

client_cmd=$(cat ./tests/functionnal/cmd_1.txt | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_cmd.log)
client_return="`grep "testChannel" ./tests/functionnal/log_cmd.log`"
verifyReturn $? 0 "/info" "Channel \"testChannel\" ($CHANNEL_UUID): test" "./tests/functionnal/log_cmd.log"

client_cmd=$(cat ./tests/functionnal/cmd_2.txt | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_cmd.log)
client_return="`grep "tester" ./tests/functionnal/log_cmd.log`"
verifyReturn $? 0 "/users" "tester" "./tests/functionnal/log_cmd.log"

CLIENT_UUID=$(grepUUIDby "tester")

client_cmd=$(echo -e "/login \"tester\"\n/user \"$CLIENT_UUID\"\n/logout" | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_cmd.log)
client_return="`grep "tester" ./tests/functionnal/log_server.log`"
verifyReturn $? 0 "/user [uuid]" "tester" "./tests/functionnal/log_server.log"


client_cmd=$(echo -e "/login \"tester\"\n/send \"$CLIENT_UUID\" \"test\"\n/logout" | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_cmd.log)
client_return="`grep "test" ./tests/functionnal/log_cmd.log`"
verifyReturn $? 0 "/send [uuid]" "test" "./tests/functionnal/log_cmd.log"

client_cmd=$(echo -e "/login \"tester\"\n/messages \"$CLIENT_UUID\"\n/logout" | ./myteams_cli "127.0.0.1" 4441 2> ./tests/functionnal/log_cmd.log)
client_return="`grep "[Private]*test" ./tests/functionnal/log_cmd.log`"
verifyReturn $? 0 "/messages [uuid]" "[Private]*test" "./tests/functionnal/log_cmd.log"

echo -e "\e[93m\nMultiple login users test\e[0m\n"

connectAndKill
echo "Note : client will timeout. No worries :)"


kill $SERVER_PID

rm ./data/users.dat
rm ./data/teams.dat