#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    br = new Brain();
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete br;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
    this->br = new Brain(*other.br);
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW! MEOW!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->br;
        this->br = new Brain(*other.br);
    }
    return (*this);
}