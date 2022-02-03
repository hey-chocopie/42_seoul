#ifndef __MAP_HPP__
#define __MAP_HPP__
#include <memory>
#include <iostream>
#include <string>
#include "pair.hpp"
#include "./utility.hpp"
#include "random_access_iterator_tag.hpp"
#include "map_iter.hpp"

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

		typedef ft::mapIte<value_type, node_type>			iterator;
		typedef ft::mapIte<const value_type, node_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;


		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		//설명 : map은 이진탐색트리형태로 구현되어있다. 
		//설명 : 그에 사용할 노드
		typedef ft::map_Node<value_type>						node_type;
		typedef node_type*										node_ptr;
		node_ptr												_Node;
		allocator_type											_alloc;
		key_compare												_comp;

//		value_type*											_array;
//		allocator_type										_alloc;
//		size_type											_size;
//		size_type											_capacity;

		//===========================Member functions=======================
		//empty (1)
		explicit map (const key_compare& comp = key_compare(),
		              const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _comp(comp), (_Node)(0)
		{ new _Node = Node_ptr (0) };
		//range (2)
		template <class InputIterator>
		  map (InputIterator first, InputIterator last,
		       const key_compare& comp = key_compare(),
		       const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _Node(0)
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
		map (const map& x) : _alloc(x._alloc), _comp(x._comp), _Node(0)
		{
			//this = x;
		};


		value_compare value_comp() const {
        return (value_compare(key_compare()));
		}
	};
	
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

}

#endif
