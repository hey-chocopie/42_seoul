#include <deque>
#include <stack>
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

//템플릿 시 typename T만 으로 정의할수 있지만 그럼 항상 MutantStack은 항상 deque인 부모만 상속받음. 지금처럼 상속하면 deque대신 vector도 가능.
template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	private :

	public :
		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		MutantStack();
		MutantStack(std::stack<T, Container> &rhd);
		~MutantStack();

		typename std::stack<T, Container>::container_type::iterator begin();
		typename std::stack<T, Container>::container_type::iterator end();
		
		MutantStack<T, Container> &operator=(std::stack<T,Container> &rhd);
};

#endif

//Container는 젤 처음에만 deque로 정의해줌. 
//template <typename T, class Container>
//MutantStack<T, Container>::MutantStack() : std::stack<T, Container> ()
//{
//
//}
//
//template <typename T, class Container>
//MutantStack<T, Container>::MutantStack(std::stack<T, Container> &rhd) : std::stack<T,Container> (rhd)
//{
//	
//}
//
//template <typename T, class Container>
//MutantStack<T, Container>::~MutantStack()
//{
//	
//}
//
//
//template <typename T, class Container>
//typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::begin()
//{
//	return this->c.begin();
//}
//
//
//template <typename T, class Container>
//typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::end()
//{
//	return this->c.end();
//}
//
//
//template <typename T, class Container>
//MutantStack<T, Container> &MutantStack<T, Container>::operator=(std::stack<T,Container> &rhd)
//{
//	std::stack<T, Container>::operator=(rhd);
//	return (*this);
//}
