#pragma once

#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, double> data;

	int is_valid_date(const std::string &data) const;
	int is_valid_value(const std::string &value, double &result) const;
	std::string trim(const std::string &str) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	int load_data(const std::string &file);
	void process_input(const std::string file);
	double get_rate(const std::string &date) const;
};