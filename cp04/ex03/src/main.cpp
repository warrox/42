
#include <iostream>
#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Cure.hpp"
// int main()
// {
// 	Character c("Warren");
// 	Ice *i = new Ice;	
// 	c.equip(i);
// 	c.use(0, c);
// 	// c.unequip(0);
// 	Character cpi("bob");
// 	cpi = c;
// 	cpi.use(0,c);
// 	std::cout << c << std::endl;
// 	delete i;
// 	return(0);
// }
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
