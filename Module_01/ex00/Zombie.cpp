#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string const str ) : name(str) {
	std::cout << "Zombie " << name << " created;\n";
}

Zombie::Zombie( void ) {
};

Zombie::~Zombie ( void ) {
	std::cout << "Zombie " << name << " destructed\n";
}

std::string	Zombie::get_name( void ) const {
	return this->name;
}

void	Zombie::announce( void ) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
