#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->type = other.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW! MEOW!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}