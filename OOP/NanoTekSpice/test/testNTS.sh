#!/bin/sh

## Bin check

if [ -e ./nanotekspice ]; then
    echo "Binary Ok : Ready for Test\n"
else
    echo "Binary not found"; exit 84
fi

verifyReturn () {
    if [ $1 -eq $2 ]; then
        echo "$3 :\e[92m OK\e[0m"
    else
        echo "$3 :\e[91m FAILED\e[0m" ; exit 1
    fi
}

testNTS () {
    cat ./test/testCommand/$1 | ./nanotekspice ./test/testFile/$1 > result.nts && diff ./test/testResult/$1 result.nts
    verifyReturn $? 0 $2
}

echo "\e[93mBasic Component :\e[0m\n"

testNTS "input1.nts" "Input->Ouput"
testNTS "clock1.nts" "Clock->Ouput"
testNTS "false1.nts" "False->Ouput"
testNTS "true1.nts" "False->Ouput"

echo "\n\e[93mBasic Component :\e[0m\n"

testNTS "4081.nts" "Input->4081->Ouput"
testNTS "4071.nts" "Input->4071->Ouput"
testNTS "4011.nts" "Input->4011->Ouput"
testNTS "4001.nts" "Input->4001->Ouput"
testNTS "4030.nts" "Input->4030->Ouput"
testNTS "4069.nts" "Input->4069->Ouput"

echo "\n\e[93mAdvanced Component :\e[0m\n"

testNTS "4013.nts" "4013->Ouput"
testNTS "4017.nts" "4017->Ouput"
testNTS "4040.nts" "4040->Ouput"

echo "\n\e[93mAdvanced Gates :\e[0m\n"

testNTS "andAdv.nts" "Advanced->AND"
testNTS "andornotAdv.nts" "Advanced->OR->NOT->AND"
