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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	for (std::map<std::string, double>::const_iterator it = other.db.begin();
		 it != other.db.end(); ++it)
		db[it->first] = it->second;
	return *this;
}

int BitcoinExchange::isValidValue(const std::string &str, double *result)
{
	if (!isValidDouble(str, result))
		return 0;
	if (*result < 0)
		return 1;
	if (*result > 1000)
		return 2;
	return 3;
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

void BitcoinExchange::printRate(const std::string &original_date, const std::string &date,
								const std::string &original_value, double value)
{
	std::cout << original_date << " => " << original_value << " = " << value * db[date] << '\n';
}

void BitcoinExchange::search(const std::string &line)
{
	std::stringstream ss(line);
	// get date
	std::string date;
	std::getline(ss, date, ' ');
	if (ss.eof())
	{
		std::cerr << "Error: bad input => " << line << '\n';
		return;
	}
	// check date
	if (!isValidDate(date))
	{
		std::cerr << "Error: invalid date => " << date << '\n';
		return;
	}
	// check delimiter
	char ch[2];
	ss.read(ch, 2);
	if (ss.eof() || ch[0] != '|' || ch[1] != ' ')
	{
		std::cerr << "Error: bad input => " << line << '\n';
		return;
	}
	// check value
	std::string raw_value;
	std::getline(ss, raw_value);
	double value;
	switch (isValidValue(raw_value, &value))
	{
	case 0:
		std::cerr << "Error: invalid number.\n";
		return;
	case 1:
		std::cerr << "Error: not a positive number.\n";
		return;
	case 2:
		std::cerr << "Error: too large a number.\n";
		return;
	}
	// get rate
	if (db.count(date) > 0)
		return printRate(date, date, raw_value, value);
	std::map<std::string, double>::iterator dateFound = db.lower_bound(date);
	if (dateFound != db.begin())
		--dateFound;
	printRate(date, (*dateFound).first, raw_value, value);
}
