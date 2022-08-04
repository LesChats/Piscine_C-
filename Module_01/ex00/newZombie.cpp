#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie( std::string const name) {
	new Zombie zombie (name);

	return (zombie);
}
