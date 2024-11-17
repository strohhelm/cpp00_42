/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:18:23 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/17 14:57:57 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//	CONSTRUCTOR, DESTRUCTOR
//
PhoneBook::PhoneBook()
{
	index = 0;
	init = 0;
}
PhoneBook::~PhoneBook(){}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		add_function utilities
//
void display_message(int i)
{
	switch (i)
	{
		case FIRST:
			print(GREEN, "Please enter your first name: ", 3);
			break;
		case LAST:
			print(GREEN, "Please enter your last name: ", 3);
			break;
		case NICK:
			print(GREEN, "Please enter your nickname: ", 3);
			break;
		case PHONE:
			print(GREEN, "Please enter your phone number: ", 3);
			break;
		case SECRET:
			print(GREEN, "Please enter your darkest secret: ", 3);
			break;
	}
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		search_function utilities
//
int test_valid(std::string input, int index)
{
	int in;

	if (input.length() == 1 && isdigit(input[0]))
	{
		in = std::stoi(input);
		if (in > 0 && in < index + 1)
			return (in);
	}
	return (0);
}
//----------------------------------------------------------------------------//

void line(char c)
{
	int	i = 43;
		std::cout << T<<"|";
	for (int j = 0; j < i; j++)
		std::cout<<c;
	std::cout <<"|\n";
}
//----------------------------------------------------------------------------//

void print_table_head(void)
{
	std::cout << T << "|     "<< YELLOW <<"index"<<RESET<<"|";
	std::cout << YELLOW << "first name" << RESET << "| ";
	std::cout << YELLOW << "last name" << RESET << "| ";
	std::cout << YELLOW << "nick name" << RESET << "|\n";
}

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		PhoneBook Class functions
//
void PhoneBook::add(void)
{
	int i = 0;
	std::string input;
	Contact temp;

	while (i < 5)
	{
		display_message(i);
		std::getline(std::cin, input);
		check_eof();
		std::cout << T <<std::endl;
		if (((i == PHONE && !check_digit(input)) || input == ""))
		{
			std::cout << T << MAGENTA << "Well that cant be right, try again.\n" << RESET <<std::endl;
			continue;
		}
		contacts[index].set_var(i, input);
		i++;
	}
	index++;
	if (index == 8)
		index = 0;
	if (init < 8)
		init++;
	return ;
}

//----------------------------------------------------------------------------//

int PhoneBook::search(void)
{
	std::string input;
	int			in;

	if (!init)
	{
		print(MAGENTA, "OOPS, looks like there are no contacts yet, you have to add them first to me you silly goose ;)\n\n", 10);
		return (1);
	}
	line('=');
	print_table_head();
	line('=');
	for(int i = 0; i < init; i++)
	{
		contacts[i].display_for_table(i + 1);
		if (i < init - 1)
			line('-');
	}
	line('=');
	std::cout<<std::endl;
	while (1)
	{
		print(GREEN, "Which contact would you like to inspect closer?\n", 2);
		print(GREEN, "Type its number to see, or 'b'to go back:\n", 2);
		std::cout << T << GREEN << ">" << RESET;
		std::getline(std::cin, input);
		check_eof();
		if (input == "b")
			break ;
		else if((in = test_valid(input, init)))
		{
			print(GREEN, "Here you go dear, this is contact number ", 5);
			std::cout<<YELLOW<<input<<std::endl<<RESET;
			contacts[in - 1].display_contact();
		}
		else if (input == "exit")
			leave();
		else if (input == "add")
			return (1);
		else
		{
			print(RED, "well that doesnt make much sense dear, does it?\n", 10);
			print(RED, "How about you try again!\n\n", 5);
		}
	}
	return (0);
}