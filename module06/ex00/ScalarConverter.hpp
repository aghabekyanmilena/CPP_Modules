#pragma once

#include <iostream>
#include <string>
// #include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter operator=(const ScalarConverter &other);
	~ScalarConverter();
public:
	static void convert(const std::string &literal);
};