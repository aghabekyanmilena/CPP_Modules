#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& vect)
{
	for (int i = 1; i < vect.size(); i++)
	{
		int tmp = vect[i];
		int j = i - 1;

		while (j >= 0 && vect[j] > tmp)
		{
			vect[j + 1] = vect[j];
			j--;
		}
		vect[j+1] = tmp;
	}
}

int main()
{
	std::vector<int> vect;

	vect.push_back(5);
	vect.push_back(2);
	vect.push_back(9);
	vect.push_back(1);
	vect.push_back(3);

	std::cout << "Before: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	insertion_sort(vect);

	std::cout << "After:  ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	return 0;
}