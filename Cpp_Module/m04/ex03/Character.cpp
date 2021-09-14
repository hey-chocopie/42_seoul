#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	for(int i = 0; i < 4; i++)
		count[i] = 0;
}

Character::Character(std::string Name)
{
	for(int i = 0; i < 4; i++)
		count[i] = 0;
	this->Name = Name;
}

Character::Character(const Character &rhd)
{
	for(int i = 0; i < 4; i++)
		count[i] = 0;
	*this = rhd;
}

std::string const & Character::getName() const
{
	return (Name);
}


void Character::equip(AMateria* m)
{
	int i;

	for(i = 0; i < 4; i++)
		if(count[i] == 0)
			break;
	if(i != 4 && m != 0)
	{
		inventory[i] = m;
		count[i] = 1;
	}
	else
	{
		if(m != 0)
		{
			delete m;
		}
		std::cout << "[full invetory]" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if(count[idx] == 1)
	{
		count[idx] = 0;
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if(this == &target)
	{
		std::cout << "* not for me *" << std::endl;
		return ;
	}
	if(idx >=0 && idx <= 3 && count[idx] == 1)
		(inventory[idx])->use(target);
	else
	{
		std::cout << "empty inventory or wrong idx" << std::endl;
	}
}

Character &Character::operator=(const Character &rhd)
{
	this->Name = rhd.getName();
	for(int i = 0; i < 4; i++)
	{
		if(count[i] == 1)
			delete inventory[i];
		count[i] = 0;
		if(rhd.count[i] == 1)
		{
			inventory[i] = rhd.inventory[i]->clone();
			count[i] = 1;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if(count[i] == 1)
		{
			count[i] = 0;
			delete (inventory[i]);
		}
	}
}

