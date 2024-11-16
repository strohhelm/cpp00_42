/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:46:49 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/16 16:16:19 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
const std::string b = "\033[34m";
const std::string w = "\033[0m";

Account::Account(void)
{
	
}
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<<"index:"		<<b<<_accountIndex	<<w<<";"\
				<<"amount:"		<<b<<_amount			<<w<<";" \
				<<"created"		<<std::endl;
	_nbAccounts++;
}
Account::~Account(void)
{
	_displayTimestamp();
	_totalAmount -= _amount;
	_nbAccounts--;
	std::cout	<<"index:"		<<b<<_accountIndex	<<w<<";"\
				<<"amount:"		<<b<<_amount			<<w<<";" \
				<<"closed"		<<std::endl;
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
	
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<<"accounts:"	<<b<<getNbAccounts()	<<w<<";" 
				<<"total:"		<<b<<getTotalAmount()	<<w<<";"
				<<"deposits:"	<<b<<getNbDeposits()	<<w<<";"
				<<"withdrawals:"<<b<<getNbWithdrawals()	<<w<<std::endl;
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		tm;
	
	time = std::time(nullptr);
	tm = *std::localtime(&time);
	std::cout	<<"["
				<<(tm.tm_year + 1900)
				<<(tm.tm_mon + 1)
				<<tm.tm_mday
				<<"_"
				<<tm.tm_hour
				<<tm.tm_min
				<<tm.tm_sec
				<<"] ";
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout	<<"index:"			<<b<<_accountIndex	<<w <<";"\
				<<"amount:"			<<b<<_amount			<<w<<";" \
				<<"deposits:"		<<b<<_nbDeposits		<<w<<";" \
				<<"withdrawals:"	<<b<<_nbWithdrawals	<<w<<std::endl;
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int		Account::checkAmount( void ) const
{
	return(_amount);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<<"index:"		<<b<<_accountIndex	<<w<<";" \
				<<"p_amount:"	<<b<<_amount			<<w<<";" \
				<<"withdrawal:";
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout						<<b<< withdrawal		<<w<<";"\
					<<"amount:"			<<b<<_amount			<<w<<";" \
					<<"nb_withdrawals:"	<<b<<_nbWithdrawals		<<w\
					<<std::endl;
		return (1);
	}
	std::cout <<"refused" <<std::endl;
	return (0);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<<"index:"		<<b<<_accountIndex	<<w<<";" \
				<<"p_amount:"	<<b<<_amount			<<w<<";" \
				<<"deposit:"	<<b<<deposit				<<w<<";";
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<<"amount:"		<<b<<_amount		<<w<<";"\
				<<"nb_deposits:"<<b<<_nbDeposits	<<w<<std::endl;
	return ;
}
