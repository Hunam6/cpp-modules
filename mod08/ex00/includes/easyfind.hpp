#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

template <typename T>
typename T::value_type &easyfind(T arr, int to_find)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), to_find);
	if (it != arr.end())
		return *it;

	throw std::runtime_error("Element not found.");
}
#endif
