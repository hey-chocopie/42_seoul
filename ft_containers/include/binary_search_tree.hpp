#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__
#include <iostream>
#include <string>
#include "pair.hpp"
#include "utility.hpp"
namespace ft
{
    template <typename pair_t>
    struct  map_Node
    {
    private:
        bool _unused;
        #if __APPLE__ == 0
            int _unused_for_linux;
        #endif
    public:
        pair_t					data;
        map_Node				*parent;
        map_Node				*leftChild;
        map_Node				*rightChild;
        
		map_Node(const pair_t &src = pair_t()) : \
        data(src),  parent(NULL), leftChild(NULL), rightChild(NULL) {};
		
		template <typename r_pair_t>
		map_Node& operator= (const map_Node<r_pair_t>& x);
    };

    template <typename pair_t>
	template <typename r_pair_t>
	map_Node<pair_t>&	map_Node<pair_t>::operator= (const map_Node<r_pair_t>& x)
	{
		data.first = x.first;
		data.second = x.second;
		data.parent = x.parent;
		data.leftChild = x.leftChild;
		data.rightChild = x.rightChild;
	}
	// 설명 : 가장 왼쪽 노드 찾기.
    template <class Node>
	Node* minNode(Node* tree)
	{
		while (tree->leftChild != NULL)
			tree = tree->leftChild;
		return (tree);
	}
	// 설명 : 가장 오른쪽 노드 찾기.
    template <class Node>
	Node* maxNode(Node* tree)
	{
		while (tree->rightChild != NULL)
			tree = tree->rightChild;
		return (tree);
	}
	// 설명 : target이 있으면 true 리턴
    template <class node_ptr, typename Key>
	bool BST_SearchNode_bool(node_ptr tree, node_ptr endNode, Key target) 
	{
	    if (tree == NULL || tree == endNode) 
	        return false;
	
	    if (tree->data.first == target)
	        return true;
	    else if (tree->data.first > target)
	        return BST_SearchNode_bool(tree->leftChild, endNode, target);
	    else if (tree->data.first < target)
	        return BST_SearchNode_bool(tree->rightChild, endNode, target);
		return (true);
	}
	// 설명 : target 이 있는 노드 리턴
    template <class node_ptr, typename Key>
	node_ptr BST_SearchNode(node_ptr tree, node_ptr endNode, Key target)
	{
	    if (tree == NULL || tree == endNode)
	        return NULL;
	    if (tree->data.first == target)
	        return tree;
	    else if (tree->data.first > target)
	        return BST_SearchNode(tree->leftChild, endNode, target);
	    else
	        return BST_SearchNode(tree->rightChild, endNode, target);
	}

	// 설명 : 적절한 위치에 값 삽입.
	template <typename pair_t, typename key_compare>
	void BST_InsertNode(map_Node<pair_t>** tree, map_Node<pair_t>* node, map_Node<pair_t> *endNode, size_t _size)
	{
		key_compare				k_comp;
		//map_Node<pair_t>		*endNode;
		//설명 : endNode는 이진탐색트리중 맨 오른쪽 노드. end()를 호출 사용될 노드.

		node->rightChild = 0; 
		node->leftChild = 0;
		//추가 : 0넣기 전에 만약 메모리 값이 있으면 메모리 헤제 시키자. 해야할거 같음. 아직안함.
		if (_size == 0)
		{
			*tree = node;
			endNode->parent = (*tree);
			(*tree)->rightChild = endNode;
			return;
		}
		if (node->data.first != (*tree)->data.first)
			node->parent = (*tree);
		//설명 : 삽입할 노드가 작은 경우
	    if (k_comp(node->data.first, (*tree)->data.first))
		{
	        if ((*tree)->leftChild == NULL)
			{
	            (*tree)->leftChild = node;
	            return;
	        }
	        else
	            BST_InsertNode<pair_t, key_compare>(&(*tree)->leftChild, node, endNode, _size);
		}
		//설명 : 삽입할 노드가 큰 경우
	    else if (!k_comp(node->data.first, (*tree)->data.first))
		{
	        if ( (*tree)->rightChild == endNode) {
				node->parent = (*tree);
	            (*tree)->rightChild = node;
				node->rightChild = endNode;
				endNode->parent = (node);
	            return;
	        }
			else if ( (*tree)->rightChild == NULL)
			{
				node->parent = (*tree);
	            (*tree)->rightChild = node;
			}
	        else
			{
	            BST_InsertNode<pair_t, key_compare>(&(*tree)->rightChild, node, endNode, _size);
			}
	    }
	}
	// 설명 : 노드 제거.
	template <typename pair_t, typename alloc_T>
	void Null_deallocate(map_Node<pair_t>* tree, alloc_T &_allocNode)
	{
		_allocNode.deallocate(tree, 1);
		tree = NULL;
	}
	//설명 : 해당 노드 제거
    template <class node_ptr, typename alloc_Node_type>
	void BST_RemoveNode(node_ptr *rmNode, node_ptr *_Node, alloc_Node_type _allocNode) 
	{
		node_ptr	replaceNode = NULL;
		node_ptr	*rmPlace = _Node;

		if ((*rmNode)->parent)
			rmPlace = ((*rmNode)->parent->leftChild == (*rmNode) ? &(*rmNode)->parent->leftChild : &(*rmNode)->parent->rightChild);
		if ((*rmNode)->leftChild == NULL && (*rmNode)->rightChild == NULL)
			;
		else if ((*rmNode)->leftChild == NULL)
			replaceNode = (*rmNode)->rightChild;
		else
		{
			replaceNode = maxNode((*rmNode)->leftChild);
			if (replaceNode != (*rmNode)->leftChild)
				if ((replaceNode->parent->rightChild = replaceNode->leftChild))
					replaceNode->leftChild->parent = replaceNode->parent;
		}
		// 설명 : 자르는 위치에 넣을 replaceNode
		if (replaceNode)
		{
			replaceNode->parent = (*rmNode)->parent;
			if ((*rmNode)->leftChild && (*rmNode)->leftChild != replaceNode)
			{
				replaceNode->leftChild = (*rmNode)->leftChild;
				replaceNode->leftChild->parent = replaceNode;
			}
			if ((*rmNode)->rightChild && (*rmNode)->rightChild != replaceNode)
			{
				replaceNode->rightChild = (*rmNode)->rightChild;
				replaceNode->rightChild->parent = replaceNode;
			}
		}
		*rmPlace = replaceNode;
		_allocNode.deallocate((*rmNode), 1);
	}
}
#endif

