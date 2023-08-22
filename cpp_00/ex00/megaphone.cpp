#include <iostream>

void	printing(char *argv[])
{
	int index = 1;
	int	index_x;
	
	while (argv[index])
	{
		index_x = 0;
		while (argv[index][index_x])
		{
			if (argv[index][index_x] >= 'a' && argv[index][index_x] <= 'z')
				argv[index][index_x] = std::toupper(argv[index][index_x]);
			std::cout << argv[index][index_x];
			index_x++;			
		}
		index++;
	}
	std::cout << std::endl;
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	printing(argv);
	return 0;
}