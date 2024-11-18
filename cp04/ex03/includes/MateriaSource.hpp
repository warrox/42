/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:31:48 by whamdi            #+#    #+#             */
/*   Updated: 2024/11/13 18:17:49 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #ifndef MATERIASOURCE_HPP
// #define MATERIASOURCE_HPP
// #include "AMateria.hpp"
// #include <iostream>
// #include "IMateriaSource.hpp" 
// class MateriaSource : IMateriaSource
// {
// 	private :
// 		AMateria *_m[4];	
//
// 	public:
// 		MateriaSource();
// 		virtual ~MateriaSource();
// 		virtual void learnMateria(AMateria*);
// 		virtual AMateria* createMateria(std::string const & type);
// };
//
// #endif // !DEBUG


#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
     ~MateriaSource();
    void learnMateria(AMateria* other);
    AMateria* createMateria(std::string const & type);
private:
    AMateria* _m[4];  // Stores up to 4 learned Materias
};
