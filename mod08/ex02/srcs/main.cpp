#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <iomanip>

// the sentinel value used by end() is not standard,
// but rather implementation-defined,
// that's why I put "whatever" for the expected output

int main()
{
	// empty stack
	MutantStack<int> stack1;
	std::cout << *stack1.begin();						   // 0
	std::cout << *stack1.end();							   // whatever
	std::cout << (stack1.begin() == stack1.end()) << "\n"; // 1

	MutantStack<int>::iterator it1 = stack1.begin();
	it1--;
	std::cout << (it1 == stack1.end()); // 1
	--it1;
	std::cout << (it1 == stack1.end()); // 1
	++it1;
	std::cout << (it1 == stack1.end()); // 1
	it1++;
	std::cout << (it1 == stack1.end()) << "\n\n"; // 1

	// stack with first el a zero
	MutantStack<int> stack2;
	stack2.push(0);
	std::cout << *stack2.begin();						   // 0
	std::cout << *stack2.end();							   // whatever
	std::cout << (stack2.begin() == stack2.end()) << "\n"; // 0

	MutantStack<int>::iterator it2 = stack2.begin();
	std::cout << (stack2.begin() == it2); // 1
	it2++;
	std::cout << (stack2.end() == it2); // 1
	it2++;
	std::cout << (stack2.begin() == it2) << "\n\n"; // 1

	// stack with complex type std::string
	MutantStack<std::string> stack3;
	stack3.push("a");
	stack3.push("b");
	stack3.push("c");
	std::cout << *stack3.begin();						   // a
	std::cout << *stack3.end();							   // whatever
	std::cout << (stack3.begin() == stack3.end()) << "\n"; // 0

	MutantStack<std::string>::iterator it3 = stack3.begin();
	std::cout << (stack3.begin() == it3); // 1
	it3--;
	std::cout << (stack3.end() == it3); // 1
	it3--;
	std::cout << ("c" == *it3) << "\n\n"; // 1

	// methods testing
	MutantStack<int> stack4;
	stack4.push(0);
	std::cout << stack4.top() << std::endl; // 0
	stack4.pop();
	std::cout << stack4.size() << std::endl; // 0
	stack4.push(3);
	stack4.push(5);
	stack4.push(737);
	stack4.push(0);

	MutantStack<int>::iterator it = stack4.begin();
	MutantStack<int>::iterator ite = stack4.end();
	--it;
	++it;
	while (it != ite)
	{
		std::cout << *it << " "; // 3 5 737 0
		++it;
	}

	// create a std::stack from a MutantStack
	std::stack<int> s(stack4);
}
