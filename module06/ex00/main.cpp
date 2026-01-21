#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string conv(argv[1]);
		ScalarConverter::convert(conv);
	}
	else
		std::cerr << "Needed 1 parameter" << std::endl;
	return (0);
}