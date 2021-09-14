#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* D = new Dog();
	const Animal* C = new Cat();
	//const Animal* A = new Animal();
	//이건 인스턴스안됨. 평가 테스트: 
	D->makeSound();
	C->makeSound();

	delete D;
	delete C;
}

