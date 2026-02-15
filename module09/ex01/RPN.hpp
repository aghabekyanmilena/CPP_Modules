#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
private:
	RPN(const RPN &);
	RPN &operator=(const RPN &);
public:
	RPN();
	~RPN();

	int solve(std::string expression);
};