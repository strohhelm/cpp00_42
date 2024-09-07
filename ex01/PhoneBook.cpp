#include "PhoneBook.hpp"
#include <algorithm>

PhoneBook::PhoneBook()
{
	index = 0;
	init = 0;
}
PhoneBook::~PhoneBook(){}

void display_message(int i)
{
	switch (i)
	{
		case FIRST:
			std::cout << T << GREEN << "Please enter your first name: " << RESET;
			break;
		case LAST:
			std::cout << T << GREEN <<"Please enter your last name: " << RESET;
			break;
		case NICK:
			std::cout << T << GREEN <<"Please enter your nickname: " << RESET;
			break;
		case PHONE:
			std::cout << T << GREEN <<"Please enter your phone number: " << RESET;
			break;
		case SECRET:
			std::cout << T << GREEN <<"Now lets hear your darkest secret: " << RESET;
			break;
	}
}

void PhoneBook::add(void)
{
	int i = 0;
	std::string input;

	if (index == 9)
		index = 0;
	while (i < 5)
	{
		display_message(i);
		std::getline(std::cin, input);
		std::cout << T <<std::endl;
		if (i == PHONE && !std::all_of(input.begin(), input.end(), ::isdigit))
		{
			std::cout << T << MAGENTA << "Well that cant be right, try again." << RESET <<std::endl;
			continue;
		}
		contacts[index].set_var(i, input);
		i++;
	}
	index++;
	if (init == 0)
		init = 1;
	return ;
}

int test_valid(std::string input, int index)
{
	int in;

	if (input.length() == 1)
	{
		in = std::stoi(input);
		if (in > 0 && in < index + 1)
			return (in);
	}
	return (0);
}

void line(char c)
{
	int	i = 65;
		std::cout << T<<"|";
	for (int j = 0; j < i; j++)
		std::cout<<c;
	std::cout <<"|\n";
} 

void PhoneBook::search(void)
{
	std::string input;
	int			in;

	// if (!init)
	// {
	// 	std::cout << T<<MAGENTA<<"OOPS, looks like there are no contacts yet, you have to add them first to me you silly goose ;)"<<std::endl<<std::endl<<RESET;
	// 	return ;
	// }
	line('=');
	std::cout << T << "|     "<< GREEN <<"index"<<RESET<<"|";
	std::cout << GREEN << "first name" << RESET << "| ";
	std::cout << GREEN << "last name" << RESET << "| ";
	std::cout << GREEN << "nick name" << RESET << "|  ";
	std::cout << GREEN << "phone nb" << RESET << "|    ";
	std::cout << GREEN << "secret" << RESET << "|" << std::endl;
	line('=');
	for(int i = 0; i < index; i++)
	{
		contacts[i].display_for_table(i + 1);
		if (i < index - 1)
			line('-');
	}
	line('=');
	std::cout <<std::endl << T<< GREEN <<"Which contact would you like to inspect closer?\n";
	std::cout << T << "Type its number to see, or 'b'to go back:\n" << RESET;
	while (1)
	{
		std::cout << T << GREEN << ">" << RESET;
		std::getline(std::cin, input);
		if (input == "b")
			break ;
		else if((in = test_valid(input, index)))
		{
			std::cout << T << GREEN << "Here you go dear, this is contact number " << input << RESET << std::endl;
			
			contacts[in - 1].display_contact();
		}
		else
		{
			std::cout << T << RED << "well that doesnt make much sense dear, does it?\n";
			std::cout << T <<"How about you try again:" << RESET <<std::endl;
		}
	}	
	return ;
}