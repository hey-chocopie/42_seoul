#ifndef MAP_ITER_HPP
# define MAP_ITER_HPP

#include "utility.hpp"

namespace ft {

template <typename T, typename node_type>
class mapIte {
	public:
		node_type						*_node;
		mapIte(node_type *src);

	public:
		typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;

		mapIte(void);

		template <typename RmapIte>
		mapIte(const RmapIte &src);

		virtual ~mapIte(void);
		mapIte	&operator=(mapIte const &rhs);

		template <class U> bool	operator==(const mapIte<U, node_type> &rhs) const;
		template <class U> bool	operator!=(const mapIte<U, node_type> &rhs) const;

		mapIte		&operator++(void);
		mapIte		operator++(int);
		mapIte		&operator--(void);
		mapIte		operator--(int);

		reference	operator*(void) const;
		pointer		operator->(void) const;

		operator mapIte<const T, node_type>(void) const {
			return mapIte<const T, node_type>(this->_node);
		}


		template <class, class, class, class>
		friend class map;

		template <class, class>
		friend class mapIte;

}; 

template <typename T, typename node_type>
mapIte<T, node_type>::mapIte(void) : _node(NULL) { }

template <typename T, typename node_type>
mapIte<T, node_type>::mapIte(node_type *src)
{
	this->_node = src; 
}

template <typename T, typename node_type>
template <typename RmapIte>
mapIte<T, node_type>::mapIte(const RmapIte &src) 
{
	this->_node = src._node;
	
}

template <typename T, typename node_type>
mapIte<T, node_type>::~mapIte(void) { return ; }

template <typename T, typename node_type>
mapIte<T, node_type> &mapIte<T, node_type>::operator=(const mapIte &rhs) {
	if (this == &rhs)
		return (*this);
	this->_node = rhs._node;
	return (*this);
}

template <typename T, typename node_type> template <class U>
bool	mapIte<T, node_type>::operator==(const mapIte<U, node_type> &rhs) const {
	return (this->_node == rhs._node);
}

template <typename T, typename node_type> template <class U>
bool	mapIte<T, node_type>::operator!=(const mapIte<U, node_type> &rhs) const {
	return (this->_node != rhs._node);
}

template <typename T, typename node_type>
mapIte<T, node_type> &mapIte<T, node_type>::operator++(void) {
	if (this->_node->rightChild != NULL)
	{
		this->_node = minNode(this->_node->rightChild);
	}
	else
	{
		node_type	*child = this->_node;

		this->_node = this->_node->parent;
		while (this->_node && child == this->_node->rightChild)
		{
			child = this->_node;
			this->_node = this->_node->parent;
		}
	}
	return (*this);
}

template <typename T, typename node_type>
mapIte<T, node_type> mapIte<T, node_type>::operator++(int) {
	mapIte	tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T, typename node_type>
mapIte<T, node_type>& mapIte<T, node_type>::operator--(void) {
	if (this->_node->leftChild != NULL)
		this->_node = maxNode(this->_node->leftChild);
	else
	{
		node_type	*child = this->_node;

		this->_node = this->_node->parent;
		while (this->_node && child == this->_node->leftChild)
		{
			child = this->_node;
			this->_node = this->_node->parent;
		}
	}
	return (*this);
}

template <typename T, typename node_type>
mapIte<T, node_type> mapIte<T, node_type>::operator--(int) {
	mapIte	tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T, typename node_type>
typename mapIte<T, node_type>::reference mapIte<T, node_type>::operator*(void) const {
	return (this->_node->data);
}

template <typename T, typename node_type>
typename mapIte<T, node_type>::pointer mapIte<T, node_type>::operator->(void) const {
	return &(this->operator*());
}

} 

#endif 
