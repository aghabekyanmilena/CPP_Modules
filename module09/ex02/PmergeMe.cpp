#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generate(size_t n) // ???
{
	std::vector<size_t> ban;
	if (n == 0)
		return ban;

	ban.push_back(1);
	if (n == 1)
		return ban;

	size_t j1 = 1;
	size_t j2 = 0;

	while (true)
	{
		size_t next = j1 + 2 * j2;
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