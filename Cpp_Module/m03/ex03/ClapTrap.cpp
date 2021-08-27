#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "[ClapTrap][Constructor] Create Player <Parameter of constructor>!" << std::endl;

	ClapTrap::Name = "Parameter of constructor";
	ClapTrap::Hitpoints = 10;
	ClapTrap::Energy_points = 10;
	ClapTrap::Attack_damage = 0;
}

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "[ClapTrap][Constructor]Create Player <";
	std::cout << name << ">!" << std::endl;
	ClapTrap::Name = name;
	ClapTrap::Hitpoints = 10;
	ClapTrap::Energy_points = 10;
	ClapTrap::Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& origin)
{
	std::cout << "[ClapTrap][Copy Constructor]Constructor by copy called, like  <" << origin.getName() <<  ">!" << std::endl;
	*this = origin;
}

void			ClapTrap::attack(std::string const & target)
{
	std::cout << "[ClapTrap] <" << ClapTrap::Name << "> ";
	std::cout << "attacks <" << target << ">, ";
	std::cout << "causing <" << ClapTrap::Attack_damage << "> ";
	std::cout << "points of damage!" << std::endl;
}


void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[ClapTrap] <"<< ClapTrap::Name;
	std::cout << "> got hit causing <"<< amount;
	std::cout << "> of damage!" << std::endl;
}
void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[ClapTrap] <" << ClapTrap::Name;
	std::cout << "> is getting repairded by <" << amount;
	std::cout << ">" << std::endl;
}




std::string				ClapTrap::getName( void ) const
{
	return (ClapTrap::Name);
}
int			            ClapTrap::getHitoints( void ) const
{
	return (ClapTrap::Hitpoints);
}
int			            ClapTrap::getEnergy_points( void ) const
{
	return (ClapTrap::Energy_points);
}
int			            ClapTrap::getAttack_damage( void ) const
{
	return (ClapTrap::Attack_damage);
}

void		     ClapTrap::setName( std::string name )
{
	this->Name = (name);
}
void            ClapTrap::setHitpoints( int Hitpoints )
{
	this->Hitpoints = (Hitpoints);
}
void            ClapTrap::setEnergy_points( int Energy_points )
{
	this->Energy_points = Energy_points;
}
void            ClapTrap::setAttack_damage( int Attack_damage )
{
	this->Attack_damage = Attack_damage;
}



ClapTrap& ClapTrap::operator=(const ClapTrap& origin)
{
    std::cout << "[ClapTrap][operator=] Operator Overloading Called" << std::endl;
	ClapTrap::Name = origin.getName();
	ClapTrap::Hitpoints = origin.getHitoints();
	ClapTrap::Energy_points = origin.getEnergy_points();
	ClapTrap::Attack_damage = origin.getAttack_damage();
    return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "[ClapTrap][Destructor]"  <<" <" << ClapTrap::Name << "> Called" << std::endl;
}
