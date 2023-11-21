#include <iostream>
#include "PhoneBook.hpp"

int	PhoneBook::get_lenght(std::string string)
{
	int	index;

	while (string[index])
		index++;
	return (index);
}

Contact PhoneBook::get_contact(PhoneBook list, int index)
{
	Contact contact;

	contact = list.phone_list[index];
	return (contact);
}

PhoneBook PhoneBook::add_contact(int index, int id, PhoneBook list)
{
	Contact		contact;

	list.phone_list[index] = contact.setcontact(id);
	return (list);
}

void PhoneBook::show_details_list(PhoneBook list)
{
	int	index = 0;
	int	index_input;
	int	size;
	Contact contact;
	std::string input;

	std::cout << "Which persons information do you want to see: ";
	std::getline(std::cin, input);
	index_input = std::stoi(input);
	if (index_input > 8 || index_input == 0)
	{
		std::cout << "Invalid input! Try a number between 1 till 8!" << std::endl;
		return ;		
	}
	index_input -= 1;
	while (index <= 8)
	{
		if (index == index_input)
			break ;
		index++;
	}
	contact = list.phone_list[index];
	if (contact.get_id(contact) != (index + 1))
	{
		std::cout << "It appears that this information doens't exist yet, how strange!" << std::endl;
		return ;		
	}	
	std::cout << "First name = ";
	std::cout << contact.get_First(contact) << std::endl;
	std::cout << "Last name = ";
	std::cout << contact.get_last(contact) << std::endl;
	std::cout << "Nickname = ";
	std::cout << contact.get_nick(contact) << std::endl;
	std::cout << "Phonenumber = ";
	std::cout << contact.get_phone(contact) << std::endl;
	std::cout << "Darkest secret = ";
	std::cout << contact.get_secret(contact) << std::endl;
	return ;
}

void PhoneBook::print_full_list(PhoneBook list)
{
	Contact	contact;
	std::string string;
	int	i;
	int	index;
	int	size;

	index = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  | Firstname| Lastname | Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (index < 7)
	{
		std::cout << "|     ";			
		contact = list.phone_list[index];
		std::cout << contact.get_id(contact);
		std::cout << "    | ";
		size = get_lenght(contact.get_First(contact));
		size += 1;
		if (size > 9)
		{
			i = 0;
			string = contact.get_First(contact);
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_First(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "| ";
		size = get_lenght(contact.get_last(contact));
		size += 1;
		if (size > 9)
		{
			i = 0;
			string = contact.get_last(contact);
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_last(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "| ";
		size = get_lenght(contact.get_nick(contact));
		size += 1;
		if (size > 9)
		{
			string = contact.get_nick(contact);
			i = 0;
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_nick(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		index++;
	}
}

void PhoneBook::print_list(int index_list, PhoneBook list)
{
	Contact	contact;
	std::string string;
	int	i;
	int	index;
	int	size;

	index = 0;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  | Firstname| Lastname | Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (index < index_list)
	{
		std::cout << "|     ";			
		contact = list.phone_list[index];
		std::cout << contact.get_id(contact);
		std::cout << "    | ";
		size = get_lenght(contact.get_First(contact));
		size += 1;
		if (size > 9)
		{
			i = 0;
			string = contact.get_First(contact);
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_First(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "| ";
		size = get_lenght(contact.get_last(contact));
		size += 1;
		if (size > 9)
		{
			i = 0;
			string = contact.get_last(contact);
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_last(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "| ";
		size = get_lenght(contact.get_nick(contact));
		size += 1;
		if (size > 9)
		{
			string = contact.get_nick(contact);
			i = 0;
			while (i < 8)
			{
				std::cout << string[i];
				i++;
			}
			std::cout << ".";
		}
		else
		{
			std::cout << contact.get_nick(contact);
			while (size < 10)
			{
				std::cout << " ";
				size++;
			}
		}
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		index++;
	}
	return ;
}