#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    index = 0;
}

PhoneBook::~PhoneBook(){
}

void    PhoneBook::addContact(){
    std::cout << "Add a contact" << std::endl;
    contact[index % MAX_STORAGE_SPACE] = craeteContact();
    index++;
    if (index == MAX_STORAGE_SPACE*2)
        index -= MAX_STORAGE_SPACE;
}

Contact PhoneBook::craeteContact(){
    std::string info[5];

    for (int i = 0; i < 5; i++){
        std::cin >> info[i];
    }
    if (std::cin.eof()){
        std::cout << "EOF: Exit the program" << std::endl;
    }

    return Contact(info[0], info[1], info[2], info[3], info[4]);
}

void    PhoneBook::searchContact(){
    std::cout << "┌───────┬────────────┬────────────┬────────────┐" << std::endl;
    std::cout << "│ index │ first name │  last name │  nick name │" << std::endl;
    std::cout << "├───────┼────────────┼────────────┼────────────┤" << std::endl;
    
    for (int i = 0; i < 8; i++){
        if (i == index)
            break;
        std::cout << "│   " << i + 1 << "   │";
        editSearchInfo(contact[i].getFirstName());
        editSearchInfo(contact[i].getLastName());
        editSearchInfo(contact[i].getNickName());
        std::cout << std::endl;
    }
    std::cout << "└───────┴────────────┴────────────┴────────────┘" << std::endl;
}

void    PhoneBook::editSearchInfo(std::string info){
    int infoLen = info.length();

    if (infoLen < 10){
        for (int i = 0; i < 11 - infoLen; i++){
            std::cout << " ";
        }
        std:: cout << info << " │";
    }
    else if (infoLen == 10){
        std::cout << " " << info << " │";
    }
    else{
        std::cout << " ";
        for (int i = 0; i < 9; i++){
            std::cout << info[i];
        }
        std::cout << ". │";
    }
}

