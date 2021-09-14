#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

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

//int main (void)
//{
//	std::cout << "<create check AMateria and ice,cure>" << std::endl;
//	Ice a;
//	Cure b;
//	std::cout << a.getType() << std::endl;
//	AMateria *parent = a.clone(); // While assigning a Materia to another, copying the type doesn’t make , parent바꿔도 c의 타입은 그대로임. 
//	std::cout << parent->getType() << std::endl;
//	delete parent;
//	ICharacter* bob = new Character("bob");
//	a.use(*bob);
//	b.use(*bob);
//	delete bob;
//	std::cout << std::endl;
//
//	std::cout << "<create check Carater class test>" << std::endl;
//	ICharacter* IC = new Character("hoylee");
//	AMateria *ttt = new Ice;
//	for(int i = 0; i < 5; i++)
//	{
//		if( i != 2)
//			IC->equip(new Ice);
//		else
//		{
//			IC->equip(ttt);
//		}
//	}
//	IC->unequip(2);
//	delete ttt;
//	ICharacter* tom = new Character("tom");
//	IC->use(2, *tom);
//	IC->equip(new Cure);
//	IC->use(2, *tom);
//	IC->use(3, *tom);
//	IC->use(2, *IC);
//	delete IC;
//	std::cout << std::endl;
//
//
//	std::cout << "<create check MateriaSource class test>" << std::endl;
//	IMateriaSource *IM = new MateriaSource;
//	AMateria *IM_Ice = new Ice;
//	AMateria *IM_Cure = new Cure;
//	IM->learnMateria(IM_Ice);
//	IM->learnMateria(IM_Cure);
//	AMateria *test_createMateria = IM->createMateria("ice");
//	test_createMateria->use(*tom);
//	delete test_createMateria;
//	delete tom;
//	delete IM;
//	return (0);
//}
