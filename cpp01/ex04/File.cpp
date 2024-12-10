#include "File.hpp"

void    File::open_and_read()
{
    std::string buffer;
    std::ifstream rf(read_file.c_str());
    if (!rf.is_open())
    {
        std::cout << "Error: Unable to open file for reading." << std::endl;
        return ;
    }
    while (getline(rf, buffer))
        read_content += buffer + "\n";
    rf.close();
    write_content = read_content;
}

void    File::edit_write_content(std::string s1, std::string s2)
{
    std::string temp;
    size_t i = 0;
    while (i < write_content.length())
    {
        if (write_content.compare(i, s1.length(), s1) == 0)
        {
            temp += s2;
            i += s2.length();
        }
        else
        {
            temp += write_content[i];
            i++;
        }
    }
    write_content = temp;
}

void    File::open_and_write()
{
    write_file = read_file + ".replace";
    std::ofstream wf(write_file.c_str(), std::ios::out | std::ios::trunc);
    if (!wf.is_open())
    {
        std::cout << "Error: Unable to open file for writing." << std::endl;
        return ;
    }
    wf << write_content;
    wf.close();
}
