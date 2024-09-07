/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:22 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/07 17:51:31 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "main.hpp"


enum err {
	ERROR,
	SUCCESS,
};

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		
		void add();
		void search();
		
	private:
		Contact	contacts[8];
		int		index;
		int		init;
};
#endif