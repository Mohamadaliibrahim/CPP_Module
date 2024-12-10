#ifndef FILE_HPP
#define FILE_HPP
#include <iostream>
#include <fstream>

class File
{
    public:
        std::string read_file;
        std::string write_file;
        std::string read_content;
        std::string write_content;
        void    open_and_read();
        void    open_and_write();
        void    edit_write_content(std::string s1, std::string s2);
};

#endif