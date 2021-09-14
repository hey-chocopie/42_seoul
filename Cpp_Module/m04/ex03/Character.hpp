#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character:public ICharacter{
private:
	std::string Name;
	AMateria *inventory[4];
	int			count[4];
public:
	Character();
	Character(std::string Name);
	Character(const Character &rhd);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	Character &operator=(const Character &rhd);

	~Character();
};

#endif
