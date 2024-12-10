#include "Weapon.hpp"

void    Weapon::setType(std::string t)
{
    type = t;
}

const std::string Weapon::getType()
{
    return (type);
}

Weapon::Weapon(const std::string t)
{
    type = t;
}