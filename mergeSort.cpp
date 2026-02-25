#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vc, int left, int middle, int right)
{
	int left_size = middle - left + 1;
	int right_size = right - middle;

	vector<int> left_tmp(left_size);
	vector<int> right_tmp(right_size);

	for (int i = 0; i < left_size; i++) // copy left half
		left_tmp[i] = vc[left+i];
	for (int j = 0; j < right_size; j++) // copy right half
		right_tmp[j] = vc[1+j+middle];
	
	int i = 0; // index for left
	int j = 0; // index for right
	int k = left; // index for original array

	while (i < left_size && j < right_size)
	{
		if (left_tmp[i] <= right_tmp[j])
		{
			vc[k] = left_tmp[i];
			i++;
		}
		else
		{
			vc[k] = right_tmp[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		vc[k] = left_tmp[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		vc[k] = right_tmp[j];
		j++;
		k++;
	}
}

void merge_sort(vector<int> &vect, int left, int right)
{
	if (left >= right)
		return;
	int middle = (left + right) / 2;
	merge_sort(vect, left, middle);
	merge_sort(vect, middle + 1, right);

	merge(vect, left, middle, right);
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

	merge_sort(vect, 0, vect.size() - 1);

	std::cout << "After:  ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;

	return 0;
}