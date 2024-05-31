/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:42:36 by fnascime          #+#    #+#             */
/*   Updated: 2024/04/08 16:16:23 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string zname);
		~Zombie();
		void	announce(void);
		std::string	getName();
		void	setName(std::string name);
};
