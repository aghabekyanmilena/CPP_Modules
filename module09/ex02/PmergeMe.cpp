#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generate(int n) // ???
{
	std::vector<int> ban;
	if (n == 0)
		return ban;

	ban.push_back(1);
	if (n == 1)
		return ban;

	int j1 = 1;
	int j2 = 0;

	while (true)
	{
		int next = j1 + 2 * j2;
		if (next > n)
			break;
		ban.push_back(next);
		j2 = j1;
		j1 = next;
	}
	return ban;
}

bool PmergeMe::valid_number(const std::string &str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	long number = std::strtol(str.c_str(), NULL, 10);
	if (number > INT_MAX)
		return false;
	return true;
}

void PmergeMe::process(char **argv)
{
	std::vector<int> vect;
	std::deque<int> deq;

	for (int i = 1; argv[i]; i++)
	{
		if (!valid_number(argv[i]))
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		// karelia strstreamov anel et heto kmtacem arji poxem te che
		int number = std::atoi(argv[i]);
		vect.push_back(number);
		deq.push_back(number);
	}

	std::cout << "Befor: ";
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;

	clock_t vector_startTime = clock();
	fordJohnsonVector(vect);
	clock_t vector_endTime = clock();

	clock_t deque_startTime = clock();
	fordJohnsonDeque(deq);
	clock_t deque_endTime = clock();

	double timeVec = (double)(vector_endTime - vector_startTime) / CLOCKS_PER_SEC * 1e6;
	double timeDeq = (double)(deque_endTime - deque_startTime) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << vect.size() <<
		" elements with std::vector : " << timeVec << "us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() <<
		" elements with std::deque : " << timeDeq << "us" << std::endl;
}