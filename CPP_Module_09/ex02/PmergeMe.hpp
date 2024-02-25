#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

# define ERROR_MESSAGE "Error"
# define MAXIMUN_NUMBER_OF_OUTPUTS 10
# define OMIT_MARK " [...]"

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PmergeMe &assign);

		const size_t _size;
		std::vector<int> _vectorContainer;
		std::list<int> _listContainer;

	public:
		PmergeMe(int size);
		~PmergeMe();

		/*****************************************/

		size_t getSize() const;
		std::vector<int>& getVectorContainer();
		std::list<int>& getListContainer();

		/*****************************************/

		void pushToEachCon(std::string input);
		static std::vector<int> sortVectorContainer(std::vector<int> & container);
		static std::list<int> sortListContainer(std::list<int> & container);

		/*****************************************/

		template<class T>
		static std::string print(const T & container);
		template<class T>
		static std::clock_t benchMark(T & container, T (*sort)(T &));

		/*****************************************/

		class invalidInput : public std::exception {
			virtual const char* what() const throw();
		};
};

/*****************************************/

template <class T>
std::string PmergeMe::print(const T &container)
{
	std::ostringstream ss;

	size_t num = 0;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (++num > MAXIMUN_NUMBER_OF_OUTPUTS) {
			ss << OMIT_MARK;
			break;
		}
		ss << ' ' << *it;
	}
	return ss.str();
}

/*****************************************/

template <class T>
std::clock_t PmergeMe::benchMark(T &container, T (*sort)(T &))
{
	std::clock_t startTime = std::clock();
	container = sort(container);
	std::clock_t endTime = std::clock();

	return endTime - startTime;
}

#endif

