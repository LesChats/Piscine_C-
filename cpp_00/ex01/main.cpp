#include <iostream>
#include "PhoneBook.hpp"

void	is_empty( std::string input, std::string phase ) {
	
	while ( input == "") {
		std::cout << "Error: " << phase << " cannot be empty.\n";
		std::cout << phase << " ?\n";
		std::getline (std::cin, input);
	}
}

int	main( void ) {
	
	PhoneBook phoneBook;
	std::cout << "\n	*** WELCOME TO PHONEBOOK ! ***	\n";
	std::string choice;
	std::cout << "What would you like to do ? ADD, SEARCH or EXIT ?\n";
	while ( std::getline (std::cin, choice) ) {

		if (choice == "ADD" )
			phoneBook.new_contact();
		else if (choice == "SEARCH" )
			phoneBook.search_contact();
		else if (choice == "EXIT" ) {
			std::cout << "Beware: You have lost all your contacts :O !\n\n";
			break;
		}
		std::cout << "What would you like to do ? ADD, SEARCH or EXIT ?\n";
	}
	return 0;
}
