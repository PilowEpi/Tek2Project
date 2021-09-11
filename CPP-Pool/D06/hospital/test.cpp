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

int main()
{
    {
        SickKoala michel = SickKoala("michel");
        michel.takeDrug("Mars");
        michel.takeDrug("Coucou");
        michel.takeDrug("Kinder");
        michel.poke();
        michel.overDrive("COUCOU COMMENT TU VAS Kreog! Je suis un monstre Kreog! et j'aime pas les Kreog!");
        std::cout << "####################################" << std::endl;
        std::cout << "####################################" << std::endl;
        KoalaNurse nurse(1);
        nurse.giveDrug("enchilada", &michel);
        nurse.giveDrug("Mars", &michel);
        nurse.giveDrug("Kinder", &michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        std::cout << nurse.readReport("michl.report") << std::endl;
        nurse.timeCheck();
        nurse.timeCheck();
        nurse.timeCheck();
        std::cout << "####################################" << std::endl;
        std::cout << "####################################" << std::endl;
        KoalaDoctor dogtor("dog");
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.diagnose(&michel);
        std::cout << nurse.readReport("michel.report") << std::endl;
        dogtor.timeCheck();
        dogtor.timeCheck();
        std::cout << "################END#################" << std::endl;
    }
    std::cout << "####################################" << std::endl;
    std::cout << "####################################" << std::endl;
    {
        SickKoala michel1 = SickKoala("michel1");
        SickKoala michel2 = SickKoala("michel2");
        SickKoala michel3 = SickKoala("michel3");
        SickKoala michel4 = SickKoala("michel4");
        SickKoala michel5 = SickKoala("michel5");
        SickKoalaList list1(&michel1);
        SickKoalaList list2(&michel2);
        SickKoalaList list3(&michel3);
        SickKoalaList list4(&michel4);
        SickKoalaList list5(&michel5);
        SickKoalaList list6(0);
        SickKoalaList *start = &list1;
        start->append(&list2);
        start->append(&list3);
        start->append(&list4);
        start->append(&list5);
        start->append(&list6);
        start->dump();
        std::cout << start->isEnd() << list6.isEnd() << std::endl;
        start = start->remove(&list1);
        start = start->removeFromName("michel3");
        start = start->removeFromName("michel33");
        start->dump();
    std::cout << "################END#################" << std::endl;

    }
    std::cout << "####################################" << std::endl;
    std::cout << "####################################" << std::endl;
    {
        KoalaNurse nurse1(1);
        KoalaNurse nurse2(2);
        KoalaNurse nurse3(3);
        KoalaNurse nurse4(4);
        KoalaNurse nurse5(5);
        KoalaNurseList list1(&nurse1);
        KoalaNurseList list2(&nurse2);
        KoalaNurseList list3(&nurse3);
        KoalaNurseList list4(&nurse4);
        KoalaNurseList list5(&nurse5);
        KoalaNurseList list6(0);
        KoalaNurseList *start = &list1;
        start->append(&list2);
        start->append(&list3);
        start->append(&list4);
        start->append(&list5);
        start->append(&list6);
        start->dump();
        std::cout << start->isEnd() << list6.isEnd() << std::endl;
        start = start->remove(&list1);
        start = start->removeFromID(3);
        start = start->removeFromID(33);
        start->dump();
        std::cout << "################END#################" << std::endl;
    }
    std::cout << "####################################" << std::endl;
    std::cout << "####################################" << std::endl;
    {
        KoalaDoctor michel1("michel1");
        KoalaDoctor michel2("michel2");
        KoalaDoctor michel3("michel3");
        KoalaDoctor michel4("michel4");
        KoalaDoctor michel5("michel5");
        KoalaDoctorList list1(&michel1);
        KoalaDoctorList list2(0);
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
        start->append(0);
        start->dump();
        std::cout << start->isEnd() << list6.isEnd() << std::endl;
        start = start->remove(&list1);
        start = start->remove(&list1);
        start = start->removeFromName("michel3");
        start = start->removeFromName("michel33");
        start->dump();
    std::cout << "################END#################" << std::endl;

    }
    std::cout << "####################################" << std::endl;
    std::cout << "####################################" << std::endl;
}