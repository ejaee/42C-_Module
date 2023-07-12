#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

// Constructors
PmergeMe::PmergeMe(int size): _size(size)
{
	if (_size < 1)
		throw WrongToken();
	_con1.reserve(_size);
}

// Destructor
PmergeMe::~PmergeMe()
{
}

size_t PmergeMe::size() const
{
	return _size;
}

std::vector<int>& PmergeMe::con1()
{
	return _con1;
}

std::list<int> & PmergeMe::con2()
{
	return _con2;
}

void PmergeMe::push(std::string lit)
{
	std::stringstream ss(lit);
	int num;

	for (std::string::iterator it = lit.begin(); it != lit.end(); ++it) {
		if (!std::isdigit(*it))
			throw WrongToken();
	}
	ss >> num;
	if (ss.fail() || num < 0)
		throw WrongToken();
	if (_con1.size() >= _size || _con2.size() >= _size)
		throw WrongToken();
	_con1.push_back(num);
	_con2.push_back(num);
}

std::vector<int> PmergeMe::sortCon1(Container1 & con)
{
	for (std::vector<int>::iterator it = con.begin(); it != con.end(); ++++it)
	{
		std::vector<int>::iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
		if (*it > *next) {
			std::iter_swap(it, next);
		}
	}

	if (con.size() <= 2)
		return con;
	std::vector<int> sorted;
	sorted.reserve(con.size() / 2);
	for (std::vector<int>::const_iterator it = ++con.begin(); it != con.end(); ++++it)
	{
		sorted.push_back(*it);

		std::vector<int>::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
	}
	sorted = sortCon1(sorted);
	sorted.reserve(con.size());
	for (std::vector<int>::const_iterator it = con.begin(); it != con.end(); ++++it)
	{
		std::vector<int>::const_iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);

		std::vector<int>::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
	}
	return sorted;
	
	// std::sort(con.begin(), con.end());
	// return con;
}

std::list<int> PmergeMe::sortCon2(Container2 & con)
{
	for (std::list<int>::iterator it = con.begin(); it != con.end(); ++++it)
	{
		std::list<int>::iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
		if (*it > *next) {
			std::iter_swap(it, next);
		}
	}

	if (con.size() <= 2)
		return con;
	std::list<int> sorted;
	for (std::list<int>::const_iterator it = ++con.begin(); it != con.end(); ++++it)
	{
		sorted.push_back(*it);

		std::list<int>::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
	}
	sorted = sortCon2(sorted);

	for (std::list<int>::const_iterator it = con.begin(); it != con.end(); ++++it)
	{
		std::list<int>::const_iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);

		std::list<int>::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end())
			break ;
	}
	return sorted;
}


// Exceptions
const char * PmergeMe::WrongToken::what() const throw()
{
	return "Error";
}