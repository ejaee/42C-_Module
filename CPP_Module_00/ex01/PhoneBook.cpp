#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    index = 0;
}

PhoneBook::~PhoneBook(){
}

void    PhoneBook::addContact(){
    std::cout << "┌───────────────┐" << std::endl;
    std::cout << "│ Add a contact │" << std::endl;
    std::cout << "└───────────────┘" << std::endl;
    contact[index % MAX_STORAGE_SPACE] = createContact();
    if (contact[index % MAX_STORAGE_SPACE].isEmpty()){
        std::cout << "[ADD] ERROR : A saved contact can’t have empty fields" << std::endl;
        return ;
    }
    std::cout << "--- Success ---" << std::endl;
    index++;
    if (index == MAX_STORAGE_SPACE*2)
        index -= MAX_STORAGE_SPACE;
}

Contact PhoneBook::createContact(){
    std::string info[5];

    for (int i = 0; i < 5; i++){
        if (i == 0)
            std::cout << "[ADD 1/5] first name > ";
        else if (i == 1)
            std::cout << "[ADD 2/5] last name > ";
        else if (i == 2)
            std::cout << "[ADD 3/5] nick name > ";
        else if (i == 3)
            std::cout << "[ADD 4/5] phone number > ";
        else if (i == 4)
            std::cout << "[ADD 5/5] darkest secret > ";
        std::getline(std::cin, info[i]);
        if (std::cin.bad() || std::cin.fail() || std::cin.eof()){
            std::cout << "[ADD] ERROR : invalid input value" << std::endl;
            exit(1);
        }
    }
    return Contact(info[0], info[1], info[2], info[3], info[4]);
}

void    PhoneBook::displayAllValues(){
    if (index == 0){
		std::cout << "[SEARCH] is empty" << std::endl;
		return ;
	}
    std::cout << "┌───────┬────────────┬────────────┬────────────┐" << std::endl;
    std::cout << "│ index │ first name │  last name │  nick name │" << std::endl;
    std::cout << "├───────┼────────────┼────────────┼────────────┤" << std::endl;

    for (int i = 0; i < 8; i++){
        if (i == index)
            break;
        std::cout << "│   " << i + 1 << "   │";
        displaySubstrInfo(contact[i].getFirstName());
        displaySubstrInfo(contact[i].getLastName());
        displaySubstrInfo(contact[i].getNickName());
        std::cout << std::endl;
    }
    std::cout << "└───────┴────────────┴────────────┴────────────┘" << std::endl;
    displaySelectedValue();
}

void    PhoneBook::displaySubstrInfo(std::string info){
    if (info.length() > 10)
        info = info.substr(0, 9) + ".";
    std::cout << " " << std::setw(10) << info << " │";
}

void    PhoneBook::displaySelectedValue(){
    std::string indexString;
    int selectedIndex;

    while (1){
		std::cout << std::endl << "[SEARCH] input index > ";
		std::getline(std::cin, indexString);
        if (std::cin.bad() || std::cin.fail() || std::cin.eof()){
            std::cout << "[SEARCH] ERROR : invalid input value" << std::endl;
            exit(1);
        }
        try{
		    validateSelectedValue(indexString);
            selectedIndex = std::atoi(indexString.c_str());
            std::cout << "┌───────────────┐" << std::endl;
            std::cout << "│     index     │        " << indexString << std::endl;
            std::cout << "├───────────────┤" << std::endl;
            std::cout << "│  first name   │        " << contact[selectedIndex - 1].getFirstName() << std::endl;
            std::cout << "├───────────────┤" << std::endl;
            std::cout << "│   last name   │        " << contact[selectedIndex - 1].getLastName() << std::endl;
            std::cout << "├───────────────┤" << std::endl;
            std::cout << "│   nick name   │        " << contact[selectedIndex - 1].getNickName() << std::endl;
            std::cout << "├───────────────┤" << std::endl;
            std::cout << "│  phone number │        " << contact[selectedIndex - 1].getPhoneNumber() << std::endl;
            std::cout << "├───────────────┤" << std::endl;
            std::cout << "│ darkest secret│        " << contact[selectedIndex - 1].getDarkestSecret() << std::endl;
            std::cout << "└───────────────┘" << std::endl;
            break;
        } catch (const char *message){
    		std::cout << message << std::endl;
        }
    }
}

void	PhoneBook::validateSelectedValue(std::string indexString){
    int indexInt;

    indexInt = std::atoi(indexString.c_str());
    if (indexString.size() != 1)
        throw "[SEARCH] Error: invalid input";
	if (0 >= indexInt || indexInt > index % MAX_STORAGE_SPACE)
        throw "[SEARCH] Error: invalid range";
}
