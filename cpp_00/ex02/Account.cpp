#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
	_accountIndex 	= _nbAccounts++;
	_amount			= initial_deposit;
	_totalAmount	+= initial_deposit;
	_nbDeposits		= 0;
	_nbWithdrawals  = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" <<_amount << ";created\n";
}

Account::~Account( void ) {
	_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" <<  _amount << ";";
	if ( withdrawal > _amount ) {
		std::cout << "refused\n";
		return ( false );
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	std::cout << "withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return ( true );
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	Account::_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" <<  _amount << ";" << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	std::cout << "amount:" << _amount << ";" << "nb_deposits:"
		<< _nbDeposits << "\n";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:"
		<< _nbWithdrawals << "\n";
}

int		Account::checkAmount( void ) const
{
	return ( _amount > 0 );
}

int		Account::getNbAccounts( void )
{
	return ( _nbAccounts );
}

int		Account::getTotalAmount( void )
{
	return ( _totalAmount );
}

int		Account::getNbDeposits( void )
{
	return ( _totalNbDeposits );
}

int		Account::getNbWithdrawals( void )
{
	return ( _totalNbWithdrawals );
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time( 0 );
	std::tm *utc_tm= std::localtime( &t );

	std::cout << std::setfill('0') << "[" << (utc_tm->tm_year + 1900)
		<< std::setw(2) << utc_tm->tm_mon + 1
		<< std::setw(2) << utc_tm->tm_mday << "_"
		<< std::setw(2) << (utc_tm->tm_hour + 9) % 24
		<< std::setw(2) << utc_tm->tm_min
		<< std::setw(2) << utc_tm->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}
