#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    // Test 1: Polymorphism and Virtual Functionality
    std::cout << "\n--- Test 1: Polymorphism ---\n";
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    // Test 2: Array of Animals
    std::cout << "\n--- Test 2: Array of Animals ---\n";
    Animal* zoo[4];
    for (int i = 0; i < 2; ++i)
        zoo[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        zoo[i] = new Cat();

    for (int i = 0; i < 4; ++i)
    {
        std::cout << zoo[i]->getType() << " says: ";
        zoo[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
        delete zoo[i];

    // Test 3: Deep Copy
    std::cout << "\n--- Test 3: Deep Copy ---\n";
    Dog originalDog;
    originalDog.makeSound();

    Dog copyDog = originalDog; // Copy constructor
    copyDog.makeSound();

    // Modify the original dog's Brain ideas
    originalDog.makeSound();

    std::cout << "\n--- Test Completed ---\n";
    return 0;
}
