#include "iter.hpp"

int main()
{
		int		array[] = {42, 57, 17, -28, -7};
		int		size = sizeof(array) / sizeof(array[0]);

		iter(array, size, print_int);

		std::cout << std::endl;
}