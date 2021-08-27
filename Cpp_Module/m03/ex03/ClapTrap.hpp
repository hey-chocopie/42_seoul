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
		void			setHitpoints( int Hitpoints );
		void			setEnergy_points( int Energy_points );
		void			setAttack_damage( int Attack_damage );

		ClapTrap		&operator=(const ClapTrap& origin);
		~ClapTrap();
};

#endif
