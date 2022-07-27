#include <iostream>
#include <ctime>
#include "Account.hpp"


Account::Acount( int intitial_deposit ) {
	std::cout << "index:" << 
}

Account::~Account( void ) {
	std::cout << "index:" << idx << ";";
	std::cout << "p_amount:" << p_amount[idx] << ";";
	std::cout << "amout:" << amount[idx] << ";";
	std::cout << "nb_deposits:" << deposits[idx];
	return;
}

Account::_displayTimestamp( void ) {
	std::time_t time = std::time( 0 );
	std::tm *utc_tm = std::localtime( &time );

	std::cout << std::setfill('0') << "[" << (utc_tm->tm_year + 1900)
		<< std::setw(2) << utc_tm->tm_mon + 1
		<< std::setw(2) << (utc_tm->tm_hour + 9) % 24
		<< std::setw(2) << utc_tm->tm_min
		<< std::setw(2) << utc_tm->tm_sec << "] ";
	return;
}
