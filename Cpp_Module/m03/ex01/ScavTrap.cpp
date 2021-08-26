#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap ( void ): ClapTrap()
{
	std::cout << "[ScavTrap][Constructor] Overwrite ScavTrap" << std::endl;
	ScavTrap::setHitoints (100);
	ScavTrap::setEnergy_points (50);
	ScavTrap::setAttack_damage (20);
}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap (name)
{
	std::cout << "[ScavTrap][Constructor] Overwrite ScavTrap, name is " << name << std::endl;
	ScavTrap::setHitoints(100);
	ScavTrap::setEnergy_points(50);
	ScavTrap::setAttack_damage(20);
}

ScavTrap::ScavTrap (const ScavTrap& origin):ClapTrap(origin)
{
	std::cout << "[ScavTrap][copy Constructor] Overwrite ScavTrap, name is <" << origin.getName() << ">" << std::endl;
	*this = origin;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "[ScavTrap] <" << ScavTrap::getName() << "> ";
	std::cout << "[attacks] <" << target << ">, ";
	std::cout << "causing <" << ScavTrap::getAttack_damage() << "> ";
	std::cout << "points of damage!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode!" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& origin)
{
	//밑에 값들은 이미 ClapTrap 복사생성자에서 넣어주지만, ScavTrap operator=를 사용할수 있게 해주고, 
	//초기 생성할때 출력문 뛰워줄려고 넣음:
	std::cout << "[ScavTrap][operator=] overwrite" << std::endl;
	ScavTrap::setName(origin.getName());
	ScavTrap::setHitoints(origin.getHitoints());
	ScavTrap::setEnergy_points(origin.getEnergy_points());
	ScavTrap::setAttack_damage(origin.getAttack_damage());
	return *this;
}



ScavTrap::~ScavTrap ( void )
{
	 std::cout << "[ScavTrapTrap][Destructor]"  <<" <" << ScavTrap::getName() << "> Called" << std::endl;
}
