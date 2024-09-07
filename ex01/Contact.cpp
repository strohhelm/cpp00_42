/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:22:38 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/07 18:35:09 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	firstname = "";
	lastname = "";
	nickname = "";
	phone = "";
	secret = "";
}

Contact::~Contact(){}

void	display_correctly(std::string content)
{
	int len;

	len = content.length();
	if (len > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << YELLOW << content[i] << RESET;
		std::cout <<".";
	}
	else
	{
		while ((10 - len++) > 0)
			std::cout <<" ";
		std::cout  << YELLOW << content << RESET;
	}
	std::cout << "|";
}
void Contact::display_for_table(int index)
{
	std::string ind;

	ind = std::to_string(index);
	std::cout << T <<"|";
	for(int i = 0; i < 7; i++)
	{
		switch(i)
		{
		case 0:
			display_correctly(ind);
			break;
		case 1:
			display_correctly(firstname);
			break;
		case 2:
			display_correctly(lastname);
			break;
		case 3:
			display_correctly(nickname);
			break;
		case 4:
			display_correctly(phone);
			break;
		case 5:
			display_correctly(secret);
			break;
		default:
			break;
		}
	}
	std::cout<<std::endl;
}


void Contact::display_contact(void)
{
	std::cout << T << GREEN << "First name: " << RESET << firstname << std::endl;
	std::cout << T << GREEN << "Last name: " << RESET << lastname << std::endl;
	std::cout << T << GREEN << "Nick name: " << RESET << nickname << std::endl;
	std::cout << T << GREEN << "Phone number: " << RESET << phone << std::endl;
	std::cout << T << GREEN << "Darkest secret: " << RESET << secret <<std::endl;
}
void Contact::set_var(int x, std::string value)
{
	switch (x)
	{
	case FIRST:
		firstname = value;
		break;
	case LAST:
		lastname = value;
		break;
	case NICK:
		nickname = value;
		break;
	case PHONE:
		phone = value;
		break;
	case SECRET:
		secret = value;
		break;
	default:
		break;
	}
}