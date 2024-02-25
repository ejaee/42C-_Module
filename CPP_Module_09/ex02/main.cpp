#include <iostream>
#include "PmergeMe.hpp"

int	validate_arg(int argc, char *argv[]) {
	if (argc < 2 || argv == NULL) {
		std::cout << ERROR_MESSAGE << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (validate_arg(argc, argv)) {
		return 1;
	}

	try
	{
		PmergeMe pm(argc - 1);
		for (int i = 1; i < argc; i++)
		{
			pm.pushToEachCon(argv[i]);
		}

		std::cout << "Before: " << PmergeMe::print(pm.getVectorContainer()) << std::endl;
		
		std::clock_t time_list = PmergeMe::benchMark(pm.getListContainer(), PmergeMe::sortListContainer);

		std::cout << "After:  " << PmergeMe::print(pm.getListContainer()) << std::endl;

		std::clock_t time_vec = PmergeMe::benchMark(pm.getVectorContainer(), PmergeMe::sortVectorContainer);

		std::cout << "Time to process a range of " << pm.getSize() << " elements with std::vector<int> : " << time_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << pm.getSize() << " elements with std::list<int> : " << time_list << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}