#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ): idx() {
	std::cout << "PhoneBook constructor called\n";
	return;
} // : idx() sets idx at 0

PhoneBook::~PhoneBook( void ) {
	std::cout << "PhoneBook destructor called\n";
	return;
}

void	PhoneBook::new_contact( void ) {

	std::string input;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First Name ?\n";
	std::getline ( std::cin, input );
	if (std::cin.eof())
		return;
	input = is_empty( input, "First Name" );
	firstName = input;

	std::cout << "Last Name ?\n";
	std::getline ( std::cin, input );
	if (std::cin.eof())
		return;
	input = is_empty( input, "Last Name" );
	lastName = input;

	std::cout << "Nickname ?\n";
	std::getline ( std::cin, input );
	if (std::cin.eof())
		return;
	input = is_empty( input, "Nickname" );
	nickName = input;

	std::cout << "Phone Number ?\n";
	std::getline ( std::cin, input );
	if (std::cin.eof())
		return;
	input = is_empty( input, "Phone Number" );
	phoneNumber = input;

	std::cout << "Darkest Secret ?\n";
	std::getline ( std::cin, input );
	if (std::cin.eof())
		return;
	input = is_empty( input, "Darkest Secret" );
	darkestSecret = input;

	this->add_contact( firstName, lastName, nickName, phoneNumber, darkestSecret );
	std::cout << "Contact successfully added!\n";
	return;
}

void	PhoneBook::add_contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret ) {
	int pBookIdx = idx % 8;
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contacts[pBookIdx] = newContact;	
	++idx;
	
	std::cout << "Contact added to PhoneBook :)\n";
	return;
}

void	PhoneBook::search_contact( void ) {

	unsigned	idx = 0;
	char		prov_idx;
	std::cout << "	*** PHONEBOOK ***	\n";
	std::cout << " ___________________________________________\n";
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |\n";
	std::cout << " ___________________________________________\n";
	if (get_idx() < 1)
		return;
	for (int i = 0; i < 8; ++i) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << is_too_big(i, 1);
		std::cout << "|" << std::setw(10) << is_too_big(i, 2);
		std::cout << "|" << std::setw(10) << is_too_big(i, 3);
		std::cout << "|\n";
	}
	std::cout << " ___________________________________________\n";
	std::cout << "Enter the index of the contact you want to read: \n";
	std::cin >> prov_idx;
	if ( (unsigned)prov_idx - '0' > 7 || std::cin.eof() ) {
		std::cout << "Error: the index must be in range [0-7]\n";
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
		return;
	}
	idx = atoi(&prov_idx);
	std::cout << "------------------\n";
	std::cout << "First Name:	" << contacts[idx].get_info( 1 ) << std::endl;
	std::cout << "Last Name:	" << contacts[idx].get_info( 2 ) << std::endl;
	std::cout << "Nick Name:	" << contacts[idx].get_info( 3 ) << std::endl;
	std::cout << "Phone Number:	" << contacts[idx].get_info( 4 ) << std::endl;
	std::cout << "Darkest Secret:	" << contacts[idx].get_info( 5 ) << std::endl;
	std::cout << "------------------\n";
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	return;
}

std::string	PhoneBook::is_too_big( int idx, int info ) {
	std::string str = contacts[idx].get_info(info);
	if (str.size() > 10) {
		str.resize(10);
		str.replace(str.size() - 1, 1 ,".");
	}
	return str;
}

int	PhoneBook::get_idx( void ) {
	return idx;
}


/* Contact class methods */

PhoneBook::Contact::Contact( void ) {
	std::cout << "Contact constructor called\n";
	return;
}

PhoneBook::Contact::Contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret ) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	return;
}

PhoneBook::Contact::~Contact( void ) {
	std::cout << "Contact destructor called\n";
	return;
}

std::string	PhoneBook::Contact::get_info( int info ) {

	if (info == 1)
		return firstName;
	if (info == 2)
		return lastName;
	if (info == 3)
		return nickName;
	if (info == 4)
		return phoneNumber;
	if (info == 5)
		return darkestSecret;
	return (NULL);
}
