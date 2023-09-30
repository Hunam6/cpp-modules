#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
	: arr(new T[0]), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
	: arr(new T[n]), n(n) {}

template <typename T>
Array<T>::Array(const Array &other)
	: arr(new T[other.n]), n(other.n)
{
	for (unsigned int i = 0; i < other.n; i++)
		arr[i] = other.arr[i];
}
template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	delete[] arr;
	arr = new T[other.n];
	n = other.n;
	for (unsigned int i = 0; i < other.n; i++)
		arr[i] = other.arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (n == 0 || i < 0 || i > n - 1)
		throw std::out_of_range("out of bounds");
	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return n;
}
