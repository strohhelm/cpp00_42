/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/11/17 15:09:36 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "main.hpp"
#include <iostream>
#include <string>

enum attribute {
	FIRST,
	LAST,
	NICK,
	PHONE,
	SECRET
};

class Contact
{
	public:
		Contact();
		~Contact();
		void display_for_table(int index);
		void display_contact(void);
		void set_var(int type, std::string value);


	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone;
		std::string secret;
};
#endif