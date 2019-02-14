//BinarySearchTree Abstract Data Type (ADT

#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template<class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
};

template <class elemType>
class BinarySearchTree
{
private:
	nodeType<elemType> *root;
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
	void destroy(nodeType<elemType>* &p);
	void inorder(nodeType <elemType> *p) const;
	void preorder(nodeType <elemType> *p) const;
	void postorder(nodeType <elemType> *p) const;
	int height(nodeType <elemType> *p) const;
	int max(int x, int y) const;
	int nodeCount(nodeType <elemType> *p) const;
	int leavesCount(nodeType <elemType> *p) const;
	bool lookup(nodeType<elemType> *p, const elemType& searchItem) const;
	void insert(nodeType <elemType>* &p, nodeType <elemType> *newNode);
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<elemType>&otherTree);
	const BinarySearchTree<elemType>& operator=(const BinarySearchTree<elemType>&);
	bool isEmpty() const;
	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	int treeHeight() const;
	int treeNodeCount() const;
	int treeLeavesCount() const;
	void destroyTree();
	bool lookupTree(const elemType &searchItem) const;
	void insertNode(const elemType& insertItem);
	void deleteNode(const elemType& deleteItem);
	~BinarySearchTree();
};

template<class elemType>
BinarySeachTree<elemType>::BinarySearchTree()
{
	root = nullptr;
}
template<class elemType>
bool BinarySearchTree<elemType>::isEmpty() const
{
	return(root == nullptr);
}
template<class elemType>
void BinarySeachTree<elemType>::inorderTraversal() const
{
	inorder(root);
}
template<class elemType>
void BinarySeachTree<elemType>::preorderTraversal() const
{
	preorder(root);
}
template<class elemType>
void BinarySeachTree<elemType>::postorderTraversal() const
{
	postorder(root);
}
template<class elemType>
int BinarySeachTree<elemType>::treeHeight() const
{
	return height(root);
}
template<class elemType>
int BinarySeachTree<elemType>::treeNodeCount() const
{
	return leavesCount(root);
}
template<class elemType>
const BinarySeachTree<elemType>& BinarySeachTree<elemType>::operator=(const BinarySeachTree <elemType>&
	otherTree)
{
	if (this != &otherTree)
	{
		if (root != nullptr)
			destroy(root);
		if (otherTree.root == nullptr)
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}
	return *this;
}
template<class elemType>
void BinarySeachTree<elemType>::destroyTree()
{
	destroy(root);
}
template<class elemType>
BinarySeachTree<elemType>::BinarySearchTree(const BinarySearchTree<elemType>& otherTree)
{
	if (otherTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root)
}
template<class elemType>
void BinarySearchTree<elemType>::inorder(nodeType<elemType> *p) const
{
	
}
template<class elemType>
void BinarySearchTree<elemType>::preorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}
template<class elemType>
void BinarySearchTree<elemType>::postorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
	
		preorder(p->lLink);
		preorder(p->rLink);
	cout << p->info << " ";
	}
}
template<class elemType>
void BinarySearchTree<elemType>::destroy(nodeType <elemType>* &p)
{
	if (p != nullptr)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
	}
}
template<class elemType>
int BinarySearchTree<elemType>::height(nodeType<elemType> *p) const
{
	if (p == nullptr)
		return 0;
	else 
		return 1 + max(height(p->lLink), height(p->rLink));
}
template<class elemType>
int BinarySearchTree<elemType>::nodeCount(nodeType<elemType> *p) const
{
	//FIXME
	cout << "write the definiton of the function nodeCount." << endl;
	//1. Base case
	//2. general case
	return 0;
}
template<class elemType>
int BinarySearchTree<elemType>::leavesCount(nodeType<elemType> *p) const
{
	//fixme
	cout << "write the definition of the function leavesCount.\n";
	//1. base case if the tree is empty return 0
	//2. base case if the left and righ subtrees are empty return 1

	//3. otherwise general case return sum of leaves count of left subtree and leaves count of right subtree
	return 0;
}
template<class elemType>
bool BinarySearchTree<elemType>::lookup(nodeType<elemType> *node, const elemType& searchItem) const
{
	//fixme
	return false;
}
template<class elemType>
void BinarySearchTree<elemType>::insert(nodeType<elemType>* &current, nodeType<elemType> *newNode)
{
	//fixme
}