#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int 	Account::_totalNbWithdrawals;


Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created\n";
	return;
}

Account::Account( void ) {
	return;
}

Account::~Account( void ) {
	_displayTimestamp();
	--_nbAccounts;
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed\n";
	return;
}


int	Account::checkAmount ( void ) const {
	return _amount;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}


void	Account::_displayTimestamp( void ) {
	std::time_t time = std::time( 0 );
	std::tm *utc_tm = std::localtime( &time );

	std::cout << std::setfill('0') << "[" << (utc_tm->tm_year + 1900)
		<< std::setw(2) << utc_tm->tm_mon
		<< std::setw(2) << utc_tm->tm_mday << "_"
		<< std::setw(2) << (utc_tm->tm_hour) % 24
		<< std::setw(2) << utc_tm->tm_min
		<< std::setw(2) << utc_tm->tm_sec << "] ";
	return;
}

void	Account::displayAccountsInfos ( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() // could be Account::getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
	return;
}

void	Account::displayStatus ( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << checkAmount()
		<< ";deposit:" << deposit;
	_amount += deposit;
	++_totalNbDeposits;
	++_nbDeposits;
	_totalAmount +=deposit;
	std::cout << ";amount:" << checkAmount()
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	return;
}

bool	Account::makeWithdrawal ( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << checkAmount()
		<< ";withdrawal:";
	if ( checkAmount() - withdrawal < 0 ) {
		std::cout << "refused\n";
		return false;
	}
	_amount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	;std::cout << withdrawal
		<< ";amount:" << checkAmount()
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return true;
}
