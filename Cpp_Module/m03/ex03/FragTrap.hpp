#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& origin);

	FragTrap		&operator=(const FragTrap& origin);

	void			highFivesGuys( void );

	~FragTrap ();
private:

};

#endif
