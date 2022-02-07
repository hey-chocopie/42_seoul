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
//        map_Node     *parent = NULL;
        map_Node     *leftChild;
        map_Node     *rightChild;
        map_Node(const pair_t &src = pair_t()) : \
        data(src),  leftChild(NULL), rightChild(NULL) {};
    };

	// 트리에 target 이 있다면 true 리턴
    template <typename pair_t>
	bool BST_SearchNode(map_Node<pair_t>* tree, pair_t target) 
	{
	    if (tree == NULL)
	        return false;
	
	    if (tree->data.first == target.first)
	        return true;
	    else if (tree->data.first > target.first)
	        return BST_SearchNode(tree->leftChild, target);
	    else if (tree->data.first < target.first)
	        return BST_SearchNode(tree->rightChild, target);
		return (true);
	}

	// 트리에 target 이 있다면 해당 노드 리턴
    template <typename pair_t>
	map_Node<pair_t>& BST_SearchNode(map_Node<pair_t>& tree, pair_t target)
	{
	    if (tree == NULL)
	        return NULL;
	
	    if (tree._Node.first == target.first)
	        return tree;
	    else if (tree._Node.first > target.first)
	        return BST_SearchNode(tree->leftChild, target);
	    else if (tree._Node.first < target.first)
	        return BST_SearchNode(tree->rightChild, target);
	}


	//적절한 위치에 값 삽입.
	template <typename pair_t>
	void BST_InsertNode(map_Node<pair_t>* tree, map_Node<pair_t>* node)
	{
	    if (node->data.first < tree->data.first) { // 현재 재귀 단계에서의 트리의 루트와 크기 비교 (서브트리의 루트)
	        if (tree->leftChild == NULL) { // 루트보다 작은데 마침 루트에게 왼쪽 자식이 없다면 루트의 왼쪽 자식으로 세팅 후 종료
	            tree->leftChild = node;
	            return;
	        }
	        else
	            BST_InsertNode(tree->leftChild, node); // 루트보다 작은데 루트에게 왼쪽 자식이 있다면 거기에 추가될 수 없으므로 더 내려가야 함. 왼쪽 서브트리로 내려가기.
	    }
	    else if (node->data.first > tree->data.first) {  // 루트보다 큰데 마침 루트에게 오른쪽 자식이 없다면 루트의 오른쪽 자식으로 세팅 후 종료
	        if (tree->rightChild == NULL) {
	            tree->rightChild = node;
	            return;
	        }
	        else
	            BST_InsertNode(tree->rightChild, node); // 루트보다 큰데 루트에게 오른쪽 자식이 있다면 거기에 추가될 수 없으므로 더 내려가야 함. 오른쪽 서브트리로 내려가기.
	    }
	}

	template <typename pair_t>
	map_Node<pair_t>* BST_SearchMinNode(map_Node<pair_t>* tree)
	{
	    if (tree == NULL)
	        return NULL;
	
	    if (tree->left == NULL)
	        return tree;
	    else
	        return BST_SearchMinNode(tree->left);
	}

	template <typename pair_t>
	map_Node<pair_t>* BST_RemoveNode(map_Node<pair_t>* tree, map_Node<pair_t>* parent, pair_t target)
	{
	    // target과 일치하는 노드는 삭제할 노드다.
	    // 삭제할 노드의 위치가 되는 노드는 tree 에, 삭제할 노드의 부모는 parent 에 저장된다.
	    // 삭제할 노드(tree)는 removedNode 에 복사해 옮겨두고 나중에 이를 리턴한다.
	    // tree 의 값을 새롭게 세팅해 이제 삭제되고 새로운 노드로 대체된 것처럼 연산해준다. 
	
	    if (tree == NULL) 
	        return NULL;
	        
	    map_Node<pair_t>* removedNode = NULL;
	    
	    /* 삭제할 노드 탐색하기*/
	    if (tree->data.first > target.first)
	        removedNode = BST_RemoveNode(tree->left, tree, target);
	    else if (tree->data.first < target.first)
	        removedNode = BST_RemoveNode(tree->right, tree, target);
	    else if (tree->data.first == target.first) { // 삭제할 노드 찾음
	        removedNode = tree; // 삭제된 노드 리턴할거라 삭제 작업 전 캐싱
	
	        // 1. 삭제하려는 노드의 자식 서브트리가 0 개 일때 (=단말노드)
	        if (tree->left == NULL && tree->right == NULL) {
	            if (parent->left == tree)
	                parent->left = NULL;
	            if (parent->right == tree)
	                parent->right = NULL;
	        }
	        // 2. 삭제하려는 노드의 자식 서브트리가 1 개 일때
	        else if (tree->left == NULL || tree->right == NULL) {
	            map_Node<pair_t>* temp = NULL;
	            if (tree->left != NULL)
	                temp = tree->left;
	            else
	                temp = tree->right;
	
	            if (parent->left == tree)
	                parent->left = temp;
	            else
	                parent->right = temp;
	        }
	        // 3. 삭제하려는 노드의 자식 서브트리가 2 개 일 때
	        else if (tree->left != NULL && tree->right != NULL) {
	            map_Node<pair_t>* minNode_Of_BiggerNodes = BST_SearchMinNode(tree->right);
	            minNode_Of_BiggerNodes = BST_RemoveNode(tree, NULL, minNode_Of_BiggerNodes->data);
	            tree->data = minNode_Of_BiggerNodes->data;
	        }
	    }	
	    return removedNode;
	}
}

#endif

