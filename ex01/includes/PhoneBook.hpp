/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:22 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/11 12:33:54 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "main.hpp"

enum err {
	ERROR,
	SUCCESS
};

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void add();
		int search();
		
	private:
		Contact	contacts[8];
		int		index;
		int		init;
};
#endif