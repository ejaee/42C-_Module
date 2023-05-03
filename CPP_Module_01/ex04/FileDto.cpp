#include "FileDto.hpp"

FileDto::FileDto(){}

FileDto::FileDto(const std::string    fileName) 
    : m_fin(fileName.c_str()), m_fout((fileName + ".replace").c_str()) {
    if (!m_fin) {
        throw std::string("Failed to open file");
    }
    if (!m_fout) {
        m_fin.close();
        throw std::string("Failed to create output file");
    }
}

FileDto::~FileDto(){
    m_fin.close();
    m_fout.close();
}

std::ifstream&  FileDto::getFin(){
    return m_fin;
}

std::ofstream&  FileDto::getFout(){
    return m_fout;
}

void	FileDto::replaceString(std::string buf, const std::string& s1, const std::string& s2) {
    size_t  pos = 0;

    while (1) {
        pos = buf.find(s1, pos);
        if (pos == std::string::npos)
            break;
        buf.erase(pos, s1.length());
        buf.insert(pos, s2);
        pos += s2.length();
    }
    m_fout << buf << std::endl;
}
