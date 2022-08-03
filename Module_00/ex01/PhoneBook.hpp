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
	void search_contact( void ) const; 

private:
	class	Contact {

	public:
		Contact( void ); // constructor
		Contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret); // constructor
		~Contact( void ); // destructor

	/* Contact methods */
	std::string _get_info( int info ) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	};
	
/* PhoneBook private methods */
	void _add_contact( std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
	int _get_idx( void ) const;
	std::string _is_too_big( int idx, int info ) const;

	Contact _contacts[8];
	int	_idx;

};

#endif // _PHONEBOOK_H
