#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& origin);

	DiamondTrap		&operator=(const DiamondTrap& origin);
	
	void			setName(std::string Name);
	std::string		getName(void) const;
	void			attack(std::string const & target);
	void			whoAmI();

	~DiamondTrap ();
private:
	std::string Name;

};

#endif

