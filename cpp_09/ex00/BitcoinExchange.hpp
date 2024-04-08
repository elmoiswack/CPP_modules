#pragma once

#include <iostream>
#include <fstream>

class BitcoinExchange
{
private:
	std::ifstream _database;
	std::ifstream _FdInput;
public:
	BitcoinExchange();
	~BitcoinExchange();

	void OpenDatabase();

	void ConvertionData(char *inputFile);
	void CheckInputLine(std::string input);
	void CheckDate(std::string input);
	void CheckValue(std::string input);
	void CalculateValueFromData(std::string date, std::string value);
	
	std::string GetSpicificDate(int index, std::string input);

	int PosPipe(std::string input);
	void OverflowCheck(std::string input);
	
	void PrintErrorDate(std::string input);

	template <typename T> int EndLine(T input)
	{
		int index;
		for (index = 0; input[index]; index++) {}
		return (index);
	}

	class EmptyException : public std::exception
	{
		const char* what() const throw();
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
};

