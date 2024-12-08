#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie *a = newZombie(name);
    a->announce();
    delete a;
}