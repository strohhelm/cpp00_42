/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:46:49 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/15 21:17:02 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout	<<"index:"		<<this->_accountIndex <<";"\
				<<"amount:"		<<this->_amount <<";" \
				<<"created"		<<std::endl;
	Account::_nbAccounts++;
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbAccounts( void )
{
	return(Account::_nbAccounts);
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getTotalAmount( void )
{
	return(Account::_totalAmount);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
	
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int	Account::getNbWithdrawals( void )
{
	return(Account::_totalNbWithdrawals);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<<"accounts"	<<Account::getNbAccounts()		<<";" 
				<<"total:"		<<Account::getTotalAmount()		<<";"
				<<"deposits:"	<<Account::getNbDeposits()		<<";"
				<<"withdrawals"	<<Account::getNbWithdrawals()	<<std::endl;
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		tm;

	tm = *std::localtime(&time);
	std::cout	<<"["
				<<tm.tm_year
				<<tm.tm_mon
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
	std::cout	<<"index:"		<<this->_accountIndex <<";"\
				<<"amount:"		<<this->_amount <<";" \
				<<"deposits:"	<<this->_nbDeposits <<";" \
				<<"withdrawals:"	<<this->_nbWithdrawals <<std::endl;
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<<"index:" <<this->_accountIndex <<";" \
				<<"p_amout:" <<this->_amount <<";" \
				<<"withdrawal:"; 
	if (this->_amount > withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals -= withdrawal;
		Account::_nbWithdrawals++;
		std::cout	<<withdrawal \
					<<"amount:"<<this->_amount<<";" \
					<<"nb_withdrawals:" <<this->_nbWithdrawals\
					<<std::endl;
		return (1);
	}
	std::cout <<"refused" <<std::endl;
	return (0);
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout	<<"index:"		<<this->_accountIndex	<<";" \
				<<"p_amount"	<<this->_amount			<<";" \
				<<"deposit:"	<<deposit				<<";" \
				<<std::endl;
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	std::cout	<<"amount:"		<<this->_amount \
				<<"nb_deposits:"<<this->_nbDeposits<<std::endl;
	return ;
}



