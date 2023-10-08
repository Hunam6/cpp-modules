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
	int isValidValue(const std::string &str, double *result);
	bool isValidLong(const std::string &str, long *result);
	bool isValidDouble(const std::string &str, double *result);

	void printRate(const std::string &original_date, const std::string &date,
				   const std::string &original_value, double value);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	void search(const std::string &line);
};

#endif
