#ifndef __HUMANA_H__
#define __HUMANA_H__
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private :
		std::string		name;
		Weapon			club;

	public :
		void			attack( void );
		HumanA( void );
		HumanA( std::string name, Weapon club );
};

#endif
