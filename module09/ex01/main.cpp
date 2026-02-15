#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn;
		std::cout << rpn.solve(av[1]) << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
	}
}
