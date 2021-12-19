#include "MutantStack.hpp"

//Container는 젤 처음에만 deque로 정의해줌.
template <typename T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container> ()
{

}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(std::stack<T, Container> &rhd) : std::stack<T,Container> (rhd)
{

}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{

}


template <typename T, class Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}


template <typename T, class Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}


template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(std::stack<T,Container> &rhd)
{
	std::stack<T, Container>::operator=(rhd);
	return (*this);
}
