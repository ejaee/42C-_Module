#include "PhoneBook.hpp"

void coutInputRequestMessage(){
	std::cout << std::endl
				<< "Enter one of the three commands (ADD / SEARCH / EXIT)" << std::endl
				<< "> ";
}

int main(){
	PhoneBook phoneBook;
    std::string	command;

	while (1){
		coutInputRequestMessage();
		std::getline(std::cin, command);
		if (std::cin.bad() || std::cin.fail() || std::cin.eof()){
            std::cout << "ERROR : invalid input value" << std::endl;
            exit(1);
        }
		if (command == "EXIT"){
			std::cout << "Exit the program" << std::endl;
			break;
		}
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.displayAllValues();
		else
			std::cout << "ERROR: Invalid input" << std::endl;
	}
	return 0;
}
