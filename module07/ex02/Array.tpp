#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(NULL), size(other.size)
{
	if (size > 0)
	{
		data = new T[size];
		for (unsigned int i = 0; i < size; i++)
			data[i] = other.data[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		if (other.size == 0)
			data = NULL;
		else
		{
			data = new T[other.size];
			for (unsigned int i = 0; i < other.size; i++)
				data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= size)
		throw std::exception();
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= size)
		throw std::exception();
	return data[index];
}

template <typename T>
unsigned int Array<T>::getsize() const
{
	return size;
}