#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	// open file
	std::ifstream data_csv("data.csv");
	if (!data_csv)
		(std::cerr << "Error: cannot read data.csv\n", exit(1));
	// check header
	std::string line;
	std::getline(data_csv, line);
	if (line != "date,exchange_rate")
		(std::cerr << "Error: no valid header in data.csv\n", exit(1));
	while (42)
	{
		// check date
		std::string date;
		if (!std::getline(data_csv, date, ','))
			break;
		if (!isValidDate(date))
			(std::cerr << "Error: invalid date in data.csv\n", exit(1));
		// check value
		std::string raw_value;
		if (!std::getline(data_csv, raw_value) || raw_value.empty())
			(std::cerr << "Error: invalid line in data.csv\n", exit(1));
		double value;
		if (!isValidDouble(raw_value, &value))
			(std::cerr << "Error: invalid value in data.csv\n", exit(1));
		// add to db
		db[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: db(other.db) {} // TODO: check deep copy

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	db = other.db; // TODO: check deep copy
	return *this;
}

bool BitcoinExchange::isValidLong(const std::string &str, long *result)
{
	const char *cstr = str.c_str();
	char *endptr;
	*result = std::strtol(cstr, &endptr, 10);

	return *endptr == '\0' && *result != 0;
}

bool BitcoinExchange::isValidDouble(const std::string &str, double *result)
{
	std::istringstream ss(str);
	return (ss >> *result) && ss.eof();
}

bool BitcoinExchange::isValidYearMonthDay(long year, int month, int day)
{
	if (month < 1 || month > 12 || day < 1)
		return false;

	int maxDaysInMonth = 31;
	if (month == 2)
		maxDaysInMonth = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDaysInMonth = 30;

	if (year < 0 && month == 2 && day == 29 && maxDaysInMonth == 29)
		return true;

	return (day <= maxDaysInMonth);
}

bool BitcoinExchange::isValidDate(const std::string &str)
{
	std::stringstream ss(str);
	std::string raw_part;
	long year, month, day;

	std::getline(ss, raw_part, '-');
	if (!isValidLong(raw_part, &year))
		return false;
	std::getline(ss, raw_part, '-');
	if (!isValidLong(raw_part, &month))
		return false;
	std::getline(ss, raw_part);
	if (!isValidLong(raw_part, &day))
		return false;
	if (!isValidYearMonthDay(year, month, day))
		return false;
	if (!ss.eof())
		return false;
	return true;
}
