#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int n;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();

	Array &operator=(const Array &other);
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

	unsigned int size() const;
};

#include "../srcs/Array.tpp"
#endif
