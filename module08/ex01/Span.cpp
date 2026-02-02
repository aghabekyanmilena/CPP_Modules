#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		data = other.data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (data.size() > N)
		throw std::runtime_error("Span is full");
	data.push_back(number);
}


int Span::shortestSpan() const
{
	if (data.size() < 2)
		throw std::runtime_error("Not enough elements");

	std::vector<int> tmp = data;
	std::sort(tmp.begin(), tmp.end());

	int min = std::numeric_limits<int>::max();

	for (size_t i = 1; i < tmp.size(); ++i)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < min)
			min = diff;
	}

	return min;
}

int Span::longestSpan() const
{
	if (data.size() < 2)
		throw std::runtime_error("Not enough elements");

	int minVal = *std::min_element(data.begin(), data.end());
	int maxVal = *std::max_element(data.begin(), data.end());

	return maxVal - minVal;
}