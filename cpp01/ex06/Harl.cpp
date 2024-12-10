#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*actions[])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = 
    {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };
    int startIndex = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            startIndex = i;
            break;
        }
    }
    if (startIndex == -1)
    {
        std::cout << "Invalid level: " << level << std::endl;
        return;
    }
    switch (startIndex)
    {
        case 0:
            (this->*actions[0])();
            (this->*actions[1])();
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 1:
            (this->*actions[1])();
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 2:
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 3:
            (this->*actions[3])();
            break;
    }
}
