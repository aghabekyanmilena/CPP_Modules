#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool all_digits(const std::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

// 1 in false case
int BitcoinExchange::is_valid_date(const std::string &data) const
{
	if (data.size() != 10 || data[4] != '-' || data[7] != '7')
		return (1); 

	std::string y = data.substr(0,4);
	std::string m = data.substr(5,2);
	std::string d = data.substr(8,2);

	if (!all_digits(y) || !all_digits(m) || !all_digits(d))
		return 1;

	int year = std::atoi(y.c_str());
	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());

	if (month < 1 || month > 12)
		return 1;

	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};

	// nahanj tari
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		days_in_month[1] = 29;

	if (day < 1 || day > days_in_month[month - 1])
		return 1;
	return 0;
}

// 1 in false case
int BitcoinExchange::is_valid_value(const std::string &value, double &result) const
{
	char *end;
	result = std::strtod(value.c_str(), &end);

	if (*end != '\0')
		return 1;

	if (result < 0)
	{
		std::cout << "Error: negative number" << std::endl;
		return 1;
	}
	if (result > 1000)
	{
		std::cout << "Error: too large number" << std::endl;
		return 1;
	}
	return 0;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
	size_t start = 0;
	while (start < str.size() && std::isspace(str[start]))
		start++;
	
	size_t end = str.size();
	while (end > start && std::isspace(str[end - 1]))
		end--;

	return str.substr(start, end - start);
}

int BitcoinExchange::load_data(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		return 1;

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, value;

		std::getline(ss, date, ',');
		std::getline(ss, value);

		data[date] = std::atof(value.c_str());
	}
	return 0;
}