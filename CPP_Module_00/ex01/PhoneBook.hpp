#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_STORAGE_SPACE 8

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook{
    private:
    Contact contact[8];
    int index;

    Contact createContact();
    void    displaySubstrInfo(std::string info);
    void    displaySelectedValue();
    void    validateSelectedValue(std::string indexString);

    public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void displayAllValues();
};

#endif
