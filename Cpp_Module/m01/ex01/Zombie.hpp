#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>
#include <iomanip>
#include <string>

class Zombie{
	public:
		void announce( void );

		Zombie ( std::string input_data );
		Zombie ( void );
		~Zombie ( void );
		
		Zombie* zombieHorde( int N, std::string name );
		void input_name(std::string name);
	private:
		std::string name;
};

#endif
