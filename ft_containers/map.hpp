#ifndef __MAP_HPP__
#define __MAP_HPP__
#include <memory>
#include <iostream>
#include <string>
#include "pair.hpp"
#include "utility.hpp"
#include "map_iter.hpp"
#include "binary_search_tree.hpp"
#include "vector_iter.hpp"
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

	template < class Key,										// map::key_type
			class T,											// map::mapped_type
			class Compare = less<Key>,							// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> >// map::allocator_type
    > class map{
	public:
		//===========================Member types=======================
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef pair<Key, T>									value_type;
		typedef Compare											key_compare;
		class value_compare;
		
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;		//T&
		typedef typename allocator_type::const_reference		const_reference;//const T&
		typedef typename allocator_type::pointer				pointer;		//T*
		typedef typename allocator_type::const_pointer			const_pointer;	//const T*

		//===========================My custom types=======================
		//설명 : map 이진탐색트리로 구현했음. 
		typedef ft::map_Node<value_type>						node_type;
		typedef node_type*										node_ptr;
		node_ptr												_Node;
		std::allocator<node_type>								_allocNode;
		allocator_type											_alloc;
		key_compare												k_comp;
		size_t													_size;

		//===========================Member types=======================
		typedef ft::mapIte<value_type, node_type>				iterator;
		typedef ft::mapIte<const value_type, node_type>			const_iterator;
		typedef ft::reverse_iterator_tag<iterator>				reverse_iterator;
		typedef ft::reverse_iterator_tag<const_iterator>		const_reverse_iterator;

		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		//===========================Member functions=======================
		//empty (1)
		explicit map (const key_compare& comp = key_compare(),
		              const allocator_type& alloc = allocator_type())
						:  _Node(0), _alloc(alloc), k_comp(comp), _size(0)
		{
			this->_Node = new node_type; 
		};
		//range (2)
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
		       const key_compare& _comp = key_compare(),
		       const allocator_type& alloc = allocator_type()) : _Node(0), _alloc(alloc), k_comp(_comp), _size(0)
		{
			this->_Node = new node_type; 
			insert(first, last); 
		};
		//copy (3)
		map (const map& x) : _Node(0), _alloc(x._alloc), k_comp(x.k_comp) , _size(0)
		{ 
			this->_Node = new node_type;
			(*this) = x; 
		};
		map& operator= (const map& x);
		~map (void)
		{
			clear();
			this->_allocNode.deallocate(_Node, 1);
		}

		//===========================Iterators:=======================
		iterator				begin();
		const_iterator			begin()		const;
		iterator				end();
		const_iterator			end()		const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin()	const;
		reverse_iterator		rend();
		const_reverse_iterator	rend()		const;

		//===========================Capacity:=======================
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//===========================Element access:=======================
		mapped_type& operator[] (const key_type& k);

		//===========================Modifiers:=======================
		//single element (1)	
		pair<iterator,bool> insert (const value_type& val);
		//with hint (2)	
		iterator insert (iterator position, const value_type& val);
		//range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position);
		size_type erase (const key_type& k);
		void erase (iterator first, iterator last);
		void swap (map& x);
		void clear();

		//===========================Observers:=======================
		key_compare key_comp() const;
		value_compare value_comp() const;

		//===========================Operations:=======================
		iterator							find (const key_type& k);
		const_iterator						find (const key_type& k) const;
		size_type							count (const key_type& k) const;
		iterator							lower_bound (const key_type& k);
		const_iterator						lower_bound (const key_type& k) const;
		iterator							upper_bound (const key_type& k);
		const_iterator						upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>             equal_range (const key_type& k);

		allocator_type						get_allocator() const;

		//=====================my_custom fun========================//
		bool						_key_eq(const key_type &k1, const key_type &k2) const;
		node_ptr					new_setNode(Key first, T second);
		void						tree_clear(node_ptr node);
	};

	template <class Key, class T, class Compare, class Alloc>
	ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator= (const map& x)
	{
		if (this == &x)
			return (*this);
		this->clear(); 
		iterator start = x.begin();
		iterator last = x.end();
		for(; start != last; start++)
		{
			BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(start->first, start->second), maxNode(_Node) , _size);
			_size++;
		}

		return (*this);
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator					map<Key, T, Compare, Alloc>::begin(void)
	{
		return (iterator(minNode(_Node)));
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator			map<Key, T, Compare, Alloc>::begin(void) const
	{
		return const_iterator(minNode(_Node));
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator					map<Key, T, Compare, Alloc>::end(void)
	{
		return (maxNode(_Node)); 
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator			map<Key, T, Compare, Alloc>::end(void) const
	{
		return (maxNode(_Node));
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator			map<Key, T, Compare, Alloc>::rbegin(void)
	{
		return reverse_iterator(this->end());
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>::rbegin(void) const
	{
		return const_reverse_iterator(this->end());
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator			map<Key, T, Compare, Alloc>::rend(void)
	{
		return reverse_iterator(this->begin());
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>::rend(void) const
	{
		return const_reverse_iterator(this->begin());
	}

	template<class Key, class T, class Compare, class Alloc>
	bool														map<Key, T, Compare, Alloc>::empty() const
	{
		if (_size == 0) return (1);
		return (0);
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type				map<Key, T, Compare, Alloc>::size() const
	{
		return (_size);
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type				map<Key, T, Compare, Alloc>::max_size() const
	{
		return (this->_allocNode.max_size());
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type&			map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
	{
		return (insert(value_type(k, mapped_type()))).first->second;
	} 

	//single element (1)	
	template < class Key, class T, class Compare, class Alloc >
	ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
	{
		ft::pair<iterator, bool> res;

		res.second = 1;
		if(_size != 0 && BST_SearchNode<node_ptr, Key>(_Node, val.first))
			res.second = 0; //설명 : 이미 _Node에 있음. 
		else
		{
			BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(val.first, val.second),maxNode(_Node), _size);
			_size++;
		}
		res.first = this->find(val.first);
		return res;
	}
	//with hint (2)	
	template < class Key, class T, class Compare, class Alloc >
	typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val)
	{
		static_cast<void>(position);
		//설명 : position 안쓰고 구현함. unsed 컴파일 에러떄문에 캐스팅함.
		return this->insert(val).first;
	}
	//range (3)	
	template < class Key, class T, class Compare, class Alloc >
	template <class InputIterator>
	void	ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
	{
		for(; first != last; first++)
			this->insert(*first);
	}

	template < class Key, class T, class Compare, class Alloc >
	void ft::map<Key, T, Compare, Alloc>::erase (iterator position)
	{
		erase((*position).first);
	}
	template < class Key, class T, class Compare, class Alloc >
	typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase (const key_type& k)
	{
		iterator element = find(k);
		
		if (element == this->end())
			return (0);
		BST_RemoveNode(&(element._node), &_Node);
		_size--;
		return (1);
	}
	template < class Key, class T, class Compare, class Alloc >
	void ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		for(; first != last; first++)
			erase(first);
	}


	template < class Key, class T, class Compare, class Alloc >
	void ft::map<Key, T, Compare, Alloc>::swap (ft::map<Key, T, Compare, Alloc>& x)
	{
		node_ptr tmp = x._Node;
		size_t tmp_i = x._size;

		x._Node = this->_Node;
		x._size = this->_size;

		this->_Node = tmp;
		this->_size = tmp_i;
	}
	template < class Key, class T, class Compare, class Alloc >
	void ft::map<Key, T, Compare, Alloc>::clear()
	{
		_size = 0;
		tree_clear(_Node);
		_Node = new node_type;
		//설명 : endNode 다시 넣어줌.
	}

	template < class Key, class T, class Compare, class Alloc >
	typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const
	{
		return (key_compare());
	}
	template < class Key, class T, class Compare, class Alloc >
	typename ft::map<Key, T, Compare, Alloc>::value_compare ft::map<Key, T, Compare, Alloc>::value_comp() const 
	{
        return (value_compare(key_compare()));
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

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator
	map<Key, T, Compare, Alloc>::find(const key_type &k) {
		iterator it = this->begin(), ite = this->end();

		while (it != ite)
		{
			if (this->_key_eq(it->first, k))
				break ;
			++it;
			if (it._node == NULL)
				break;
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

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::count (const key_type& k) const
	{
		return (BST_SearchNode_bool<node_ptr, Key>(_Node, k));
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator			map<Key, T, Compare, Alloc>::lower_bound (const key_type& k)
	{
		//설명 : find 안쓰고 while쓴 이유.
		//설명 : find 안에서 리턴할때 또 복사생성자를 하니까 segment가 뜬다.
		//설명 : 참조를 쓸려고 해도 지역변수로 선언해야해서, 그냥 while문 돌림.
		iterator it = this->begin(), ite = this->end();
	
		while (it != ite)
		{
			if (!this->k_comp(it->first, k))
				break;
			++it;
		}
		return (it);
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator		map<Key, T, Compare, Alloc>::lower_bound (const key_type& k) const
	{
		iterator it = this->begin();
		iterator ite = this->end();
	
		while (it != ite)
		{
			if (!this->k_comp(it->first, k))
				break;
			++it;
		}
		return (it);
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator			map<Key, T, Compare, Alloc>::upper_bound (const key_type& k)
	{
		iterator it = this->begin(), ite = this->end();

		while (it != ite)
		{
			if (this->k_comp(k, it->first))
				break;
			++it;
		}
		return (it);
		//return ( BST_SearchNode<node_ptr, Key>(_Node, k) );
	}
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator		map<Key, T, Compare, Alloc>::upper_bound (const key_type& k) const
	{
		iterator it = this->begin(), ite = this->end();

		while (it != ite)
		{
			if (this->k_comp(k, it->first))
				break;
			++it;
		}
		return (it);
	}		
	template<class Key, class T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::const_iterator,
			typename map<Key, T, Compare, Alloc>::const_iterator>
																map<Key, T, Compare, Alloc>::equal_range (const key_type& k) const
	{
		return (make_pair<const_iterator, const_iterator> (lower_bound(k), upper_bound(k)));
	}
	template<class Key, class T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, 
			typename map<Key, T, Compare, Alloc>::iterator>
																map<Key, T, Compare, Alloc>::equal_range (const key_type& k)
	{
		return (make_pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::allocator_type		map<Key, T, Compare, Alloc>::get_allocator() const
	{
		return (_alloc);
	}

	//=================================my_custor========================//
	template<class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::tree_clear(node_ptr node) {
		if (node == NULL)
			return ;
		this->tree_clear(node->leftChild);
		this->tree_clear(node->rightChild);
		this->_allocNode.deallocate(node, 1);
		node = NULL;
	}
	template <class Key, class T, class Compare, class Alloc>
	typename ft::map<Key, T, Compare, Alloc>::node_ptr			ft::map<Key, T, Compare, Alloc>::new_setNode(Key first, T second)
	{
		node_ptr tmp = _allocNode.allocate(1);
		tmp->data = pair<const Key, T> (first, second);
		tmp->data.first = first;
		tmp->data.second = second;

		return tmp;
	}
	template<class Key, class T, class Compare, class Alloc>
	bool
	map<Key, T, Compare, Alloc>::_key_eq(const key_type &k1, const key_type &k2) const {
		return (!this->k_comp(k1, k2) && !this->k_comp(k2, k1));
		//설명 : 같을 땐 항상 fail
	}

	//=======================Non-member function overloads=====================
	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? true : false);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{ return (!(lhs == rhs)); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<	(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{ return lexicographical_compare (lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) ? true : false; }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{ return ( !(rhs < lhs) ); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{ return ( rhs < lhs ); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{ return ( !(lhs < rhs) ); }
}

#endif
