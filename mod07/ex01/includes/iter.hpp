#pragma once
#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

template <typename T>
void iter(T arr[], size_t len, void func(const T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
