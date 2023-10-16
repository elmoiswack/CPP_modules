#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::ifstream	old_file;
	std::ofstream	new_file;

	if (argc != 4)
	{
		std::cout << "Pass the right ammount of arguments!\nArg 0 = the program name, \nArg 1 = the filename, \nArg 2 = the string you want to find, \nArg 3 is the string you want to replace Arg 2 with!!" << std::endl;
		return (-1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Input strings cannot be empy!" << std::endl;
		return (-1);
	}
	old_file.open(argv[1], std::ios::in);
	if (!old_file)
	{
		std::cout << "Failed to open the input file!\nDoes it really exist??" << std::endl;
		return (-1);
	}
	std::string file_str;
	std::size_t i = 0;
	while (argv[1][i])
		i++;
	file_str = argv[1];
	file_str.append(".replace");
	new_file.open(file_str, std::ios::out);
	if (!new_file)
	{
		old_file.close();
		std::cout << "Failed to create and open the output file!" << std::endl;
		return (-1);
	}

	size_t index;
	size_t lenght_needle = 0;
	size_t lenght_haystack = 0;

	while (argv[2][lenght_haystack])
		lenght_haystack++;
	while (argv[3][lenght_needle])
		lenght_needle++;

	while (std::getline(old_file, file_str))
	{
		index = file_str.find(argv[2]);
		while (index != file_str.npos)
		{
			std::string temp;
			temp = file_str;
			file_str = file_str.substr(0, index);
			file_str = file_str.append(argv[3]); 
			file_str = file_str.append(temp.substr((lenght_haystack + index)));
			index = file_str.find(argv[2], index + lenght_needle);
		}
		new_file << file_str;
		if (old_file.eof())
			break ;
		new_file << std::endl;
	}
	
	old_file.close();
	new_file.close();
	return (0);
}