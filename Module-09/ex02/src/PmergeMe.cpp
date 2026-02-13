#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

// https://excalidraw.com/#json=yLrTRmUXbJVmdcHNLBvcL,pgYC-2GXKG937B0pz04CyA

inline std::string printSequence(const std::vector<int>& seq) {
	std::stringstream result;
	for (size_t i = 0; i < seq.size(); ++i) {
		result << seq[i];
		if (i < seq.size() - 1) {
			result << " ";
		}
	}
	return result.str();
}

inline std::string printSequence(const std::deque<int>& seq) {
	std::stringstream result;
	for (size_t i = 0; i < seq.size(); ++i) {
		result << seq[i];
		if (i < seq.size() - 1) {
			result << " ";
		}
	}
	return result.str();
}

PmergeMe::PmergeMe(char *argv[])
{
	// ** PARSE ARGS **
	std::vector<std::string> args;
	for (int i = 1; argv[i]; ++i)
	{
		std::vector<std::string> split_args = PmergeMe::split(PmergeMe::trim(argv[i]), " \t\n\r");
		args.insert(args.end(), split_args.begin(), split_args.end());
	}

	// ** FILL CONTAINERS **
	std::vector<int> arr_vector;
	std::deque<int> arr_deque;
	typedef typename std::vector<std::string>::iterator it_vector;
	for (it_vector it = args.begin(); it != args.end(); ++it)
	{
		int value = PmergeMe::atoi(*it);
		if (value < 0)
			throw std::invalid_argument("negative number: " YEL + *it);
		arr_vector.push_back(value);
		arr_deque.push_back(value);
	}


	
	// ** SORT vector **
	clock_t start = clock();
	std::vector<int> arr_vec_sorted = fordJohnsonSort(arr_vector);
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	
	
	
	// ** SORT DEQUE **
	clock_t start_deque = clock();
	std::deque<int> arr_deque_sorted = fordJohnsonSort(arr_deque);
	clock_t end_deque = clock();
	double elapsed_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC;
	
	

	// ** PRINT RESULTS **
	std::cout << MAG "Before:\t" YEL << printSequence(arr_vector) << RESET << std::endl;
	std::cout << MAG "After:\t" GRN << printSequence(arr_vec_sorted) << RESET << std::endl;
	std::cout << MAG "Time to process a range of " RESET << arr_vector.size() << MAG " elements with " BLU "std::vector" MAG " : " RESET << std::fixed << std::setprecision(6) << elapsed << " us" << std::endl;
	std::cout << MAG "Time to process a range of " RESET << arr_deque.size() << MAG " elements with " BLU "std::deque" MAG " : " RESET << std::fixed << std::setprecision(6) << elapsed_deque << " us" << std::endl;

}

// -------------------------------------------- UTILS --------------------------------------------

std::string PmergeMe::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

std::string PmergeMe::trim(const char* str)
{
	return PmergeMe::trim(std::string(str));
}


int PmergeMe::atoi(std::string str)
{
	int value;
	std::istringstream iss(str);

	iss >> value;

	if (iss.fail())
		throw std::invalid_argument("bad input: " YEL + str);

	return (value);
}


std::vector<std::string> PmergeMe::split(const std::string &s, const char *delimiters)
{
	std::vector<std::string> tokens;
	size_t start = 0;
	size_t end = s.find_first_of(delimiters);

	while (end != std::string::npos)
	{
		int n = 1;
		while (end + n < s.size() && std::string(delimiters).find(s[end + n]) != std::string::npos)
			++n;
		tokens.push_back(s.substr(start, end - start));
		start = end + n;
		end = s.find_first_of(delimiters, start);
	}
	tokens.push_back(s.substr(start));
	return tokens;
	
}

// ------------------------------------------ FUNCTIONS ------------------------------------------

std::vector<int> PmergeMe::jacobsthalSequence(int n) {
    std::vector<int> seq;
    if (n <= 0) return seq;

    seq.push_back(0);
    if (n == 1) return seq;

    seq.push_back(1);

    while (seq.back() < n) {
        int size = seq.size();
        seq.push_back(seq[size - 1] + 2 * seq[size - 2]);
    }

    return seq;
}