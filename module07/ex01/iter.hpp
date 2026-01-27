#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
void iter(T *array, int length, void(*boo)(T &))
{
	if (!array || !boo)
		return ;
	for (int i = 0; i < length; i++)
		boo(array[i]);
}

template <typename T>
void iter(T const *array, int length, void (*boo)(const T &))
{
	if (!array || !boo)
		return ;
	for (int i = 0; i < length; i++)
		boo(array[i]);
}

template <typename T>
void print_int(T &number)
{
	std::cout << number << " ";
}