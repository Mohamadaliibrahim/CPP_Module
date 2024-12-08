#include <iostream>
#include "Zombie.hpp"

int main()
{
    int i;
    std::cout<<"enter number of zombies"<< std::endl;
    std::cin>>i;
    Zombie *a = zombieHorde(i, "jnde");
    for (int j = 0; j < i; j++)
    {
        a[j].announce();
    }
    delete[] a;
    return (0);
}