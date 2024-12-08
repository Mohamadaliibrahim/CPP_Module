#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;
    std::cout << "the address of str is: " << &str << std::endl;
    std::cout << "the address of ptr is: " << ptr << std::endl;
    std::cout << "the address of str is: " << &ref << std::endl;
    std::cout << "the value of str is: " << str << std::endl;
    std::cout << "the value of of str is: " << *ptr << std::endl;
    std::cout << "the value of of str is: " << ref << std::endl;
    return (0);
}