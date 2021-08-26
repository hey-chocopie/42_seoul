#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__
#include <iostream>
#include <string>
class ClapTrap{
	private:
		std::string		Name;
		int				Hitpoints;
		int				Energy_points;
		int				Attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& origin);

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName( void ) const;
		int				getHitoints( void ) const;
		int				getEnergy_points( void ) const;
		int				getAttack_damage( void ) const;

		void			setName( std::string );
		void			setHitoints( int Hitpoints );
		void			setEnergy_points( int Energy_points );
		void			setAttack_damage( int Attack_damage );

		ClapTrap		&operator=(const ClapTrap& origin);
		~ClapTrap();
};

//ClapTrap::ClapTrap( void )
//{
//	std::cout << "Create Player <Parameter of constructor>!" << std::endl;
//
//	this->Name = "Parameter of constructor";
//	Hitpoints = 10;
//	Energy_points = 10;
//	Attack_damage = 0;
//}
//ClapTrap::ClapTrap(const ClapTrap& origin)
//{
//	std::cout << "Constructor by copy called, like  <" << origin.getName() <<  ">!" << std::endl;
//	*this = origin;
//}
//
//void			ClapTrap::attack(std::string const & target)
//{
//	std::cout << "ClapTrap <" << ClapTrap::Name << "> ";
//	std::cout << "attacks <" << target.getName() << ">, ";
//	std::cout << "causing <" << ClapTrap::damage << "> ";
//	std::cout << "points of damage!" << std::endl;
//}
//
//
//void			ClapTrap::takeDamage(unsigned int amount)
//{
//	std::cout << "ClapTrap <"<< ClapTrap::name;
//	std::cout << "> got hit causing <"<< amount;
//	std::cout << "> of damage!" << std::endl;
//}
//void			ClapTrap::beRepaired(unsigned int amount);
//{
//	std::cout << "ClapTrap <" << ClapTrap::name;
//	std::cout << "> is getting repairded by <" << amount;
//	std::cout << ">" << std::endl;
//}
//
//ClapTrap::~ClapTrap( void )
//{
//	std::cout << "<" << ClapTrap::Name << "> GAME OVER" << std::endl;
//}
//
//
//void            getName( void )
//{
//	return (ClapTrap::Name);
//}
//void            getHitoints( void )
//{
//	return (ClapTrap::Hitpoints);
//}
//void            getEnergy_points( void )
//{
//	return (ClapTrap::Energy_points);
//}
//void            getAttack_damage( void );
//{
//	return (ClapTrap::damage);
//}
//
//ClapTrap& ClapTrap::operator=(const ClapTrap& origin)
//{
//    std::cout << "[Constructor] Operator Overloading Called" << std::endl;
//	ClapTrap::Name = origin.getName();
//	ClapTrap::Hitpoints = origin.getHitoints();
//	ClapTrap::Energy_points = origin.getEnergy_points();
//	ClapTrap::Attack_damage = origin.getAttack_damage();
//    return (*this);
//}
//
#endif
