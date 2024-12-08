#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *a = newZombie("hello");
    randomChump("world");
    delete a;
}