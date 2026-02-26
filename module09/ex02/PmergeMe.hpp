#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>
#include <string>
#include <sstream>

class PmergeMe
{
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void fordJohnsonVector(std::vector<int> &vect);
	void fordJohnsonDeque(std::deque<int> &deq);

	void binaryInsertVector(std::vector<int> &vect, int value);
	void binaryInsertDeque(std::deque<int> &deq, int value);

	bool valid_number(const std::string &str);
	std::vector<int> generate(int n);
public:
	PmergeMe();
	~PmergeMe();

	void process(char **argv);
};

/* deque
deque-ն double-ended queue ա որը հնարավորությունա տալիս էլեմենտերն ինսեռտ անել ու ջնջել
համ սկզբից համ վերջից, stack֊ի ու queue֊ի ընդհանրացնումնա
*/

/*
J(n) = J(n-1) + 2 * J(n-2)
*/

/* resources for an algorithm
https://en.wikipedia.org/wiki/Merge-insertion_sort#Algorithm
https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

book by Donald Knuth (vol 3, page 184)
https://vivekupadhyay125.wordpress.com/wp-content/uploads/2013/08/donald-e-knuth-the-art-of-computer-programming-vol-3.pdf
*/