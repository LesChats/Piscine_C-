#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>

std::string	is_empty( std::string input, std::string phase);

class	PhoneBook {

public:
	PhoneBook( void ); //constructor
	~PhoneBook( void ); // destructor

/* PhoneBook methods */
	void new_contact( void );
	void add_contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret); // each cannot be empty, all must be filled before adding contact.
	void search_contact( void ); 
	std::string is_too_big( int idx, int info );
	int get_idx( void );

private:
	class	Contact {

	public:
		Contact( void ); // constructor
		Contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret); // constructor
		~Contact( void ); // destructor

	/* Contact methods */
	std::string get_info( int info );

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	};
	Contact contacts[8];
	int	idx;
};

/* SEARCH */
/*

|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |
|         0|   Johanna|   Lecomte|   Shlurck|
|         1|Aime Juli.|    Baudot|   Mimmiii|

*/

// alignement a droit : setw(10);

#endif
