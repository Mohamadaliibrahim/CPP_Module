#include <iostream>
#include "HumanB.hpp"

void HumanB::attack()
{
    if (w) {
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon" << std::endl;
    }
}

HumanB::HumanB(std::string n)
{
    name = n;
}

void    HumanB::setWeapon(Weapon &wp)
{
    w = &wp;
}
