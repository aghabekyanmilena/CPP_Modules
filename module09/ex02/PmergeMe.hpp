#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>
#include <string>

class PmergeMe
{
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void fordJohnsonVector(std::vector<int> &vect);
	void fordJohnsonDeque(std::deque<int> &deq);

	void binaryInsertVector(std::vector<int> &vect);
	void binaryInsertDeque(std::deque<int> &deq);

	bool valid_number(const std::string &str);
	std::vector<size_t> generate(size_t n);
public:
	PmergeMe();
	~PmergeMe();

	void process(char **argv);
};

/* deque
deque-ն double-ended queue ա որը հնարավորությունա տալիս էլեմենտերն ինսեռտ անել ու ջնջել
համ սկզբից համ վերջից, stack֊ի ու queue֊ի ընդհանրացնումնա
*/