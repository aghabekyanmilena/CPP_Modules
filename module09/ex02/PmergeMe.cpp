#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generate(int n) // Jacobsthal order -> es funcy insertioni hertakanutyuny talu hamara
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

	for (size_t i = 0; i < vect.size(); i = i+2) // aystex
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

	// 2rd qaylov recursive sort enq anum big-i elementnery
	fordJohnsonVector(big);

	// 3rd qayl himnakany sksvuma sort arac big vectorov
	std::vector<int> result = big;

	// 4rd qayl generate functionov generate enq anum insertioni hertakanutyuny
	// std::vector<int> order = generate(small.size());

	// // 5rd qayl -> insert enq anum smalli elementnery
	// for (size_t i = 0; i < order.size(); i++)
	// {
	// 	size_t index = order[i];
	// 	if (index < small.size())
	// 		binaryInsertVector(result, small[index]);
	// }

	for (size_t i = 0; i < small.size(); i++)
	{
		binaryInsertVector(result, small[i]);
	}
	// 6rd qayl insert leftovery ete ka
	if (exist)
		binaryInsertVector(result, leftover);
	vect = result; // stex
}

void PmergeMe::binaryInsertVector(std::vector<int> &vect, int value)
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

	for (size_t i = 0; i < deq.size(); i = i+2) // aystex
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
	// nuyn logikan u qaylery voronq vectori hamar
	fordJohnsonDeque(big);
	std::deque<int> result = big;
	// std::vector<int> order = generate(small.size());
	// for (size_t i = 0; i < order.size(); i++)
	// {
	// 	size_t index = order[i];
	// 	if (index < small.size())
	// 		binaryInsertDeque(result, small[index]);
	// }
	for (size_t i = 0; i < small.size(); i++)
	{
		binaryInsertDeque(result, small[i]);
	}
	if (exist)
		binaryInsertDeque(result, leftover);
	deq = result; // stex
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