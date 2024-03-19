#include "ScalarConverter.hpp"
#include <cstring>


ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar default constructor is called!" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &in)
{
	std::cout << "Scalare copy constructor is called!" << std::endl;
	*this = in;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &in)
{
	std::cout << "Operator overload '=' has been called!" << std::endl;
	(void)in;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar default deconstructor is called!" << std::endl;
}

int    ftIsPrintable(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (-1);
}

int    ftIsDigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (-1);
}

void convertFromC(char c)
{
    int i;
    float f;
    double d;

    i = c;
    f = (float) i;
    d = (double) f;
    std::cout << "Char: '" << c << "'\nInt: " << i << "\nFloat: " << f << ".0f\nDouble: " << d << ".0" << std::endl;
}

void convertFromI(int i)
{
    char c;
    float f;
    double d;
    const std::string ndisplay = "Non displayable";
    bool    noPrintC = false;

    if (ftIsPrintable(i) == 1)
        c = (char) i;
    else
        noPrintC = true;

    f = static_cast<float>(i);
    d = static_cast<double>(i);

    if (noPrintC == true)
        std::cout << "Char: " << ndisplay << "\nInt: " << i << "\nFloat: " << f << ".0f\nDouble: " << d << ".0" << std::endl;
    else
        std::cout << "Char: '" << c << "'\nInt: " << i << "\nFloat: " << f << ".0f\nDouble: " << d << ".0" << std::endl;
}

void convertFromF(float f)
{
    char c;
    int i;
    double d;
    const std::string ndisplay = "Non displayable";
    bool    noPrintC = false;
    
    if (ftIsPrintable((int)f) == 1)
        c = (char) f;
    else
        noPrintC = true;
    
    i = static_cast<int>(f);
    d = static_cast<double>(f);

    if (noPrintC == true)
        std::cout << "Char: " << ndisplay << "\nInt: " << i << "\nFloat: " << f << "f\nDouble: " << d << std::endl;
    else
        std::cout << "Char: '" << c << "'\nInt: " << i << "\nFloat: " << f << "f\nDouble: " << d << std::endl;
}

void convertFromD(double d)
{
    char c;
    int i;
    float f;
    const std::string ndisplay = "Non displayable";
    bool    noPrintC = false;
    
    if (ftIsPrintable((int)d) == 1)
        c = (char) d;
    else
        noPrintC = true;
    
    i = static_cast<int>(d);
    f = static_cast<float>(d);

    if (noPrintC == true)
        std::cout << "Char: " << ndisplay << "\nInt: " << i << "\nFloat: " << f << "f\nDouble: " << d << std::endl;
    else
        std::cout << "Char: '" << c << "'\nInt: " << i << "\nFloat: " << f << "f\nDouble: " << d << std::endl;
}

void convertWord(const char *typesFloat[], const char *typesDouble[], int index)
{
    const std::string imp = "Impossible";

    std::cout << "Char: " << imp << "\nInt: " << imp << std::endl;
    std::cout << "Float: " << typesFloat[index] << "\nDoubles: " << typesDouble[index] << std::endl;

}

int overflowCheck(char *input)
{
    const char max[] = "2147483647";
    const char min[] = "-2147483648";
    int i = 0;

    while (input[i] && input[i] != '.')
        i++;
    if (i < 10)
        return (-1);
    if (input[0] == '-')
    {
        for (i = 1; i < 11; i++)
        {
            if (input[i] == '.')
                return (-1);
            if (input[i] > min[i])
                return (1);
        }
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (input[i] == '.')
                return (-1);
            if (input[i] > max[i])
                return (1);
        }
    }
    return (-1);
}

int myStrcmp(const char *src, const char *str)
{
    size_t			i;

	i = 0;
	while (((src[i] != '\0') || (str[i] != '\0')))
	{
		if (src[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

void ScalarConverter::convert(char *input)
{
    const char *typesFloat[] = {"-inff", "+inff", "nanf"};
    const char *typesDouble[] = {"-inf", "+inf", "nan"};
    bool    is_char = false;
    bool    is_decimal = false;
    bool    is_float = false;
    bool    is_digit = false;
    int     strIndex = 0;

    while (input[strIndex])
    {
        if (ftIsPrintable(input[strIndex]) == 1 && ftIsDigit(input[strIndex]) != 1)
            is_char = true;
        if (ftIsDigit(input[strIndex]) == 1)
            is_digit = true;
        if (input[strIndex] == '.')
            is_decimal = true;
        if (input[strIndex] == 'f')
            is_float = true;
        strIndex++;
    }
    if (is_digit == true)
    {
        if (overflowCheck(input) == 1)
        {
            std::cout << "Overflowcheck returned true!" << std::endl;
            std::cout << "Input given is invalid, try another one!" << std::endl;
            return ;           
        }
    }
    if (is_char == true && strIndex == 1)
        return(convertFromC(input[0]));
    else if (is_float == true && is_decimal == true && is_digit == true)
        return (convertFromF(std::atof(input)));
    else if (is_decimal == true && is_digit == true)
        return (convertFromD(std::atof(input)));
    else if (is_digit == true && is_char != true)
        return (convertFromI(std::atoi(input)));
    else 
    {
        int i = 0;
        while (i < 3)
        {
            if (myStrcmp(typesFloat[i], input) == 0)
                return (convertWord(typesFloat, typesDouble, i));
            else if (myStrcmp(typesDouble[i], input) == 0)
                return (convertWord(typesFloat, typesDouble, i));
            i++;
        }
    }
    std::cout << "Input given is invalid, try another one!" << std::endl;
    return ;
}
