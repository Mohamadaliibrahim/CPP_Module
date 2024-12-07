#include <iostream>
#include "PhoneBook.hpp"

void	PhoneBook::i_index()
{
	i = 0;
}
void	PhoneBook::add(Contact new_contact)
{
	if (i == 8)
		i = 0;
	contacts[i] = new_contact;
	i++;
}

void	PhoneBook::search(int n)
{
	if (n < 0 || n > 7)
	{
		std::cout<<"Invalid index"<< std::endl;
		return ;
	}
	if (contacts[n].get_first_name().empty())
	{
		std::cout<<"Invalid indexxx"<< std::endl;
		return ;
	}
	std::cout<<n<<"|"<<contacts[n].get_first_name()<<"|"<<contacts[n].get_last_name()<<"|"<<contacts[n].get_nick_name()<< std::endl;
}

int	main()
{
	std::string str;
	PhoneBook	a;
	a.i_index();
	std::cout<<"hello world\n";
	while (str != "EXIT")
	{
		std::cout<<"choose: (ADD, SEARCH and EXIT)\n";
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			Contact nc;
			std::string n;
			std::cout << "enter the first name: ";
			std::getline(std::cin, n);
			nc.set_first_name(n);
			std::cout << "enter the last name: ";
			std::getline(std::cin, n);
			nc.set_last_name(n);
			std::cout << "enter the nick name: ";
			std::getline(std::cin, n);
			nc.set_nick_name(n);
			std::cout << "enter the phone number: ";
			std::getline(std::cin, n);
			nc.set_phone_number(n);
			std::cout << "enter the darkest secret: ";
			std::getline(std::cin, n);
			nc.set_secret(n);
			a.add(nc);
		}
		else if (str == "SEARCH")
		{
			int input;
			std::cout<<"Enter the index you want to search for: ";
			std::cin>>input;
			a.search(input);
		}
		else if (str == "EXIT")
			break;
	}
	return (0);
}