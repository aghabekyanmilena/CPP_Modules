#include "easyfind.hpp"

int main()
{
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(-3);
	lst.push_back(0);
	lst.push_back(2);
	lst.push_back(5);
	lst.push_back(3);

	try
	{
		std::list<int>::iterator i = easyfind(lst, 2);
		std::cout << "Number found in list: " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator i = easyfind(lst, 9);
		std::cout << "Number found in list: " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}