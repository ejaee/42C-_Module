#ifndef FILEDTO_HPP
# define FILEDTO_HPP

#include <iostream>
#include <fstream>

class FileDto {

    private:
        std::ifstream m_fin;
        std::ofstream m_fout;

    public:
        FileDto();
        FileDto(std::string fileName);
        ~FileDto();

        std::ifstream   &getFin();
        std::ofstream   &getFout();
        void    isValidFile();
        
        void    replaceString(std::string line, std::string s1, std::string s2);
        
};

#endif