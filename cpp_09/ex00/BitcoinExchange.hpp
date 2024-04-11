#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>

class BitcoinExchange
{
private:

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &in);
	BitcoinExchange& operator=(BitcoinExchange &in);
	~BitcoinExchange();

	void OpenDatabase(std::ifstream& database, std::ifstream& Fdinput);
	std::map<long, double> PutFileIntoContainer(std::map<long, double> container, std::ifstream& database);
	void CheckDataLine(std::string input);

	void ConvertionData(char *inputFile);
	void CheckInputLine(std::string input);
	void CheckDate(std::string input);
	void CheckValue(std::string input);
	void CalculateValueFromData(std::string date, std::string value, std::map<long, double> container);
	
	std::string GetSpicificDate(int index, std::string input);

	int PosPipe(std::string input);
	void OverflowCheck(std::string input);

	void CloseFiles(std::ifstream& database, std::ifstream& Fdinput);

	template <typename T> int EndLine(T input)
	{
		int index;
		for (index = 0; input[index]; index++) {}
		return (index);
	}

	class DateException : public std::exception
	{
		public:
			DateException(const std::string &input);
			const char* what() const throw();
		private:
		std::string errorStr;
	};

	class BadValueTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	class BadValueTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class BadInputLineException : public std::exception
	{
		const char* what() const throw();
	};

	class FileOpenFailedException : public std::exception
	{
		const char* what() const throw();
	};

	class InfileFirstLineexception : public std::exception
	{
		const char* what() const throw();
	};

	class DatabaseFirstLineexception : public std::exception
	{
		const char* what() const throw();
	};

	class DatabaseInvalidLineexception : public std::exception
	{
		const char* what() const throw();
	};
};

