#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
private:
	unsigned int N; // max size
	std::vector<int> data;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number); // adds number to Span

	template <typename T>
	void addRange(T begin, T end)
	{
		unsigned int distance = std::distance(begin, end);
		if (data.size() + distance > N)
			throw std::runtime_error("Span is full");
		data.insert(data.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;
};