#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <iostream>
#include <string>
#include "Weapon.hpp"
class Weapon{
	public:
		const std::string	&getType( void );
		void				setType( std::string newtype );
		Weapon(std::string type);
		Weapon( void );
		~Weapon();
	private:
		static std::string	type;
};

#endif
