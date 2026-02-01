#include "Array.hpp"

int main()
{
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	Array<int> b = a;
	b[0] = 42;

	std::cout << a[0] << " " << b[0] << std::endl;

	try
	{
		std::cout << a[0] << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "out of range" << std::endl;
	}

	return 0;
}