#include "PmergeMe.hpp"
#include <set>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

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
		int number = std::atoi(argv[i]);
		vect.push_back(number);
		deq.push_back(number);
	}
	if (std::set<int>(vect.begin(), vect.end()).size() != vect.size())
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	if (std::adjacent_find(vect.begin(), vect.end(), std::greater<int>()) == vect.end())
	{
		std::cout << "Container is already sorted" << std::endl;
		return;
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	clock_t vector_startTime = clock();
	fordJohnsonVector(vect);
	clock_t vector_endTime = clock();

	clock_t deque_startTime = clock();
	fordJohnsonDeque(deq);
	clock_t deque_endTime = clock();

	double timeVec = (double)(vector_endTime - vector_startTime) / CLOCKS_PER_SEC * 1e6;
	double timeDeq = (double)(deque_endTime - deque_startTime) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vect.size() <<
		" elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() <<
		" elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &vect)
{
	if (vect.size() <= 1)
		return ;

	std::vector<int> big; // vector mec tveri hamar
	std::vector<int> small; // vector poqreri hamar
	int leftover = 0;
	bool exist = false;

	for (size_t i = 0; i < vect.size(); i = i+2)
	{
		if (i + 1 < vect.size())
		{
			if (vect[i] < vect[i+1])
			{
				small.push_back(vect[i]);
				big.push_back(vect[i+1]);
			}
			else
			{
				small.push_back(vect[i+1]);
				big.push_back(vect[i]);
			}
		}
		else
		{
			leftover = vect[i];
			exist = true;
		}
	}
	
	// -> recursive sort enq anum big-i elementnery
	fordJohnsonVector(big);
	// -> himnakany sksvuma sort arac big vectorov
	std::vector<int> result = big;
	/* -> bigy arden sort araca smally parunakuma paireri poqr elementnery
	es fory hertov insert a anum smalli elementnery big-i mej*/
	for (size_t i = 0; i < small.size(); i++)
		binaryInsertVector(result, small[i]);
	// -> insert leftovery ete ka
	if (exist)
		binaryInsertVector(result, leftover);
	vect = result; // stex
}

void PmergeMe::binaryInsertVector(std::vector<int> &vect, int value) // [left, right)
{
	size_t left = 0;
	size_t right = vect.size();

	while (left < right)
	{
		int middle = (left + right) / 2;

		if (vect[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}
	vect.insert(vect.begin() + left, value);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;

	std::deque<int> big;
	std::deque<int> small;
	int leftover = 0;
	bool exist = false;

	for (size_t i = 0; i < deq.size(); i = i+2)
	{
		if (i + 1 < deq.size())
		{
			if (deq[i] < deq[i+1])
			{
				small.push_back(deq[i]);
				big.push_back(deq[i+1]);
			}
			else
			{
				small.push_back(deq[i+1]);
				big.push_back(deq[i]);
			}
		}
		else
		{
			leftover = deq[i];
			exist = true;
		}
	}
	// -> nuyn logikan u qaylery voronq vectori hamar
	fordJohnsonDeque(big);
	std::deque<int> result = big;
	for (size_t i = 0; i < small.size(); i++)
		binaryInsertDeque(result, small[i]);
	if (exist)
		binaryInsertDeque(result, leftover);
	deq = result;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &deq, int value)
{
	size_t left = 0;
	size_t right = deq.size();

	while (left < right)
	{
		int middle = (left + right) / 2;

		if (deq[middle] < value)
			left = middle + 1;
		else
			right = middle;
	}
	deq.insert(deq.begin() + left, value);
}