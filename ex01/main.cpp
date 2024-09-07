/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:02:58 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/07 18:30:43 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string input;
	
	std::cout <<std::endl << T << GREEN<< "Welcome beautiful soul! I am your new phonebook!"<<std::endl<<RESET;
	std::cout <<std::endl << T << GREEN<< "you cannot imagine how excited i am to serve you!"<<std::endl<<RESET;
	std::cout <<std::endl << T << GREEN<< "Tell me darling, what is your desire?"<<std::endl << T << ">"<<RESET;
	while (1)
	{
		std::getline(std::cin, input);
		if (input == "add")
			book.add();
		else if (input == "search")
			book.search();
		else if (input == "exit")
		{
			std::cout <<std::endl << T << MAGENTA<<"Goodbye my my love! I will cease to exist now, blessed to have served you! Keep being so beautiful!"<<std::endl<<RESET;
			exit(0);
		}
		else
		{
			std::cout <<std::endl << T << RED<<"Sorry dear, i can not help you with this naughty stuff."<<std::endl<<RESET;
			std::cout <<std::endl << T << RED<<"Unfortunately you can only 'add' 'search' or 'exit' me...for now ;)\n"<<std::endl<<RESET;
		}
		std::cout << T << GREEN<<"Okay now,  what do you wish to do?"<<std::endl<< T << ">"<<RESET;
	}
	return (0);
}