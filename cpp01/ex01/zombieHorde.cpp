#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *a = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        a[i].set_name(name);
    }
    return (a);
}