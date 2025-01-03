#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor called" << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}