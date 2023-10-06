#include "ScalarConverter.hpp"
#include <iostream>

size_t ScalarConverter::ft_strlen(const char *str)
{
	int len = 0;
	while (*str++)
		len++;
	return len;
}

int ScalarConverter::robustAtoi(const char *str, bool *errored)
{
	errno = 0;
	long result = strtol(str, NULL, 10);

	if (errno != 0)
	{
		*errored = true;
		return static_cast<int>(result);
	}

	if (result > INT_MAX || result < INT_MIN)
	{
		*errored = true;
		return static_cast<int>(result);
	}

	*errored = false;
	return static_cast<int>(result);
}

ScalarConverter::type ScalarConverter::getType(const char *str)
{
	const size_t str_len = ft_strlen(str);

	if (str_len == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;

	bool dotFound = false;
	size_t i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str_len; i++)
	{
		if (str[i] == '.')
		{
			if (dotFound || i == str_len - 1)
				return INVALID;
			dotFound = true;
		}
		else if (str[i] == 'f')
		{
			if (i != str_len - 1)
				return INVALID;
			return REAL;
		}
		else if (!('0' <= str[i] && str[i] <= '9'))
			return INVALID;
	}
	return dotFound ? REAL : INT;
}

void ScalarConverter::printChar(const int num, const bool errored)
{
	if (errored || num < 0 || num > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (num <= 32)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
}

void ScalarConverter::printInt(const int num, const bool errored)
{
	if (errored)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << num << '\n';
}

void ScalarConverter::printReal(const double num, const bool is_float, const bool errored)
{
	if (is_float)
		std::cout << "float: ";
	else
		std::cout << "double: ";

	if (errored)
	{
		std::cout << "impossible\n";
		return;
	}

	if (is_float)
		std::cout << static_cast<float>(num);
	else
		std::cout << num;

	if (num == static_cast<int>(num))
		std::cout << ".0";
	if (is_float)
		std::cout << "f";

	std::cout << '\n';
}

void ScalarConverter::printInvalid()
{
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible\n";
}

bool ScalarConverter::handlePseudoLiterals(const std::string &str)
{
	if (str.empty())
		printInvalid();
	else if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: nanf\n"
				  << "double: nan\n";
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: -inff\n"
				  << "double: -inf\n";
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible\n"
				  << "int: impossible\n"
				  << "float: inff\n"
				  << "double: inf\n";
	}
	else
		return false;
	return true;
}

void ScalarConverter::handleChar(const char *str)
{
	const u_char _char = str[1];

	printChar(_char, false);
	printInt(static_cast<int>(_char), false);
	printReal(static_cast<float>(_char), true, false);
	printReal(static_cast<double>(_char), false, false);
}

void ScalarConverter::handleInt(const char *str)
{
	bool errored;
	const int _int = robustAtoi(str, &errored);

	printChar(_int, errored);
	printInt(_int, errored);
	printReal(static_cast<float>(_int), true, false);
	printReal(static_cast<double>(_int), false, false);
}

void ScalarConverter::handleReal(const char *str)
{
	bool errored;
	const int _int = robustAtoi(str, &errored);

	printChar(_int, errored);
	printInt(_int, errored);

	errno = 0;
	const double real = std::strtod(str, NULL);
	printReal(static_cast<float>(real), true, errno != 0);
	printReal(real, false, errno != 0);
}

void ScalarConverter::convert(const char *literal)
{
	if (handlePseudoLiterals(literal))
		return;

	switch (getType(literal))
	{
	case CHAR:
		handleChar(literal);
		break;
	case INT:
		handleInt(literal);
		break;
	case REAL:
		handleReal(literal);
		break;
	default:
		printInvalid();
	}
}
