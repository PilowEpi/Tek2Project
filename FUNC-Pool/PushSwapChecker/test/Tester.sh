#!/bin/sh

## Bin check

if [ -e ../pushswap_checker ]; then
    echo "Binary Ok : Ready for Test\n"
else
    echo "Binary not found"; exit 84
fi

verify () {
    if [ "$1" = "$2" ]; then
        echo "$3 :\e[92m OK\e[0m"
    else
        echo "$3 :\e[91m FAILED\e[0m"
    fi
}

verifyReturn () {
    if [ $1 -eq $2 ]; then
        echo "$3 :\e[92m OK\e[0m"
    else
        echo "$3 :\e[91m FAILED\e[0m"
    fi
}

## Parsing Args

echo "\e[93mParsing Test\e[0m\n"

test_r="$(echo "sa sa sb" | ../pushswap_checker 1 2 3 4 5)"
verifyReturn $? 0 "Correct Arg"

test_r="$(echo "" | ../pushswap_checker)"
verifyReturn $? 0 "Empty Args"

test_r="$(echo "sa sa sb" | ../pushswap_checker 1 a2 3 24 5b)"
verifyReturn $? 84 "Bad params Arg"

test_r="$(echo "sa21a sa s bs" | ../pushswap_checker 1 2 3 4 5)"
verifyReturn $? 84 "Bad command Arg"

test_r="$(echo "sa s2sb rr aa" | ../pushswap_checker 12r 2 3a 4 5)"
verifyReturn $? 84 "Both params/command Arg"


## Sorted List
echo "\n\e[93mSorted List Test\e[0m\n"

test1="$(echo "" | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "" | ../pushswap_checker -11 -2 3 4 5)"
test3="$(echo "" | ../pushswap_checker 1 2 3 40000 5)"

verify "$test1" "OK" "Simple Sorted List"
verify "$test2" "OK" "Simple Neg Sorted List"
verify "$test3" "KO ([1,2,3,40000,5],[])" "Simple Not Sorted List"

## sa / sb / sc test
echo "\n\e[93msa sb sc List Test\e[0m\n"

test4="$(echo "sa sa" | ../pushswap_chewcker 1 2 3 4 5)"
test5="$(echo "sa" | ../pushswap_checker -11 -2 3 4 5)"
test6="$(echo "pb pb sb sb" | ../pushswap_checker 1 2 3 4 5)"
test7="$(echo "pb pb sb" | ../pushswap_checker -11 -2 3 4 5)"
test8="$(echo "pb pb sc" | ../pushswap_checker -11 -2 3 4 5)"

verify "$test4" "OK" "Double sa List"
verify "$test5" "KO ([-2,-11,3,4,5],[])" "Simple sa List"
verify "$test6" "KO ([3,4,5],[2,1])" "Double sb List"
verify "$test7" "KO ([3,4,5],[-11,-2])" "Simple sb List"
verify "$test8" "KO ([4,3,5],[-11,-2])" "Simple sc List"

##  pa / pb
echo "\n\e[93mpa pb List Test\e[0m\n"

test1="$(echo "pb pa" | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "pb pb pa pa" | ../pushswap_checker 1 2 3 4 5)"
test3="$(echo "pb pb pa pa" | ../pushswap_checker )"

verify "$test1" "OK" "Simple pb pa List"
verify "$test2" "OK" "Double pb pa List"
verify "$test3" "OK" "Empty list with pb pa"

## ra / rb / rr
echo "\n\e[93mra rb rr List Test\e[0m\n"

test1="$(echo "ra ra ra ra ra" | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "pb pb rb rb rb" | ../pushswap_checker 1 2 3 4 5)"
test3="$(echo "pb pb rr rr" | ../pushswap_checker 1 2 3 4 5)"
test4="$(echo "ra ra ra" | ../pushswap_checker )"
test5="$(echo "rb rb rb rb rb" | ../pushswap_checker )"
test6="$(echo "rr rr rr rr" | ../pushswap_checker )"

verify "$test1" "OK" "Simple ra List"
verify "$test2" "KO ([3,4,5],[1,2])" "Simple rb List"
verify "$test3" "KO ([5,3,4],[2,1])" "Simple rr List"
verify "$test4" "OK" "Simple Empty ra List"
verify "$test5" "OK" "Simple Empty rb List"
verify "$test6" "OK" "Simple Empty rr List"

## rra / rrb / rrr
echo "\n\e[93mrra rrb rrr List Test\e[0m\n"

test1="$(echo "rra rra rra rra rra" | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "pb pb rrb rrb rrb" | ../pushswap_checker 1 2 3 4 5)"
test3="$(echo "pb pb rrr rrr" | ../pushswap_checker 1 2 3 4 5)"
test4="$(echo "rra rra rra" | ../pushswap_checker )"
test5="$(echo "rrb rrb rrb rrb rrb" | ../pushswap_checker )"
test6="$(echo "rrr rrr rrr rrr" | ../pushswap_checker )"

verify "$test1" "OK" "Simple rra List"
verify "$test2" "KO ([3,4,5],[1,2])" "Simple rrb List"
verify "$test3" "KO ([4,5,3],[2,1])" "Simple rrr List"
verify "$test4" "OK" "Simple Empty rra List"
verify "$test5" "OK" "Simple Empty rrb List"
verify "$test6" "OK" "Simple Empty rrr List"

echo "\n\e[93mLong List Test\e[0m\n"

test1="$(echo "ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra ra " | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa sa " | ../pushswap_checker 1 2 3 4 5)"

verify "$test1" "OK" "Long long ra List"
verify "$test2" "OK" "Long long sa List"


echo "\n\e[93mMulti Command List Test\e[0m\n"

test1="$(echo "sa pb sb sa sc ra rb pb rr pa rra rrb rrr" | ../pushswap_checker 1 2 3 4 5)"
test2="$(echo "sa pb sb sa sc ra pb rr sa sc sb rr rrr rra rra sa pb pa pa pa pb pb pb ra rb pb rr pa rra rrb rrr" | ../pushswap_checker 1 2 3 4 5)"

verify "$test1" "KO ([1,4,2,5],[3])" "Multi Command List"
verify "$test2" "KO ([2,1],[4,5,3])" "Crash Test List"

## 