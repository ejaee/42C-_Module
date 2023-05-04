/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:30:00 by ejachoi           #+#    #+#             */
/*   Updated: 2023/05/04 15:30:03 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
    :   _accountIndex(_nbAccounts++), 
        _amount(initial_deposit),
        _nbDeposits(0),
        _nbWithdrawals(0) {
    _displayTimestamp();
    std::cout	<< " index:" << _accountIndex
			    << ";amount:" << _amount
			    << ";created" << std::endl;
    _totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;
	_totalNbDeposits = _totalNbDeposits - _nbDeposits;
	_totalNbWithdrawals = _totalNbWithdrawals - _nbWithdrawals;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
			    << ";amount:" << _amount
	    		<< ";closed" << std::endl;
}  

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout   << " accounts:" << getNbAccounts()
			    << ";total:" << getTotalAmount()
			    << ";deposits:" << getNbDeposits()
			    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
			    << ";p_amount:" << _amount - deposit
			    << ";deposit:" << deposit
		    	<< ";amount:" << _amount
			    << ";nb_deposits:" << _nbDeposits << std::endl;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout     << " index:" << _accountIndex
		        << ";p_amount:" << _amount + _nbWithdrawals
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    bool    result;

    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
		        << ";p_amount:" << _amount + withdrawal;
    if (_amount - withdrawal < 0) {
        std::cout   << ";withdrawal:refused" << std::endl;
        result = false;
    }
    else {
        std::cout   << ";withdrawal:" << withdrawal
                    << ";amount:" << _amount - withdrawal
                    << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        ++_totalNbWithdrawals;
        result = true;
    }
    return result;
}

void	Account::_displayTimestamp( void )
{
	time_t	tStemp;
	char	buf[16];

	time(&tStemp);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&tStemp));
	std::cout << "[" << buf << "]";
}
