#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>
#include <iomanip>
#include <string>

class Zombie{
	public:
		void announce(std::string name, std::string type);
	private:
		std::string name;
		std::string type;
};

#endif
