/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:50:15 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/03 13:49:01 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/******************************* STATICS *************************************/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    time_t timestamp;

    timestamp = time(NULL);
    std::cout << std::put_time(localtime(&timestamp), "[%Y%m%d_%H%M%S] ");
}

/******************************* CONSTRUCTOR & DESTRUCTOR ********************/
Account::Account(int initial_deposit)
{
    this->_accountIndex = this->getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
    std::cout << ";created" << std::endl;
    Account::_nbAccounts++;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
    std::cout << ";closed" << std::endl;
    Account::_nbAccounts--;
}

/******************************* GETTERS *************************************/
int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

/******************************* MEMBER FUNCTIONS ****************************/
void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:";
    std::cout << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits();
    std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    this->_nbDeposits++;
    this->_amount += deposit;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() - deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << this->checkAmount() << ";nb_deposits:";
    std::cout << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
    std::cout << ";withdrawal:";
    if (this->checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:";
    std::cout << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
