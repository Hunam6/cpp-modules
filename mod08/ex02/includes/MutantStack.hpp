#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	class iterator : public std::iterator<std::input_iterator_tag, T>
	{
	private:
		const MutantStack &stack;
		int idx;
		bool isEnd;
		const T nil;

	public:
		// TODO: check consts in args and return vals
		// TODO: impl everything is separate file for Mr. norm
		iterator(MutantStack &stack, int idx, bool isEnd = false)
			: stack(stack), idx(idx), isEnd(isEnd), nil(T()) {}
		iterator &operator++()
		{
			if (isEnd)
			{
				isEnd = false;
				idx = 0;
			}
			else
				++idx;
			if (idx == static_cast<int>(stack.size()))
				isEnd = true;
			return *this;
		}
		iterator operator++(int)
		{
			iterator out = *this;
			++(*this);
			return out;
		}
		iterator &operator--()
		{
			if (isEnd)
			{
				isEnd = false;
				idx = stack.size() - 1;
			}
			else
				--idx;
			if (idx == -1)
				isEnd = true;
			return *this;
		}
		iterator operator--(int)
		{
			iterator out = *this;
			--(*this);
			return out;
		}
		bool operator==(iterator other) const
		{
			if (isEnd || other.isEnd)
				return isEnd == other.isEnd;
			return stack.c[idx] == other.stack.c[idx];
		}
		bool operator!=(iterator other) const
		{
			return !(*this == other);
		}
		const T &operator*() const
		{
			return isEnd ? nil : stack.c[idx];
		}
	};
	iterator begin()
	{
		if (this->size() == 0)
			return end();
		return iterator(*this, 0);
	}
	iterator end() { return iterator(*this, 0, true); }
};

#endif
