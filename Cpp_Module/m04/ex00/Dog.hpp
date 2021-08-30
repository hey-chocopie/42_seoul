#ifndef __DOG_HPP__
#define __DOG_HPP__

class Dog :public Animal{
	public:
		Dog();
		Dog(const Dog &rhd);
		~Dog();

		void makeSound( void ) const;

		Dog &operator=(const Dog &rhd);
};

#endif

