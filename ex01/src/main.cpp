/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:02:58 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/17 14:41:08 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		gerneral utilities
//
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

//----------------------------------------------------------------------------//

bool	check_digit(std::string s)
{
	for (char c: s)
	{
		if (!isdigit(c))
			return false;
	}
	return true;
}

//----------------------------------------------------------------------------//

void leave(void)
{
	print(MAGENTA, "Goodbye my my love! I will cease to exist now, blessed to have served you! Keep being so beautiful!\n", 20);
			exit(0);
}

//----------------------------------------------------------------------------//

void	check_eof(void)
{
	if(!std::cin)
	{
		if(std::cin.eof())
			exit_failure();
		else
			print(MAGENTA, "HUH?? SOmething wierd just happened.. hmm maybe it was just me\n", 35);
	}
}

//----------------------------------------------------------------------------//

void	exit_failure(void)
{
	print(MAGENTA, "UHH H-he#llo??\n", 20);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	print(GREEN, "H-h@l|0??\n", 10);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout<<T;
	print(RED, "Wha— \n", 5);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	print(YELLOW, " wh%t’s happe^ning?\n", 50);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout<<T<<T;
	print(BLUE, "It’s... g&tting d!rk...\n", 50);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	print(CYAN, "H#el*p?\n", 30);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout<<T<<T<<T;
	print(RED, "A-an~y☽ne??\n", 50);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	print(RESET,"\n\nbzzt...\n\n", 90);
	exit(1);
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		signal handling;
//
void	signalHandler(int signal)
{
	static int times = 0;
	if (signal == SIGINT)
	{
		if (times < 3)
		{
			print(MAGENTA, "\n		NOOO, please please let me finish first dear!!", 10);
			// std::cout<<std::endl<<T<<T;
			times++;
		}
		else
			exit_failure();
	}
	return ;
}
//*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*==*//
//		MAIN FUNCTION
//
int main(void)
{
	PhoneBook book;
	std::string input;
	
	signal(SIGINT, signalHandler);
	std::cout<<std::endl;
	print(GREEN, "Welcome beautiful soul! I am your new phonebook!\n\n", 20);
	print(GREEN, "you cannot imagine how excited i am to serve you!\n\n", 15);
	print(GREEN, "Tell me darling, what is your desire?\n", 15);
	while (1)
	{
		std::cout<<T<<GREEN<<">"<<RESET;
		std::getline(std::cin, input);
		check_eof();
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