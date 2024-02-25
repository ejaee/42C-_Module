#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(int size): _size(size)
{
	if (_size < 1) throw invalidInput();

	_vectorContainer.reserve(_size);
}

PmergeMe::~PmergeMe()
{
}

/*****************************************/

size_t PmergeMe::getSize() const
{
	return _size;
}

std::vector<int>& PmergeMe::getVectorContainer()
{
	return _vectorContainer;
}

std::list<int> & PmergeMe::getListContainer()
{
	return _listContainer;
}

/*****************************************/

void PmergeMe::pushToEachCon(std::string input)
{
	std::stringstream ss(input);
	int num;

	for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
		if (!std::isdigit(*it)) throw invalidInput();
	}
	ss >> num;

	if (ss.fail() || num < 0) throw invalidInput();
	if (_vectorContainer.size() >= _size || _listContainer.size() >= _size) throw invalidInput();

	_vectorContainer.push_back(num);
	_listContainer.push_back(num);
}

std::vector<int> PmergeMe::sortVectorContainer(std::vector<int> & container)
{
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++++it)
	{
		std::vector<int>::iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
		
		if (*it > *next) std::iter_swap(it, next);
	}

	if (container.size() <= 2) return container;

	std::vector<int> sortedContainer;
	sortedContainer.reserve(container.size() / 2);
	for (std::vector<int>::const_iterator it = ++container.begin(); it != container.end(); ++++it)
	{
		sortedContainer.push_back(*it);

		std::vector<int>::const_iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
	}

	sortedContainer = sortVectorContainer(sortedContainer);
	sortedContainer.reserve(container.size());
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++++it)
	{
		std::vector<int>::const_iterator pos = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), *it);
		sortedContainer.insert(pos, *it);

		std::vector<int>::const_iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
	}
	return sortedContainer;
}

std::list<int> PmergeMe::sortListContainer(std::list<int> & container)
{
	for (std::list<int>::iterator it = container.begin(); it != container.end(); ++++it)
	{
		std::list<int>::iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
		
		if (*it > *next) std::iter_swap(it, next);
	}

	if (container.size() <= 2)
		return container;
	std::list<int> sortedContainer;
	for (std::list<int>::const_iterator it = ++container.begin(); it != container.end(); ++++it)
	{
		sortedContainer.push_back(*it);

		std::list<int>::const_iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
	}
	sortedContainer = sortListContainer(sortedContainer);

	for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++++it)
	{
		std::list<int>::const_iterator pos = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), *it);
		sortedContainer.insert(pos, *it);

		std::list<int>::const_iterator next = it;

		std::advance(next, 1);
		if (next == container.end()) break ;
	}
	return sortedContainer;
}


const char * PmergeMe::invalidInput::what() const throw()
{
	return ERROR_MESSAGE;
}