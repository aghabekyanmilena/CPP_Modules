#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &) {}
RPN &RPN::operator=(const RPN &) {return *this;}

static bool is_oprtator(const std::string op)
{
	return op.length() == 1 && 
		(op[0] == '+' || op[0] == '-' ||
		op[0] == '*' || op[0] == '/');
}

static int apply_operation(int a, int b, char op)
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("division by 0");
			return a / b;
	}
	throw std::runtime_error("Wrong operator");
}

int RPN::solve(std::string expression)
{
	std::stack<int> st;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (is_oprtator(token))
		{
			if (st.size() < 2)
				throw std::runtime_error("Bad expression");
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();
	
			st.push(apply_operation(a, b, token[0]));
		}
		else
		{
			if (token.length() != 1 || !isdigit(token[0]))
				throw std::runtime_error("Bad token");

			st.push(token[0] - '0');
		}
	}

	if (st.size() != 1)
		throw std::runtime_error("Bad expression");
	return st.top();
}