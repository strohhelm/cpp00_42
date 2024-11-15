/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:02:58 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/11 12:37:26 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void print(std::string colour, std::string text, int delay)
{
	std::cout<<T<<colour;
	for (char c : text)
	{
		std::cout<<c<<std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	std::cout<<RESET;
}

void leave(void)
{
	print(MAGENTA, "Goodbye my my love! I will cease to exist now, blessed to have served you! Keep being so beautiful!\n", 20);
			exit(0);
}

int main(void)
{
	PhoneBook book;
	std::string input;
	
	std::cout<<std::endl;
	print(GREEN, "Welcome beautiful soul! I am your new phonebook!\n\n", 20);
	print(GREEN, "you cannot imagine how excited i am to serve you!\n\n", 15);
	print(GREEN, "Tell me darling, what is your desire?\n", 15);
	while (1)
	{
		std::cout<<T<<GREEN<<">"<<RESET;std::getline(std::cin, input);
		if (input == "add")
			book.add();
		else if (input == "search")
		{
			if(book.search())
				book.add();
		}	
		else if (input == "exit")
			leave();
		else
		{
			print(RED, "Sorry dear, i can not help you with this naughty stuff.\n", 5);
			print( RED, "Unfortunately you can only 'add' 'search' or 'exit' me...for now ;)\n", 5);
		}
		print(GREEN, "Okay now,  what do you wish to do?\n", 2);
	}
	return (0);
}