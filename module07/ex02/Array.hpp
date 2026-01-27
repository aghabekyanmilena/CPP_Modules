#pragma once

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T *data;
	unsigned int size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int getsize() const;
};

#include "Array.tpp"