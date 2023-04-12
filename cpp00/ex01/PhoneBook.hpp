#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_STORAGE_SPACE 8

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
    private:
    Contact contact[8];
    int index;

    Contact craeteContact();
    void    editSearchInfo(std::string info);

    public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact();

};

#endif