#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}