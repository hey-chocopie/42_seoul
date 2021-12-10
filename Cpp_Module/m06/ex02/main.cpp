#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class A : public Base{
};

class B : public Base{
};

class C : public Base{
};

Base * generate(void)
{
	srand((unsigned int)time(NULL));
    int num = rand();

	if(num % 3 == 1)
		return (new A);
	else if(num % 3 == 2)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	std::cout << "*p : ";
	A* test1 = dynamic_cast<A*>(p);
	B* test2 = dynamic_cast<B*>(p);
	C* test3 = dynamic_cast<C*>(p);

	if (test1 != 0)
		std::cout << "A" << std::endl;
	else if (test2 != 0)
		std::cout << "B" << std::endl;
	else if (test3 != 0)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	std::string convert_flag;
	
	try{
		A& test1 = dynamic_cast<A&>(p);
		if((&test1) != 0)
			std::cout << "&p : A" << std::endl;
	}
	catch (std::bad_cast b) {
		std::cout << "A__Caught: " << b.what() << std::endl;
	}

	try{
		B& test2 = dynamic_cast<B&>(p);
		if((&test2) != 0)
			std::cout << "&p : B" << std::endl;
	}
   catch (std::bad_cast b) {
	   std::cout << "B__Caught: " << b.what() << std::endl;
   }

	try{
		C& test3 = dynamic_cast<C&>(p);
		if((&test3) != 0)
			std::cout << "&p : C" << std::endl;
	}
   catch (std::bad_cast b) {
	   std::cout << "C__Caught: " << b.what() << std::endl;
   }
}

int main ( void )
{
	Base *tmp = generate();

	identify(tmp);
	identify(*tmp);
	delete tmp;
	return 0;
}
