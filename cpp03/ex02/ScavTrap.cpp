#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout<<"ScavTrap: Default construction is called"<< std::endl;
    name = "Default";
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n)
{
    std::cout<<"ScavTrap: construction of "<< this->name<<" is called"<< std::endl;
    name = n;
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
     std::cout << "ScapTrap: " << name << " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hit_point = other.hit_point;
        energy_point = other.energy_point;
        attack_damage = other.attack_damage;
        std::cout<<"ScavTrap: copy operation is done"<< std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap: destruction is called"<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ScavTrap " << name << "cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (energy_point <= 0)
    {
        std::cout << "ScavTrap: " << name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    energy_point--;
    std::cout << "ScavTrap: " << name << " fiercely attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (hit_point <= 0)
    {
        std::cout << "ScavTrap: " << name << " cannot enter Gate Keeper mode because it has no hit points left!" << std::endl;
        return;
    }
    std::cout << "ScavTrap: " << name << " has entered Gate Keeper mode." << std::endl;
}