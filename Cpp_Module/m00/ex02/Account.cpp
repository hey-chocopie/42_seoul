#include <iostream>
#include <ctime>
#include "Account.hpp"
#include <stdio.h>
#include <iomanip>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
//static은 한번 만들어지면 프로그램이 종료될때까지 존재하기 때문에, 전역에서 한번만 선언한다. 

void Account::_displayTimestamp( void )
{
	time_t time_now ;
    struct tm *tm ;

    time(&time_now) ;
    tm = localtime(&time_now) ;
	std::cout.fill('0');
	std::cout << "[" << tm->tm_year+1900 ;
	std::cout << std::setw(2) << tm->tm_mon+1;
	std::cout << std::setw(2) << tm->tm_mday << "_";
	std::cout << std::setw(2) << tm->tm_hour;
	std::cout << std::setw(2) << tm->tm_min;
	std::cout << std::setw(2) << tm->tm_sec << "] ";
}

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account()
{
	;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void    Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount = _amount + deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;

}

 bool    Account::makeWithdrawal( int withdrawal )
{

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount >= withdrawal)
	{
			_nbWithdrawals++;
			_totalNbWithdrawals++;
			_amount = _amount - withdrawal;
			_totalAmount = _totalAmount - withdrawal;
			std::cout << ";withdrawal:" << withdrawal;
			std::cout << ";amount:" << _amount;
			std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
			return (true);
	}
	else
		std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

