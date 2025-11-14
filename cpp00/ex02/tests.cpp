// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Static member functions
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() 
              << ";total:" << getTotalAmount() 
              << ";deposits:" << getNbDeposits() 
              << ";withdrawals:" << getNbWithdrawals() 
              << std::endl;
}

// Constructor
Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount 
              << ";created" << std::endl;
}

// Destructor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount 
              << ";closed" << std::endl;
}

// Make a deposit
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << this->_amount 
              << ";deposit:" << deposit;
    
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout << ";amount:" << this->_amount 
              << ";nb_deposits:" << this->_nbDeposits 
              << std::endl;
}

// Make a withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << this->_amount 
              << ";withdrawal:";
    
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout << withdrawal 
              << ";amount:" << this->_amount 
              << ";nb_withdrawals:" << this->_nbWithdrawals 
              << std::endl;
    
    return true;
}

// Check current amount
int Account::checkAmount(void) const {
    return this->_amount;
}

// Display account status
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount 
              << ";deposits:" << this->_nbDeposits 
              << ";withdrawals:" << this->_nbWithdrawals 
              << std::endl;
}

// Display timestamp (private static)
void Account::_displayTimestamp(void) {
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    
    std::cout << "[" 
              << (now->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << now->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << now->tm_hour
              << std::setfill('0') << std::setw(2) << now->tm_min
              << std::setfill('0') << std::setw(2) << now->tm_sec
              << "] ";
}
// int Account::getNbAccounts(void) 
// {
// 	return _nbAccounts;
// } 

// int Account::getTotalAmount(void)
// {
// 	return _totalAmount;
// } 

// int	Account::getNbDeposits(void)
// {
// 	return _totalNbDeposits; 
// }

// int	Account::getNbWithdrawals(void)
// {
// 	return _totalNbWithdrawals;
// }

// void	Account::displayAccountsInfos(void)
// {
// 	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposit:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
// }
// void	Account::makeDeposit( int deposit)
// {
// 	this->_amount = deposit;
// 	_nbDeposits++;
// 	_totalAmount += _amount;
// }
// bool	Account::makeWithdrawal(int withdrawal)
// {
// 	this->_amount = withdrawal;
// 	_nbWithdrawals++;
// 	if (withdrawal > _totalAmount)
// 		return false;
// 	_totalAmount -= _amount;
// 	return true;
// }
// Account::Account(int initialDiposit)
// {

// }

	int		checkAmount( void ) const;
	void	displayStatus( void ) const;
int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
