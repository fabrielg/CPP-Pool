#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator result = std::find(container.begin(), container.end(), toFind);

	if (result == container.end())
		throw std::runtime_error("Value not found");
	return (result);
}
