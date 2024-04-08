#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
	this->_database.close();
	this->_FdInput.close();
}

int BitcoinExchange::PosPipe(std::string input)
{
	int index;

	for (index = 0; input[index]; index++)
	{
		if (input[index] == '|')
			return (index);
	}
	return (-1);
}

void BitcoinExchange::OpenDatabase()
{
	this->_database.open("./data.csv", std::ifstream::in);
	if (this->_database.fail())
		throw(FileOpenFailedException());
}

void BitcoinExchange::CheckInputLine(std::string input)
{
	int countseperator = 0;
	
	if (input.size() < 14)
		throw (BadInputLineException());

	int index;
	for (index = 0; input[index]; index++)
	{
		if (index > 9 && input[index] == ' ')
			break ;
		if (std::isdigit(input[index]) == 0 && input[index] != '-')
			throw (BadInputLineException());
		if (input[index] == '-')
			countseperator += 1;
		if (countseperator > 2)
			throw (BadInputLineException());
	}
	if ((size_t)index == input.size())
		throw (BadInputLineException());
	index++; 
	if (input[index] != '|' && input[index + 1] != ' ')
		throw (BadInputLineException());
	index += 2;
	if ((size_t)(index) == input.size())
		throw (BadInputLineException());
}

void BitcoinExchange::OverflowCheck(std::string input)
{
    const char max[] = "2147483647";
    int i = 0;

    while (input[i] && input[i] != '.')
        i++;
    if (i < 10)
        return ;
    for (i = 0; i < 10; i++)
    {
        if (input[i] == '.')
            break ;
        if (input[i] > max[i])
            throw (BadValueTooHighException());
    }
}

std::string BitcoinExchange::GetSpicificDate(int index, std::string input)
{
	int	beginindex;
	
	if (index == 4)
		beginindex = 0;
	else
	{
		beginindex = index;
		while (input[index] != '-' || input[index] != ' ')
			index++;
	}
	return (input.substr(beginindex, index));
}

void BitcoinExchange::PrintErrorDate(std::string input)
{
	std::cout << "Error: bad date => " << input << std::endl;
}

void BitcoinExchange::CheckDate(std::string input)
{
	int countseperator = 0;
	std::string singledate;
	float datevalue;

	for (int index = 0; input[index]; index++)
	{
		if (input[index] == '-')
		{
			countseperator += 1;
			if (countseperator > 2)
			{
				this->PrintErrorDate(input);
				throw (EmptyException());
			}
			singledate = this->GetSpicificDate(index, input);
			this->OverflowCheck(singledate);
			datevalue = std::stof(singledate);
			if (countseperator == 0 && ((datevalue < 2009 || datevalue > 2022)))
			{
				this->PrintErrorDate(input);
				throw (EmptyException());				
			}
			else if (countseperator == 1 && (datevalue < 1 || datevalue > 12))
			{
				this->PrintErrorDate(input);
				throw (EmptyException());					
			}
			else if (countseperator == 2 && (datevalue < 1 || datevalue > 31))
			{
				this->PrintErrorDate(input);
				throw (EmptyException());					
			}
		}
	}
}

void BitcoinExchange::CheckValue(std::string input)
{
	if (input[0] == '-')
		throw (BadValueTooLowException());
	this->OverflowCheck(input);
}

void BitcoinExchange::ConvertionData(char *arg)
{
	std::string LineFile;
	std::string DateType;
	std::string ValueType;

	this->_FdInput.open(arg, std::ifstream::in);
	if (this->_FdInput.fail())
		throw (FileOpenFailedException());
	this->OpenDatabase();
	std::getline(this->_FdInput, LineFile);
	if (LineFile != "date | value")
		throw (InfileFirstLineexception());
	while (std::getline(this->_FdInput, LineFile))
	{
		try
		{
			this->CheckInputLine(LineFile);
			//int PipeIndex = this->PosPipe(LineFile);
			//DateType = LineFile.substr(0, PipeIndex - 1);
			//this->CheckDate(DateType);
			//ValueType = LineFile.substr(PipeIndex + 2, this->EndLine<std::string>(LineFile));
			//this->CheckValue(ValueType);
			std::cout << "yay" << std::endl;
			//this->CalculateValueFromData(DateType, ValueType);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

const char* BitcoinExchange::EmptyException::what() const throw()
{
	return ("");
}

const char* BitcoinExchange::BadValueTooLowException::what() const throw()
{
	return ("ERROR: not a positive number");
}

const char* BitcoinExchange::BadValueTooHighException::what() const throw()
{
	return ("ERROR: number too large");
}

const char* BitcoinExchange::BadInputLineException::what() const throw()
{
	return ("ERROR: current line is invalid. Expected: 'a date | a value'");
}

const char* BitcoinExchange::FileOpenFailedException::what() const throw()
{
	return ("ERROR: Failed to open the current file!");
}

const char* BitcoinExchange::InfileFirstLineexception::what() const throw()
{
	return ("ERROR: The first line of the file needs to start with: 'date | value'. Date being the date of the current bitcoin value!");
}