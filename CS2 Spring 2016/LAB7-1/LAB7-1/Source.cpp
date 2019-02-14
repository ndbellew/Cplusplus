/*
Nathan Bellew
April 26, 2016
CS2
Lab 7*/
#include <iomanip>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


void main()
{
	int num;
	BinarySearchTree<int> tree;
	if (tree.isEmpty())
		cout << "Tree is Empty!\n";
	else
		cout << "Tree is not Empty!\n";
	cout << "Adding numbers to tree.\n";
	tree.insertNode(50);
	tree.insertNode(67);
	tree.insertNode(23);
	tree.insertNode(45);
	tree.insertNode(89);
	tree.insertNode(12);
	tree.insertNode(5);
	tree.insertNode(1);
	tree.insertNode(99);
	tree.insertNode(68);
	tree.insertNode(14);
	if (tree.isEmpty())
		cout << "Tree is Empty!\n";
	else
		cout << "Tree is not Empty!\n";
	cout << "Preorder Traversal: ";
	tree.preorderTraversal();
	cout << endl<<"Inorder Traversal: ";
	tree.inorderTraversal();
	cout <<endl<< "Postorder Traversal: ";
	tree.postorderTraversal();
	cout << endl;
	cout << "Tree Height: " << tree.treeHeight()<<endl;
	cout << "Tree Node Count: " << tree.treeNodeCount() << endl;
	cout << "Tree Leaves Count: " << tree.treeLeavesCount() << endl;
	num = 3;
	cout << "Looking up tree with number " << num<<": ";
	if (tree.lookupTree(num))
		cout << "In Tree!\n";
	else
		cout << "Not in Tree!\n";
	cout << "Looking up tree with number: 67";
	if (tree.lookupTree(67))
		cout << "In Tree!\n";
	else
		cout << "Not in Tree!\n";
	cout << "Creating newtree and setting it equal to original tree.\n";
	BinarySearchTree<int> newtree=tree;
	if (newtree.isEmpty())
		cout << "Newtree is Empty!\n";
	else
		cout << "Newtree is not Empty!\n";
	cout << "Original tree destroyed!\n";
	tree.destroyTree();
	cout << "Newtree Preorder Traversal: ";
	newtree.preorderTraversal();
	cout << endl << "Newtree Inorder Traversal: ";
	newtree.inorderTraversal();
	cout << endl << "Newtree Postorder Traversal: ";
	newtree.postorderTraversal();
	cout << endl;
	system("pause");
}