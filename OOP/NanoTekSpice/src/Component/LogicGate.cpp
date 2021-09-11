/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** InputComponent
*/

#include "LogicGate.hpp"

nts::Tristate nts::LogicGate::ANDGate(nts::Tristate first, nts::Tristate second)
{
    if (first == FALSE || second == FALSE)
        return (FALSE);
    if (first == UNDEFINED || second == UNDEFINED)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (first && second));
}

nts::Tristate nts::LogicGate::ORGate(nts::Tristate first, nts::Tristate second)
{
    if (first == TRUE || second == TRUE)
        return (TRUE);
    if (first == UNDEFINED || second == UNDEFINED)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (first || second));
}

nts::Tristate nts::LogicGate::XORGate(nts::Tristate first, nts::Tristate second)
{
    if (first == UNDEFINED || second == UNDEFINED)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (first ^ second));
}

nts::Tristate nts::LogicGate::NOTGate(nts::Tristate first, nts::Tristate second)
{
    if (second != UNDEFINED)
        throw PinError("NOTGate : Second params need to be UNDEFINED or void\n");
    if (first == UNDEFINED)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (!first));
}

nts::Tristate nts::LogicGate::NANDGate(nts::Tristate first, nts::Tristate second)
{
    if (first == UNDEFINED && second == UNDEFINED)
        return (UNDEFINED);
    if (first == TRUE && second == UNDEFINED)
        return (UNDEFINED);
    if (first == UNDEFINED && second == TRUE)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (!(ANDGate(first, second))));
}

nts::Tristate nts::LogicGate::NORGate(nts::Tristate first, nts::Tristate second)
{
    if (first == UNDEFINED && second == UNDEFINED)
        return (UNDEFINED);
    if (first == FALSE && second == UNDEFINED)
        return (UNDEFINED);
    if (first == UNDEFINED && second == FALSE)
        return (UNDEFINED);
    return (static_cast<nts::Tristate> (!(ORGate(first, second))));
}

/*
    data :
        0 : Clock
        1 : Data
        2 : Reset
        3 : Set
        4 : Q
        5 : /Q
    return :
        {Q, /Q}
*/

std::pair<nts::Tristate, nts::Tristate> nts::LogicGate::flipFlop(nts::Tristate data[])
{
    if (data[3] == nts::TRUE) {
        if (data[2] == nts::TRUE)
            return {nts::TRUE, nts::TRUE};
        else if (data[2] == nts::FALSE)
            return {nts::TRUE, nts::FALSE};
    } else if (data[3] == nts::FALSE) {
        if (data[2] == nts::TRUE)
            return {nts::FALSE, nts::TRUE};
        if (data[0] == nts::FALSE)
            return {data[4], data[5]};
        if (data[1] == nts::TRUE)
            return {nts::TRUE, nts::FALSE};
        else
            return {nts::FALSE, nts::TRUE};
    }
    return {nts::UNDEFINED, nts::UNDEFINED};
}
