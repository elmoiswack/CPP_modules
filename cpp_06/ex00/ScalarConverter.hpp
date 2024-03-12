#pragma once

#include <iostream> 

class ScalarConverter
{
private:

public:

	static void	printOutput(char c, int i, float f, double d);
	static void	convertFromC(char c, int i, float f, double d);
	static void	convertFromI(char c, int i, float f, double d);
	static void	convertFromF(char c, int i, float f, double d);
	static void	convertFromD(char c, int i, float f, double d);
	static void convertWord(char c, int i, float f, double d);
	
	static void convert(char *input);

};
