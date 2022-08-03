#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <stdlib.h>
#include "PhoneBook.hpp"

//-----------------------------------------------------------------------------//
/*
**			PHONEBOOK CLASS INSTANCIATION
*/
//-----------------------------------------------------------------------------//

PhoneBook::PhoneBook( void ): _idx() {
	
	std::cout << "PhoneBook constructor called\n";
	return;
} // : idx() sets idx at 0

PhoneBook::~PhoneBook( void ) {
	
	std::cout << "PhoneBook destructor called\n";
	return;
}

PhoneBook::Contact::~Contact( void ) {

	std::cout << "Contact destructor called\n";
	return;
}

//--------------------------------------------------------------------------------------//
/*
**			PHONEBOOK CLASS METHODS
*/
//--------------------------------------------------------------------------------------//

/* Creates a new contact */
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

	this->_add_contact( firstName, lastName, nickName, phoneNumber, darkestSecret );
	std::cout << "Contact successfully added!\n";
	return;
}

/* Adds a contact in Phonebook after creation */
void	PhoneBook::_add_contact( std::string firstName, std::string lastName, std::string nickName, 
	std::string phoneNumber, std::string darkestSecret ) {

	int pBookIdx = this->_idx % 8;
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	_contacts[pBookIdx] = newContact;	
	++(this->_idx);
	
	std::cout << "Contact added to PhoneBook :)\n";
	return;
}

int	PhoneBook::_get_idx( void ) const {
	
	return this->_idx;
}

/* Trims the extra characters and replace them by '.' */
std::string	PhoneBook::_is_too_big( int idx, int info ) const {
	
	std::string str = _contacts[idx]._get_info(info);
	if (str.size() > 10) {
		str.resize(10);
		str.replace(str.size() - 1, 1 ,".");
	}
	return str;
}

/* Search contact in Phonebook */
void	PhoneBook::search_contact( void ) const {

	unsigned	idx = 0;
	char		prov_idx;
	std::cout << "	*** PHONEBOOK ***	\n";
	std::cout << " ___________________________________________\n";
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |\n";
	std::cout << " ___________________________________________\n";
	if (this->_get_idx() < 1)
		return; // if empty PhoneBook
	for (int i = 0; i < 8; ++i) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << _is_too_big(i, 1);
		std::cout << "|" << std::setw(10) << _is_too_big(i, 2);
		std::cout << "|" << std::setw(10) << _is_too_big(i, 3);
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
	std::cout << "First Name:	" << _contacts[idx]._get_info( 1 ) << std::endl;
	std::cout << "Last Name:	" << _contacts[idx]._get_info( 2 ) << std::endl;
	std::cout << "Nick Name:	" << _contacts[idx]._get_info( 3 ) << std::endl;
	std::cout << "Phone Number:	" << _contacts[idx]._get_info( 4 ) << std::endl;
	std::cout << "Darkest Secret:	" << _contacts[idx]._get_info( 5 ) << std::endl;
	std::cout << "------------------\n";
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	return;
}

//----------------------------------------------------------------------------------//
/*
**			CONTACT CLASS INSTANCIATION
*/
//----------------------------------------------------------------------------------//

PhoneBook::Contact::Contact( void ) {
	
	std::cout << "Contact constructor called\n";
	return;
}

PhoneBook::Contact::Contact( std::string fName, std::string lName, std::string nName, 
	std::string pNumber, std::string secret ) :
       	_firstName(fName), 
		_lastName(lName), 
		_nickName(nName), 
		_phoneNumber(pNumber), 
		_darkestSecret(secret) {
	
		return;
}

//-----------------------------------------------------------------------------//
/*
**			CONTACT CLASS METHODS
*/
//-----------------------------------------------------------------------------//

/*gets contact info depending on which one is asked*/
std::string	PhoneBook::Contact::_get_info( int info ) const {

	if (info == 1)
		return this->_firstName;
	if (info == 2)
		return this->_lastName;
	if (info == 3)
		return this->_nickName;
	if (info == 4)
		return this->_phoneNumber;
	if (info == 5)
		return this->_darkestSecret;
	return (NULL);
}
