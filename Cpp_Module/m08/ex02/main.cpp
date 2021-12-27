#include <deque>
#include <iostream>
#include "MutantStack.hpp"
#include "MutantStack.cpp"
int main()
{
    MutantStack<int> mstack;
  
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
	std::cout << "======all print=====" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
	std::cout << "======ADD test======" <<std::endl;
	std::cout << "s.size() == " <<  s.size() << std::endl;
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	std::cout << "s.size() == " << s.size() << std::endl;
	std::cout << "=====ADD test=====" << std::endl;
	MutantStack<int> foo,bar;
	foo.push (10); foo.push(20); foo.push(30);
	bar.push (111); bar.push(222);
	foo.swap(bar);
	std::cout << "size of foo: " << foo.size() << '\n';
	std::cout << "size of bar: " << bar.size() << '\n';

    return 0;
}
