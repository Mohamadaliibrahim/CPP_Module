#include "File.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
		std::cout << "error: bad arguments" << std::endl;
		return (1);
	}
    File a;
    a.read_file = av[1];
    a.open_and_read();
    a.edit_write_content(av[2], av[3]);
    a.open_and_write();
    return (0);
}