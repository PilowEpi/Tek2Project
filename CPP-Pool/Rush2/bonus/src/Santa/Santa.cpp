/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Santa
*/

#include <regex>
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Santa.hpp"

Santa::Santa()
{
    this->watching = "";
    this->content = "";
}

Santa::~Santa()
{
}

void Santa::watchGift(const std::string &gift)
{
    this->watching = gift;
}

const std::string &Santa::whatsWatched() const
{
    return (this->watching);
}

bool Santa::takeGift()
{
    std::string line = "";

    this->inHands.open(this->whatsWatched());
    this->content = "";
    if (!this->inHands) {
        std::cerr << "Santa Claus is to old to take this gift : " << this->watching << std::endl;
        return (false);
    }
    while (getline(this->inHands, line)) {
        this->content += line;
    }
    return (true);
}

const std::ifstream &Santa::getGift() const
{
    return (this->inHands);
}

void Santa::putdownGift()
{
    if (this->obj)
        delete this->obj;
    this->_size = 0;
    this->obj = nullptr;
    this->inHands.close();
    this->content = "";
}

bool Santa::validateXml()
{
    unsigned long int x = 0;
    unsigned long int z = 0;
    std::regex r("<(.+?)>");
    std::smatch match;
    std::string sub;
    std::vector<std::string> v;

    for (std::sregex_iterator it = std::sregex_iterator(this->content.begin(), this->content.end(), r); it != std::sregex_iterator(); it++) {
        match = *it;
        x++;
        sub = match.str(0).substr(1, match.str(0).size() - 2);
        if (sub.size() >= 1 && sub[0] == '/') {
            for (auto it = v.begin(); it != v.end(); ++it)
                if ("/" + *it == sub)
                    z++;
        } else {
            if (z)
                return (false);
            v.push_back(sub);
        }
    }
    if (!(x % 2) && x != 0 && (z == x / 2))
        return (true);
    return (false);
}

const std::string *Santa::getToyName()
{
    std::string name;
    std::regex r(">[^<].+?[^>]</");
    std::smatch match;

    regex_search(this->content, match, r);
    name = match.str(0).substr(1, match.str(0).size() - 3);
    return (new std::string(name));
}

void Santa::generateObj(std::vector<std::string> &v)
{
    const std::string *name = this->getToyName();
    Object *cur = nullptr;
    Object *old = nullptr;

    for (auto x = v.crbegin(); x != v.crend(); x++)  {
        std::cout << *x << std::endl;
        if (*x == "Teddy") {
            cur = new Teddy(*name == "" ? 0 : *name);
            cur->isTaken();
        }
        if (*x == "LittlePony") {
            cur = new LittlePony(*name == "" ? 0 : *name);
            cur->isTaken();
        }
        if (*x == "Box") {
            cur = new Box();
            cur->wrapMeThat(old);
        }
        if (*x == "GiftPaper") {
            cur = new GiftPaper();
            cur->wrapMeThat(old);
        }
        old = cur;
    }
    this->obj = old;
    delete name;
}

void Santa::unpackIt()
{
    std::regex r("<(.+?)>");
    std::vector<std::string> v;
    std::smatch match;
    std::string sub;

    if (this->validateXml()) {
        for (std::sregex_iterator it = std::sregex_iterator(this->content.begin(), this->content.end(), r); it != std::sregex_iterator(); it++) {
            match = *it;
            sub = match.str(0).substr(1, match.str(0).size() - 2);
            if (sub[0] == '/')
                break;
            else
                v.push_back(sub);
        }
        this->_size = v.size();
        this->generateObj(v);
    } else
        std::cerr << "Santa Claus prefer to drink some coke instead of unpacking : " << this->watching << std::endl;
}
