#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

typedef std::vector<int> Container1;
typedef std::list<int> Container2;

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PmergeMe &assign);

		const size_t _size;
		std::vector<int> _con1;
		std::list<int> _con2;

	public:
		PmergeMe(int size);
		~PmergeMe();
		// Exceptions
		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};

		size_t size() const;
		std::vector<int>& con1();
		std::list<int>& con2();

		void push(std::string lit);
		static std::vector<int> sortCon1(Container1 & con);
		static std::list<int> sortCon2(Container2 & con);

		template<class T>
		static std::string print(const T & con);

		template<class T>
		static std::clock_t bench(T & con, T (*sort)(T &));

};

template <class T>
std::string PmergeMe::print(const T &con)
{
	std::ostringstream ss;

	size_t num = 0;
	for (typename T::const_iterator it = con.begin(); it != con.end(); ++it)
	{
		if (++num > 10) {
			ss << "\t [...]";
			break;
		}
		ss << '\t' << *it;
	}
	return ss.str();
}

template <class T>
std::clock_t PmergeMe::bench(T &con, T (*sort)(T &))
{
	std::clock_t start = std::clock();
	con = sort(con);
	std::clock_t end = std::clock();
	return end - start;
}

#endif

