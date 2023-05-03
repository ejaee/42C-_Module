#include "FileDto.hpp"

void    FileDto::replaceString(std::string line, std::string s1, std::string s2) {
    size_t  pos = 0;
    while (1) {
        pos = line.find(s1, pos);
        if (pos == std::string::npos)
            break;
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
}

FileDto::FileDto(){}

FileDto::FileDto(std::string fileName) {

    m_fin.open(fileName);
    std::string outName = fileName;
    m_fout.open(outName.append(".replace"));
    isValidFile();

}

std::ifstream   &FileDto::getFin(){
    return m_fin;
}

std::ofstream   &FileDto::getFout(){
    return m_fout;
}

void    FileDto::isValidFile() {
    if (m_fin.fail() || m_fout.fail())
        throw "Failed to open file";
}
