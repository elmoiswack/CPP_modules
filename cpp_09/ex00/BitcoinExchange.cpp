#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& in)
{
	std::cout << "Copy constructor is called!" << std::endl;
	*this = in;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& in)
{
	std::cout << "Operator overload '=' is called!" << std::endl;
	if (this == &in)
		return (*this);
	return(*this);
}

void BitcoinExchange::OpenDatabase(std::ifstream& database, std::ifstream& Fdinput)
{
	database.open("./data.csv", std::ifstream::in);
	if (database.fail())
	{
		this->CloseFiles(database, Fdinput);
		throw(FileOpenFailedException());
	}
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
		beginindex = index - 1;
		while (input[beginindex] != '-')
			beginindex--;
		beginindex += 1;
	}
	return (input.substr(beginindex, index - beginindex));
}

void BitcoinExchange::CheckDate(std::string input)
{
	int countseperator = 0;
	std::string singledate;
	float datevalue;

	for (int index = 0; input[index]; index++)
	{
		if (input[index] == '-' || input[index + 1] == '\0')
		{
			if (input[index + 1] == '\0')
				index += 1;
			if (countseperator > 2)
				throw (DateException(input));
			singledate = this->GetSpicificDate(index, input);
			this->OverflowCheck(singledate);
			datevalue = std::stof(singledate);
			if (countseperator == 0 && ((datevalue < 2009 || datevalue > 2022)))
				throw (DateException(input));				
			else if (countseperator == 1 && (datevalue < 1 || datevalue > 12))
				throw (DateException(input));					
			else if (countseperator == 2 && (datevalue < 1 || datevalue > 31))
				throw (DateException(input));		
			countseperator += 1;
			if (input[index] == '\0')
				break ;
		}
	}
}

void BitcoinExchange::CheckValue(std::string input)
{
	this->OverflowCheck(input);
	double Value = std::stod(input);
	if (Value < 0)
		throw (BadValueTooLowException());
	if (Value > 1000)
		throw (BadValueTooHighException());
}

void BitcoinExchange::CheckDataLine(std::string input)
{
	if (input.size() <= 10)
		throw(DatabaseInvalidLineexception());
	if (input[4] != '-')
		throw(DatabaseInvalidLineexception());
	if (input[7] != '-')
		throw(DatabaseInvalidLineexception());
	if (input[10] != ',')
		throw(DatabaseInvalidLineexception());
}

std::map<long, double> BitcoinExchange::PutFileIntoContainer(std::map<long, double> container, std::ifstream& database)
{
	long Date;
	double Value;
	std::string FileLine;
	std::string Datestring;
	std::string Valuestring;

	std::getline(database, FileLine);
	if (FileLine != "date,exchange_rate")
		throw(DatabaseFirstLineexception());
	while(std::getline(database, FileLine))
	{
		this->CheckDataLine(FileLine);
		Datestring = FileLine.substr(0, 10);
		Valuestring = FileLine.substr(11, this->EndLine<std::string>(FileLine));
		Datestring.erase(4, 1);
		Datestring.erase(6, 1);
		Date = std::stol(Datestring);
		Value = std::stod(Valuestring);
		container[Date] = Value;
	}
	return (container);
}

void BitcoinExchange::CalculateValueFromData(std::string DateType, std::string ValueType, std::map<long, double> container)
{
	std::string Datestr(DateType);
	Datestr.erase(4, 1);
	Datestr.erase(6, 1);

	long Date = std::stol(Datestr);
	double Value = std::stod(ValueType);
	
	double ContainerValue;

	std::map<long, double>::iterator it;
	it = container.begin();
	
	while (it != container.end() && (*it).first != Date)
		it++;
	if (it != container.end())
	{
		ContainerValue = (*it).second * Value;
		std::cout << DateType << " => " << ValueType << " = " << ContainerValue << std::endl;
	}
	else
	{
		auto it = container.lower_bound(Date);
		ContainerValue = (*it).second * Value;
		std::cout << DateType << " => " << ValueType << " = " << ContainerValue << std::endl;
	}
}

void BitcoinExchange::ConvertionData(char *arg)
{
	std::string LineFile;
	std::string DateType;
	std::string ValueType;
	std::map<long, double> container;

	std::ifstream database;
	std::ifstream Fdinput;

	Fdinput.open(arg, std::ifstream::in);
	if (Fdinput.fail())
		throw (FileOpenFailedException());
	this->OpenDatabase(database, Fdinput);
	container = this->PutFileIntoContainer(container, database);
	std::getline(Fdinput, LineFile);
	if (LineFile != "date | value")
	{
		this->CloseFiles(database, Fdinput);
		throw (InfileFirstLineexception());
	}
	while (std::getline(Fdinput, LineFile))
	{
		try
		{
			this->CheckInputLine(LineFile);
			int PipeIndex = this->PosPipe(LineFile);
			DateType = LineFile.substr(0, PipeIndex - 1);
			this->CheckDate(DateType);
			ValueType = LineFile.substr(PipeIndex + 2, this->EndLine<std::string>(LineFile));
			this->CheckValue(ValueType);
			this->CalculateValueFromData(DateType, ValueType, container);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	this->CloseFiles(database, Fdinput);
}

void BitcoinExchange::CloseFiles(std::ifstream& database, std::ifstream& Fdinput)
{
	if (database.is_open())
		database.close();
	if (database.is_open())
		Fdinput.close();
}

BitcoinExchange::DateException::DateException(const std::string &input)
{
	this->errorStr = "Error: bad date => " + input;
}

const char* BitcoinExchange::DateException::what() const throw()
{
	return (this->errorStr.c_str());
}

const char* BitcoinExchange::BadValueTooLowException::what() const throw()
{
	return ("ERROR: not a positive number!");
}

const char* BitcoinExchange::BadValueTooHighException::what() const throw()
{
	return ("ERROR: number too large!");
}

const char* BitcoinExchange::BadInputLineException::what() const throw()
{
	return ("ERROR: current line is invalid. Expected: 'a date | a value'!");
}

const char* BitcoinExchange::FileOpenFailedException::what() const throw()
{
	return ("ERROR: Failed to open file!");
}

const char* BitcoinExchange::InfileFirstLineexception::what() const throw()
{
	return ("ERROR: The first line of the file needs to start with: 'date | value'. Date being the date of the current bitcoin value!");
}

const char* BitcoinExchange::DatabaseFirstLineexception::what() const throw()
{
	return ("ERROR: The first line of the database needs to start with 'date,exchange_rate'!");
}

const char* BitcoinExchange::DatabaseInvalidLineexception::what() const throw()
{
	return ("ERROR: lines of the database should look like this: 'xxxx-xx-xx,xx'!\nEverything before the comma is the date and after the value, for example: '2022-01-12,24'!");
}
