#include <iostream>

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
	private:
		int			id;
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string PhoneNumber;
		std::string	DarkestSecret;
	public:
		int	invalid_input;
		Contact	setcontact(int id);
		int	get_id(Contact contact);
		std::string get_First(Contact contact);
		std::string get_last(Contact contact);
		std::string get_nick(Contact contact);
		std::string get_phone(Contact contact);
		std::string get_secret(Contact contact);
		int	check_input(std::string input);
};

#endif
