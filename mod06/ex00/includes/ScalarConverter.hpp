#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter
{
private:
	typedef enum
	{
		CHAR,
		INT,
		REAL,
		INVALID
	} type;
	static size_t ft_strlen(const char *str);
	static int robustAtoi(const char *str, bool *errored);
	static type getType(const char *str);

	static void printChar(const int num, const bool errored);
	static void printInt(const int num, const bool errored);
	static void printReal(const double num, const bool is_float, const bool errored);
	static void printInvalid();

	static bool handlePseudoLiterals(const std::string &str);
	static void handleChar(const char *str);
	static void handleInt(const char *str);
	static void handleReal(const char *str);

public:
	static void convert(const char *literal);
};

#endif
