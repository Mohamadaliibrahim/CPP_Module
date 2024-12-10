#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
    
    public:
        std::string name;
        Weapon &w;
        HumanA(std::string n, Weapon &wp);
        void    attack();
};

#endif