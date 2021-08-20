#ifndef __HUMANB_H__
#define __HUMANB_H__
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public :
		void			attack( void );
		void			setWeapon( Weapon &club );
		HumanB( std::string name );
	private :
		std::string		name;
		Weapon			*club;
};

#endif
