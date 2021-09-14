#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal *A[50];

	for (int index = 0; index < 50; index++)
	{
		if(index % 2 == 0)
			A[index] = new Dog();
		else if(index % 2 == 1)
			A[index] = new Cat();
	}
	std::cout << std::endl;

	delete j;
	delete i;
	for (int index = 0; index < 50; index++)
		delete A[index];

	Dog test;
	test.setideas(0, "hhahahaha");
	Dog copy_test(test);

	std::cout << "<Doge's address>" << std::endl;
	std::cout << test.getBrain() << std::endl;
	std::cout << copy_test.getBrain() << std::endl;
	std::cout << "______ " << (test.getideas())[0] << " _______" << std::endl;
	std::cout << "______ " << (copy_test.getideas())[0] << " _______" << std::endl;
	std::cout << std::endl;
}

