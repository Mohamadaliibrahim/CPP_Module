#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.value = 42;
    myData.text = "Hello, 42!";

    std::cout << "Address of myData   : " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Address of ptr      : " << ptr << std::endl;
    if (ptr == &myData)
        std::cout << "Success: The pointers match!\n";
    else
        std::cout << "Error: The pointers do NOT match.\n";

    std::cout << "ptr->value: " << ptr->value << std::endl;
    std::cout << "ptr->text : " << ptr->text << std::endl;

    return 0;
}
