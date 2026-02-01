#pragma once

#include <iostream>
#include <exception>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), number);
	if (iter == container.end())
		throw std::runtime_error("Number not found");
	return iter;
}
