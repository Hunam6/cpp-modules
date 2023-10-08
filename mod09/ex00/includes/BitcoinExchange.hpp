#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> db;

	bool isValidDate(const std::string &str);
	bool isValidYearMonthDay(long year, int month, int day);
	bool isValidLong(const std::string &str, long *result);
	bool isValidDouble(const std::string &str, double *result);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void search(std::string *error);
};

#endif
