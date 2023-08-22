#include <iostream>
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

#define BOOKSIZE 8

class PhoneBook
{
	private:
		Contact	phone_list[BOOKSIZE];

	public:
		Contact get_contact(PhoneBook list, int index);
		PhoneBook add_contact(int index, int id, PhoneBook list);
		void	print_list(int index, PhoneBook list);
		void	print_full_list(PhoneBook list);
		void	show_details_list(PhoneBook list);
		int		get_lenght(std::string string);
};

#endif
