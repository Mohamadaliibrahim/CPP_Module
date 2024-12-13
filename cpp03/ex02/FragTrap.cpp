#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Deafault_FragTrap")
{
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Default constructor called for " << this->name << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n)
{
    this->name = n;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called for " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap Copy assignment operator called for " << this->name << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
