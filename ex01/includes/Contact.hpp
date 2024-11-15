/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/09/11 12:16:40 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "main.hpp"

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