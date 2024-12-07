#include <iostream>
#include "contact.hpp"

class	PhoneBook
{
	private:
		int	i;
		Contact contacts[8];
	public:
	void	i_index();
	void	add(Contact a);
	void	search(int n);
};