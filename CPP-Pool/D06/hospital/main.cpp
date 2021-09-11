/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** hello
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"
#include "SickKoalaList.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctorList.hpp"

int main ()
{
    KoalaDoctor michel1("michel1");
        KoalaDoctor michel2("michel2");
        KoalaDoctor michel3("michel3");
        KoalaDoctor michel4("michel4");
        KoalaDoctor michel5("michel5");
        KoalaDoctorList list1(&michel1);
        KoalaDoctorList list2(&michel2);
        KoalaDoctorList list3(&michel3);
        KoalaDoctorList list4(&michel4);
        KoalaDoctorList list5(&michel5);
        KoalaDoctorList list6(0);
        KoalaDoctorList *start = &list1;
        start->append(&list2);
        start->append(&list3);
        start->append(&list4);
        start->append(&list5);
        start->append(&list6);
        start->append(0);
        start->append(0);
        start->append(0);
        start->dump();
        std::cout << start->isEnd() << list6.isEnd() << std::endl;
        start = start->remove(&list1);
        start = start->remove(&list1);
        start = start->removeFromName("michel3");
        start = start->removeFromName("michel33");
        start->dump();
}