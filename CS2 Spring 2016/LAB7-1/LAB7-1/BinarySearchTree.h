#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
// Definition of the BinaryTree Node
template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
};
//Definition of the BinarySearchTree class
template <class elemType>
class BinarySearchTree
{
private:
	nodeType<elemType> *root;
	void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
	// Makes a copy of the binary tree to which
	// otherTreeRoot points.
	// Postcondition: The pointer copiedTreeRoot points to
	//				  the root of the copied binary tree.
	void destroy(nodeType <elemType>* &p);
	// Function to destroy the binary tree to which p points.
	// Postcondition: Memory space occupied by each node, in 
	//				  the binary tree to which p points, is
	//				  deallocated.
	//				  p = nullptr;
	void inorder(nodeType<elemType> *p) const;
	// Function to do an inorder traversal of the binary
	// tree to which p points.
	// Postcondition: Nodes of the binary tree, to which p
	//				  points, are printed inorder sequence.
	void preorder(nodeType<elemType> *p) const;
	// Function to do a preorder traversal of the binay
	// tree to which p points.	// Postcondition: Nodes of the binary tree, to which p points, are printed in preorder sequence.
	void postorder(nodeType<elemType> *p) const;
	// Function to do a postorder traversal of the binary tree to which p points.
	// Postconditional: Nodes of the binary tree, to which p points, are printed in postorder sequence.
	int height(nodeType<elemType> *p) const;
	// Finction to determine the height of the binary tree to which p points.
	//Postcondition: heigh of the binary tree to which p points is returned.
	int max(int x, int y) const;
	// Function to determine the larger of x and y.
	// Postcondition: Returns the larger of x and y.
	int nodeCount(nodeType<elemType> *p) const;
	// Function to determine the number of nodes in the binary tree to which p points.
	// Postcondition: The number of nodes in the binary tree to which p points is returned
	int leavesCount(nodeType<elemType> *p) const;
	// // Function to determine the number of leaves in the binary tree to which p points.
	// Postcondition: The number of leaves in the binary tree to which p points is returned
	bool lookup(nodeType<elemType> *p, const elemType& searchItem) const;
	// Function to determine if searchItem is in the binary tree.
	// Postcondition: Returns true if searchItem is found in the binary tree; otherwise, returns false.
	void insert(nodeType<elemType>* &p, nodeType<elemType> *newNode);
	// Function to insert newNode in the binaey tree.
	// Postcondition: If there is no node in the binary tree that has the same info as newNode, a 
	//				  node with the info newNode is creatred and inserted in the binary search tree
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<elemType>& otherTree);
	// copy constructor
	const BinarySearchTree<elemType>& operator=(const BinarySearchTree<elemType>&);
	// Overload the assignment operator.
	bool isEmpty() const;
	// Function to determine wheather the binary tree is empty.
	// Postcondition: Return truw if the binary tree is empty; otherwise, returns false.
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
	// Function to delete deleteItem from the binary tree
	// Postcondition: If a node with the same info as deleteItem is found, it is deleted from the 
	//				  binary tree. If the binary tree is empty or deleteItem is not in the binary tree,
	//				  an appropriate message is printed.
	~BinarySearchTree();
};
// Definition of member functions
template <class elemType>
BinarySearchTree<elemType>::BinarySearchTree()
{
	root = nullptr;
}
template <class elemType>
bool BinarySearchTree<elemType>::isEmpty() const
{
	return (root == nullptr);
}
template <class elemType>
void BinarySearchTree<elemType>::inorderTraversal() const
{
	inorder(root);
}
template <class elemType>
void BinarySearchTree<elemType>::preorderTraversal() const
{
	preorder(root);
}
template <class elemType>
void BinarySearchTree<elemType>::postorderTraversal() const
{
	postorder(root);
}
template <class elemType>
int BinarySearchTree<elemType>::treeHeight() const
{
	return height(root);
}
template <class elemType>
int BinarySearchTree<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}
template <class elemType>
int BinarySearchTree<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}
template <class elemType>
const BinarySearchTree<elemType>& BinarySearchTree<elemType>::operator=(const BinarySearchTree<elemType> &othertree)
{
	if (this != &otherTree) // avoid self-copy
	{
		if (root != nullptr) // if binary tree is not empty
			// destroy the binary tree
			destroy(root);

		if (otherTree.root == nullptr) // otherTree is empty
			root = nullptr;
		else
			copyTree(root, otherTree.root);
	}
	return *this;
}
template <class elemType>
void BinarySearchTree<elemType>::destroyTree()
{
	destroy(root);
}
template <class elemType>
BinarySearchTree<elemType>::BinarySearchTree(const BinarySearchTree<elemType>& otherTree)
{
	if (otherTree.root == nullptr) // other tree is empty
		root = nullptr;
	else
		copyTree(root, otherTree.root);
}
template <class elemType>
bool BinarySearchTree<elemType>::lookupTree(const elemType &searchItem) const
{
	return lookup(root, searchItem);
}
template <class elemType>
void BinarySearchTree<elemType>::insertNode(const elemType& insertItem)
{
	nodeType<elemType> *newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	insert(root, newNode);
}
template <class elemType>
BinarySearchTree<elemType>::~BinarySearchTree()
{
	destroy(root);
}
// Private member functions
template <class elemType>
void BinarySearchTree<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType <elemType> *otherTreeRoot)
{
	if (otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	else
	{
		copiedTreeRoot = new nodeType < elemType >;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}
template <class elemType>
void BinarySearchTree<elemType>::inorder(nodeType <elemType> *p) const
{
	//FIXED
	if (p != nullptr)
	{
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}
template <class elemType>
void BinarySearchTree<elemType>::preorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}
template <class elemType>
void BinarySearchTree<elemType>::postorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		postorder(p->lLink);
		postorder(p->rLink);
		cout << p->info<< " ";
	}
}
template <class elemType>
void BinarySearchTree<elemType>::destroy(nodeType<elemType>* &p)
{
	if (p != nullptr)
	{
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
	}
}
template <class elemType>
int BinarySearchTree<elemType>::height(nodeType<elemType> *p) const
{
	if (p == nullptr)
		return 0;
	else
		return 1 + max(height(p->lLink), height(p->rLink));
}
template <class elemType>
int BinarySearchTree<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}
template <class elemType>
int BinarySearchTree<elemType>::nodeCount(nodeType<elemType> *p) const
{
	//FIXED
	// cout << "Write the definition of the function nodeCount." << endl;
	if (p == nullptr)
		return 0;
	else
		return (1 + nodeCount(p->lLink) + nodeCount(p->rLink));
}
template <class elemType>
int BinarySearchTree<elemType>::leavesCount(nodeType<elemType> *p) const
{
	//FIXED
	// cout << "Write the definiton of the fiunction leavesCount" << endl;
	if (p == nullptr)
		return 0;
	else if (p->lLink == nullptr && p->rLink == nullptr)
		return 1;
	else
		return (leavesCount(p->rLink) + leavesCount(p->lLink));
}
template <class elemType>
bool BinarySearchTree<elemType>::lookup(nodeType<elemType> *node, const elemType& searchItem) const
{
	//FIXED
	if (node ==nullptr)
		return false;
	else if (node->info == searchItem)
		return true;
	else if (node->info > searchItem)
		return lookup(node->lLink, searchItem);
	else
		return lookup(node->rLink, searchItem);
}
template <class elemType>
void BinarySearchTree<elemType>::insert(nodeType<elemType>* &current, nodeType<elemType> *newNode)
{
	// FIXED
	/*
	Give a binary search tree and a number, inserts a new node
	with the given number in the correct place in the tree.
	Since the node could be changed, it's pass by reference.
	*/
	if (current == nullptr)
	current = newNode;
	else if (current->info == newNode->info)
		cout << "Duplicates are NOT allowed!\n";
	else if (current->info > newNode->info)
		return insert(current->lLink, newNode);
	else
		return insert(current->rLink, newNode);
	
}