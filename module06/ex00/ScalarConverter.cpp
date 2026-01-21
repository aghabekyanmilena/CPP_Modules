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

// print
static bool print_special_cases(const std::string &str)
{
	// print linox charer
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && !std::isdigit(str[0]))
	{
		char c = str[0];

		std::cout << "char: '" << static_cast<char>(c) << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << ".0f\n";
		std::cout << "double: " << static_cast<double>(c) << ".0\n";
		return true;
	}

	// nan kam nanf
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}

	// +-inf(f)
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}

	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}

static void print_char(double ch)
{
	if (ch < 0 || ch > 127)
		std::cout << "char: impossible" << std::endl;
	else if (ch < 32 || ch == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(ch) << "'\n";
}

static void print_int(double i)
{
	if (i < std::numeric_limits<int>::min()
		|| i > std::numeric_limits<int>::max() || std::isnan(i))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
}

static void print_float(double d)
{
	float f = static_cast<float>(d);

	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
	{
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
}

static void print_double(double d)
{
	if (std::isnan(d))
		std::cout << "double: nan\n";
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0" << std::endl;
		else
			std::cout << "\n";
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (print_special_cases(literal))
		return ;
	
	std::stringstream ss(literal);

	double value;

	ss >> value; 
	if (ss.fail())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}

	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}

// creates a stream object, loads the contents of literal into it
// receive the converted number and stores in value