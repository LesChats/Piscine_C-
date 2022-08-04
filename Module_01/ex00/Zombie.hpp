#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

class Zombie {

public:

	Zombie( std::string const name );
	Zombie( void );
	~Zombie( void );
	void	announce( void ) const;

private:

	std::string get_name( void ) const;

	std::string name;

};


#endif //------------------------------------------------------------ZOMBIE_H---
