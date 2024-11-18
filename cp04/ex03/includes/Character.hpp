/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:20:58 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/14 13:51:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter
{
	protected:
		std::string _type;	
	public:
		
		AMateria *_inventory[INVENTORY_SIZE];			
		Character();
		Character(std::string type);
		Character(const Character &);
		Character & operator=(const Character &);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};
std::ostream& operator<<(std::ostream& os, const Character& value);
#endif // !CHARACTER_HPP
