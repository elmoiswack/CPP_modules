#pragma once

#include <iostream> 

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &in);
	ScalarConverter& operator=(ScalarConverter &in);
	~ScalarConverter();
public:    
    static void convert(char *input);

};
