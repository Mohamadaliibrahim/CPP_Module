#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout<<"Default construction is called"<< std::endl;
    name = "Default";
    hit_point = 10;
    energy_point = 10;
    attack_damage = 0;
}
ClapTrap::~ClapTrap()
{
    std::cout<<"destruction is called"<< std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
{
    name = n;
    hit_point = 10;
    energy_point = 10;
    attack_damage = 0;
    std::cout<<"construction of "<< this->name<<" is called"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    name = other.name;
    hit_point = other.hit_point;
    energy_point = other.energy_point;
    attack_damage = other.attack_damage;
    std::cout<<""<<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hit_point = other.hit_point;
        energy_point = other.energy_point;
        attack_damage = other.attack_damage;
        std::cout<<"copy operation is done"<< std::endl;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap: " << name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }
    if (energy_point <= 0)
    {
        std::cout << "ClapTrap: " << name << " cannot attack because it has no energy points left!" << std::endl;
        return;
    }
    energy_point--;
    std::cout << "ClapTrap: " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_point -= amount;
    if (hit_point < 0)
        hit_point = 0;
    std::cout << "ClapTrap: " << name << " takes " << amount
              << " points of damage! Hit points left: " << hit_point << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap: " << name << " cannot be repaired because it has no hit points left!" << std::endl;
        return;
    }
    if (energy_point <= 0)
    {
        std::cout << "ClapTrap: " << name << " cannot be repaired because it has no energy points left!" << std::endl;
        return;
    }
    energy_point--;
    hit_point += amount;
    std::cout << "ClapTrap: " << name << " is repaired by " << amount
              << " points! Hit points: " << hit_point << "." << std::endl;
}
