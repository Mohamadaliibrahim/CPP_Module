#include <iostream>
#include "contact.hpp"

void    Contact::set_first_name(std::string name)
{
    first_name = name;
}
std::string    Contact::get_first_name()
{
    return (first_name);
}
void    Contact::set_last_name(std::string name)
{
    last_name = name;
}
std::string    Contact::get_last_name()
{
    return (first_name);
}
void    Contact::set_nick_name(std::string name)
{
    nick_name = name;
}
std::string    Contact::get_nick_name()
{
    return (nick_name);
}
void    Contact::set_phone_number(std::string name)
{
    phone_number = name;
}
std::string    Contact::get_phone_number()
{
    return (phone_number);
}
void    Contact::set_secret(std::string name)
{
    secret = name;
}
std::string    Contact::get_secret()
{
    return (secret);
}
