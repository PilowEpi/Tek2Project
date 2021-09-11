/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

int main(void)
{
    float temperature;
    std::string type;

    std::cin >> temperature >> type;
    if (type == "Celsius") {
        temperature = (temperature * 1.8) + 32;
        type = "Fahrenheit";
    } else if (type == "Fahrenheit") {
        temperature = (temperature - 32) / (1.8);
        type = "Celsius";
    }
    std::cout << std::fixed; 
    std::cout << std::setw(16) << std::setprecision(3) << temperature << std::setw(16) << type << std::endl;
    return (0);
}