#ifndef __MAP_HPP__
#define __MAP_HPP__
#include <memory>
#include <iostream>
#include <string>
#include "pair.hpp"
#include "./utility.hpp"
#include "random_access_iterator_tag.hpp"
#include "map_iter.hpp"
#include "binary_search_tree.hpp"
namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T> struct less : binary_function <T,T,bool> {
	  bool operator() (const T& x, const T& y) const {return x<y;}
	};




	template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
    > class map{
	public:
		//===========================Member types=======================
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<Key, T>								value_type;
		typedef Compare										key_compare;
		class value_compare;
		
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;		//T&
		typedef typename allocator_type::const_reference	const_reference;//const T&
		typedef typename allocator_type::pointer			pointer;		//T*
		typedef typename allocator_type::const_pointer		const_pointer;	//const T*

		//설명 : map은 이진탐색트리형태로 구현되어있다. 
		//설명 : 그에 사용할 노드
		typedef ft::map_Node<value_type>						node_type;
		typedef node_type*										node_ptr;
		node_ptr												_Node;
		std::allocator<node_type>								_allocNode;
		allocator_type											_alloc;
		key_compare												k_comp;
		//내가 만듬... 이름 다시?
		typedef ft::mapIte<value_type, node_type>			iterator;
		typedef ft::mapIte<const value_type, node_type>		const_iterator;
		typedef ft::reverse_iterator_tag<iterator>				reverse_iterator;
		typedef ft::reverse_iterator_tag<const_iterator>		const_reverse_iterator;
		//==custom fun==//
		node_ptr new_setNode(Key first, T second);

		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;

//		value_type*											_array;
//		allocator_type										_alloc;
		size_type											_size;
//		size_type											_capacity;

		//===========================Member functions=======================
		//empty (1)
		explicit map (const key_compare& comp = key_compare(),
		              const allocator_type& alloc = allocator_type())
						: _alloc(alloc), k_comp(comp), _Node(0), _size(0)
		{ 
			return; };
		//range (2)
		template <class InputIterator>
		  map (InputIterator first, InputIterator last,
		       const key_compare& _comp = key_compare(),
		       const allocator_type& alloc = allocator_type()) : _alloc(alloc), k_comp(_comp), _Node(0), _size(0)
		{
			insert(first, last);
//			for(; first != last; first++)
//			{
//				map_Node tmp(*first);
//				if(_Node == 0)
//					_Node  = tmp;
//				else
//					BST_InsertNode(&_Node, &tmp);
//			}
		};
		//copy (3)
		map (const map& x) : _alloc(x._alloc), k_comp(x.k_comp), _Node(0), _size(0)
		{
			//this = x;
		};

		//single element (1)	
		pair<iterator,bool> insert (const value_type& val);
//		//with hint (2)	
//		iterator insert (iterator position, const value_type& val);
		//range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);


		iterator				begin(void);
		const_iterator			begin(void) const;

		value_compare value_comp() const {
        return (value_compare(key_compare()));
		}
	bool				_key_eq(const key_type &k1, const key_type &k2) const;

	};
	//==my_custor==//
	template <class Key, class T, class Compare, class Alloc>
	typename ft::map<Key, T, Compare, Alloc>::node_ptr ft::map<Key, T, Compare, Alloc>::new_setNode(Key first, T second)
	{
		node_ptr tmp = _allocNode.allocate(1);
		tmp->data.first = first;
		tmp->data.second = second;

		return tmp;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare : binary_function<value_type,value_type,bool>
	{
	friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	//single element (1)	

	template < class Key, class T, class Compare, class Alloc >
	ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
	{
		ft::pair<iterator, bool> res;
		res.second = 1;
		if(_size == 0)
			_Node = new_setNode(val.first, val.second);
		else if(BST_SearchNode(_Node, val))
			res.second = 0; //이미 있음.
		else
			BST_InsertNode(_Node, new_setNode(val.first, val.second));
		res.first = this->find(val.first);
		//일단 임시로.res.first = 
		_size++;
		return res;
	}
//	//with hint (2)	
//	template < class Key, class T, class Compare, class Alloc >
//	iterator insert (iterator position, const value_type& val);
//	//range (3)	
	template < class Key, class T, class Compare, class Alloc >
	template <class InputIterator>
	void	ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
	{
		for(; first != last; first++)
			this->insert(*first);
	}
// ******************************* Operations ******************************* //
template<class Key, class T, class Compare, class Alloc>
bool
map<Key, T, Compare, Alloc>::_key_eq(const key_type &k1, const key_type &k2) const {
	return (!this->_key_cmp(k1, k2) && !this->_key_cmp(k2, k1));
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find(const key_type &k) {
	iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_eq(it->first, k))
			break ;
		++it;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find(const key_type &k) const {
	const_iterator it = this->begin(), ite = this->end();

	while (it != ite)
	{
		if (this->_key_eq(it->first, k))
			break ;
		++it;
	}
	return (it);
}


//template<class Key, class T, class Compare, class Alloc>
//typename map<Key, T, Compare, Alloc>::iterator				typename map<Key, T, Compare, Alloc>::begin(void)
//{
//	return (_Node); 맨 왼쪽 노드 반환해야함. 
//}
//template<class Key, class T, class Compare, class Alloc>
//const_iterator			begin(void) const
//{
//
//}

}

#endif
