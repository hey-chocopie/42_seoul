#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std:: cout <<std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	WrongAnimal *A =  new WrongCat();
	WrongCat *C = new WrongCat();
	A->makeSound();
	C->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete A;
	delete C;
}
