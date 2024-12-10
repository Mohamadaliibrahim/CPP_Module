#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *w;
    public:
        HumanB(std::string n);
        void    setWeapon(Weapon &wp);
        void    attack();
};

#endif