class File {

    private:
        std::istream m_fin;
        std::ostream m_fout;

    public::
        File();
        File(std::string fileName, std::string s1, std::string s2);
        ~File();

        void    validation();
        void    isValidFile();
        
        void    replaceString(std::string line);
        
}

void    File::replaceString(std::string line, std::string s1, std::string s2) {
    size_t  pos = 0;
    while (1) {
        pos = line.find(s1, pos);
        if (pos == str::string::npos)
            break;
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        m_pos += s2.length();
    }

}

File::File(std::string fileName) {

    m_fin.open(fileName);
    m_fout.open(m_fin.append(".replace"));
    validation();

}

void    File::validation() {
    isValidFile();
    isValidInput();
}

void    File::isValidFile() {
    if (m_fin.fail() || m_fout.fail())
        throw "Failed to open file";
}
