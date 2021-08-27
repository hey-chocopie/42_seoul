#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& origin);

	ScavTrap		&operator=(const ScavTrap& origin);

	void			attack(std::string const & target);
	void			guardGate();

	~ScavTrap ();
private:

};

#endif
