#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
Animal *test(std::string want)
{
	if(want == "Dog")
    	return new Dog();
    else
    	return new Cat();
}


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal *A[50];

	//업케스팅의 장점을 살펴보기 위해 몇가지 테스트를해봄.
	//지금 보면 리턴되는게 Dog, Cat 두가지인데, 업케스팅을 이용해
	//하나의 함수로 둘다 받음. 이런게 업케스팅의 장점.
	std::cout << "siofoisrjfiow"<< std::endl;
	Animal *zz = test("Dog");
	std::cout << zz->getType() << std::endl;
	zz = test("Cat");
	std::cout << zz->getType() << std::endl;
	std::cout << std::endl;

	for (int index = 0; index < 50; index++)
	{
		if(index % 2 == 0)
			A[index] = new Dog();
		else if(index % 2 == 1)
			A[index] = new Cat();
		std::cout <<std::endl;
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

