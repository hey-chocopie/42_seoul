#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__
#include <iostream>
#include <string>
class Brain{

private:
	std::string ideas[100];

public:
	Brain();
	Brain(Brain &rhd);

	std::string *getideas( void );
	void		setideas( int index, std::string ideas );
		
	Brain &operator=(Brain &rhd);

	~Brain( void );
};

#endif
