#include "PhoneBook.hpp"

void coutInputRequestMessage(){
	std::cout << std::endl
				<< "Enter one of the three commands (ADD / SEARCH / EXIT)" << std::endl
				<< "> ";
}

int main(){
	PhoneBook phoneBook;
	//  == PhoneBook phoneBook = PhoneBook();
    std::string	command;

	coutInputRequestMessage();
	while (std::cin >> command){
		if (command == "EXIT"){
			std::cout << "Exit the program" << std::endl;
			break;
		}

		else if (command == "ADD"){
			
			phoneBook.addContact();

		}

		else if (command == "SEARCH"){
			
			phoneBook.searchContact();

		}
		else{
			std::cout << "ERROR: Invalid input" << std::endl;
		}
		if (std::cin.eof()){
			std::cout << "EOF: Exit the program" << std::endl;
			return 1;
		}
		coutInputRequestMessage();
	}
	return 0;
}
