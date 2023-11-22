#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	Contact::get_id(Contact contact)
{
	return (contact.id);
}

std::string Contact::get_First(Contact contact)
{
	return (contact.FirstName);
}

std::string Contact::get_last(Contact contact)
{
	return (contact.LastName);
}
std::string Contact::get_nick(Contact contact)
{
	return (contact.Nickname);
}

std::string Contact::get_phone(Contact contact)
{
	return (contact.PhoneNumber);
}

std::string Contact::get_secret(Contact contact)
{
	return (contact.DarkestSecret);
}

int	Contact::check_input(std::string input)
{
	int	count = 0;
	int	index = 0;

	while (input[index])
	{
		if (std::isspace(input[index]) != 0)
			count++;
		index++;
	}
	if (count == index)
		return (-1);
	return (1);
}

Contact	Contact::setcontact(int	id_index)
{
	std::string	input;
	PhoneBook phone;
	Contact	contact;

	contact.id = id_index;
	std::cout << "First Name = ";
	std::getline(std::cin, input);
	if (check_input(input) == -1)
	{
		while (check_input(input) == -1)
		{
			std::cout << "Invalid input, try again!" << std::endl;
			std::cout << "First Name = ";
			std::getline(std::cin, input);
		}
	}
	contact.FirstName = input;
	std::cout << "Last Name = ";
	std::getline(std::cin, input);
	if (check_input(input) == -1)
	{
		while (check_input(input) == -1)
		{
			std::cout << "Invalid input, try again!" << std::endl;
			std::cout << "Last Name = ";
			std::getline(std::cin, input);
		}
	}
	contact.LastName = input;
	std::cout << "Nickname = ";
	std::getline(std::cin, input);
	if (check_input(input) == -1)
	{
		while (check_input(input) == -1)
		{
			std::cout << "Invalid input, try again!" << std::endl;
			std::cout << "Nickname = ";
			std::getline(std::cin, input);
		}
	}
	contact.Nickname = input;
	std::cout << "Phone Number = ";
	std::getline(std::cin, input);
	if (check_input(input) == -1)
	{
		while (check_input(input) == -1)
		{
			std::cout << "Invalid input, try again!" << std::endl;
			std::cout << "Phone Number = ";
			std::getline(std::cin, input);
		}
	}
	contact.PhoneNumber = input;
	std::cout << "Darkset Secret = ";
	std::getline(std::cin, input);
	if (check_input(input) == -1)
	{
		while (check_input(input) == -1)
		{
			std::cout << "Invalid input, try again!" << std::endl;
			std::cout << "Darkest Secret = ";
			std::getline(std::cin, input);
		}
	}
	contact.DarkestSecret = input;
	std::cout << "Contact added!" << std::endl;
	return (contact);
}


int main(void)
{
	int			index = 0;
	int			check;
	Contact		contact;
	PhoneBook	list;
	std::string	input;
	int			input_search;

	check = -1;
	while (1)
	{
		std::cout << "Your choices: [ADD] [SEARCH] [EXIT]" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			list = list.add_contact(index, index + 1, list);
			index += 1;
			if (index == 8)
			{
				index = 0;
				check = 1;
			}
		}
		else if (input == "SEARCH")
		{
			if (index == 0 && check != 1)
			{
				std::cout << "Phonebook is empty, add a person!" << std::endl;
				continue ;
			}
			if (check != 1)
				list.print_list(index, list);
			else
				list.print_full_list(list);
			list.show_details_list(list);
		}
		else if (input == "EXIT")
			exit(0);
		else
			std::cout << "Invalid input, try one of these!";
		std::cout << std::endl;
	}
	return 0;
}