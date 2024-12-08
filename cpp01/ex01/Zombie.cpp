#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << "name constructor called" << std::endl;
    this->name = name;
}

void    Zombie::announce()
{
    std::cout<<name<<":BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " destructor called" << std::endl;
}

void    Zombie::set_name(std::string n)
{
    name = n;
}

Zombie::Zombie()
{
    std::cout << "default constructor called" << std::endl;
}
