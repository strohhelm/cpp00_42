/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:22 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/17 15:11:22 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Contact.hpp"
#include "main.hpp"

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