#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";

	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused\n";
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount + withdrawal
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}
int Account::checkAmount(void) const
{
	return _amount;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << "\n";
}

void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(nullptr);
	std::tm *localTime = std::localtime(&currentTime);

	std::cout << std::setfill('0') << "[" << localTime->tm_year + 1900
			<< std::setw(2) << localTime->tm_mon + 1
			<< std::setw(2) << localTime->tm_mday
			<< "_" << std::setw(2) << localTime->tm_hour
			<< std::setw(2) << localTime->tm_min
			<< std::setw(2) << localTime->tm_sec << "] ";
}
