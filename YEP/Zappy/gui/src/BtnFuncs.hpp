/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** BtnFuncs
*/

#ifndef BTNFUNCS_HPP_
#define BTNFUNCS_HPP_

#include "Zappy.hpp"

class Zappy;
class Slider;
class Btn;

namespace BF
{
    void playBtn(Zappy *win, Btn *b, void *data);
    void switchScene(Zappy *win, int scene);
    void setMusic(Zappy *win, Slider *s, void *data);
    void setSound(Zappy *win, Slider *s, void *data);
    void resolutionBtn(Zappy *win, Btn *b, void *data);
    void optBtn(Zappy *win, Btn *b, void *data);
    void quitBtn(Zappy *win, Btn *b, void *data);
    void backToHome(Zappy *win, Btn *b, void *data);
    void directionBtn(Zappy *win, Btn *b, void *data);
};

#endif /* !BTNFUNCS_HPP_ */
