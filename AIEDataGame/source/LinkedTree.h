#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

//used to allow the player to specify the search method for the transversal of trees
enum class SearchMethod
{
	DEPTH_PRE_ORDER,
	DEPTH_POST_ORDER,
	BREADTH_ORDER
};

/*
* class TreeNode
* template
*
* an item that belongs to a tree, holds a value, link to it's parent
* and a collection of nodes that have it as it's parent
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class TreeNode
{
public:

	/*
	* TreeNode<T>()
	* template
	* default constructor
	*/
	TreeNode<T>() {
		std::cout << "Tree Node created without parameters\n\n";
	};
	TreeNode<T>(unsigned int _line, char* _filename) { line = _line; filename = _filename; 
		std::cout << "Tree Node created on " << line << " in " << std::string(filename);
		std::cout << "\n\n";
	}

	/*
	* ~TreeNode<T>()
	* template
	* destructor, gets called recursively on all children in the tree
	*/
	~TreeNode<T>()
	{
		std::cout << "Tree Node deleted on " << line << " in " << std::string(filename);
		std::cout << "\n\n";

		LinkedList<TreeNode<T>*>::Iterator childIter = children.begin();

		//iterate through all children, remembering the pointer and then deleting it
		while (childIter != children.end())
		{
			TreeNode<T>* childNode = childIter.m_node->value;

			delete childNode;

			childIter++;
		}
	};

	/*
	* getRoot
	*
	* finds the uppermost node on the tree that this node belongs to
	* will recursively call upon the parents to find the uppermost node
	*
	* @returns TreeNode<T>* pointer to the root node;
	*/
	TreeNode<T>* getRoot()
	{
		if (parent == nullptr)
		{
			return this;
		}
		else
		{
			return parent->getRoot();
		}
	}

	T value;
	
	char* filename = ""; //this too >>>
	unsigned int line = 0; //DELETE THIS asdfhapsoifasdfhkajsdhfkashdflkasdhflkjhadsflksahdlkjhsadfklhasdklfhaslkjdfhkasdjfhklasdjhfklasjdasdadasdasdasdasdasdasdassd
	TreeNode<T>* parent = nullptr; //the node that this node is parented to
	LinkedList<TreeNode<T>*> children = LinkedList<TreeNode<T>*>(0); //the nodes parented to this node
};



/*
* class LinkedTree
* template
*
* manages a resizable collection of nodes with a growing amount
* of diversions from a root
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class LinkedTree
{
public:

	/*
	* LinkedTree<T>()
	* template
	* default constructor
	*/
	LinkedTree<T>() {};

	/*
	* ~LinkedTree<T>()
	* template
	* destructor, deletes its root, therefore deleting all branches recursively
	*/
	~LinkedTree<T>()
	{
		//don't delete any nodes if the root is part of another tree
		if (!isSubTree)
		{
			delete m_root;
		}

	}

	/*
	* clear
	* 
	* deletes the root, therefore deleting all branches recursively
	*
	* @returns void
	*/
	void clear()
	{
		if (!isSubTree)
		{
			delete m_root;
		}

		m_root = nullptr;
	}

	/*
	* getRoot
	* template
	*
	* gets the uppermost root of the tree
	*
	* @returns TreeNode<T>* - pointer to the root node
	*/
	TreeNode<T>* getRoot()
	{
		return m_root;
	}

	/*
	* setRoot
	* template
	*
	* @param TreeNode<T>* rootPtr - the new root
	* @returns void
	*/
	void setRoot(TreeNode<T>* rootPtr)
	{
		m_root = rootPtr;

		//check if the tree is a sub-tree of another
		isSubTree = m_root->parent != nullptr;
	}

	/*
	* extend
	* template
	*
	* adds a new node with the specified value as a child of the specified tree node
	*
	* @param TreeNode<T>* parent - pointer to the parent node
	* @param T value - value of the new node
	*
	* @returns void
	*/
	void extend(TreeNode<T>* parent, T value)
	{
		//create a new node with the given node
		TreeNode<T>* newNode = new TreeNode<T>();
		newNode->value = value;

		//give the new node the parent
		newNode->parent = parent;

		//add the child to the parent's children list
		parent->children.pushBack(newNode);
	}

	/*
	* extend
	* template
	*
	* adds an existing node (including it's children) as a child of the specified tree node
	*
	* @param TreeNode<T>* parent - pointer to the parent node
	* @param TreeNode<T>* existing - pointer to the existing node to add
	*
	* @returns void
	*/
	void extend(TreeNode<T>* parent, TreeNode<T>* existing)
	{
		//give the existing tree node the parent
		existing->parent = parent;

		//add the child to the parent's children list
		parent->children.pushBack(existing);
	}

	/*
	* extend
	* template
	*
	* adds a tree to a node in another tree
	*
	* @param TreeNode<T>* parent - pointer to the parent node
	* @param LinkedTree<T>& existingTree - reference to the tree to add
	*
	* @returns void
	*/
	void extend(TreeNode<T>* parent, LinkedTree<T>& existingTree)
	{
		//give the root of the existing tree the parent
		existingTree.m_root->parent = parent;

		//add the existing tree's root to the parent's children list
		parent->children.pushBack(existingTree.m_root);

		existingTree.isSubTree = true;
	}

	/*
	* getSubTree
	*
	* gets or seperates a sub-tree given the new root node
	*
	* @param TreeNode<T>* root - the new root node of the sub-tree
	* @param prune = false - flag indicating to seperate the sub-tree or not
	* @returns LinkedTree<T> - the sub-tree
	*/
	LinkedTree<T> getSubTree(TreeNode<T>* root, bool prune = false)
	{
		LinkedTree<T> subTree = LinkedTree<T>();

		//set the root of the subtree to the specified node
		subTree.setRoot(root);

		if (prune)
		{
			LinkedList<TreeNode<T>*>::Iterator childIter = root->parent->children.begin();

			//sequential search for the LinkedNode that contains the child in the parent
			for (; childIter != root->parent->children.end(); childIter++)
			{
				if (childIter.m_node->value == root)
				{
					break;
				}
			}

			//erase the parent's link to the child being removed
			root->parent->children.erase(childIter.m_node);

			//erase the child's link to it's parent
			root->parent = nullptr;

		}
		
		//if the subTree was not seperated from the tree, it is a subtree
		subTree.isSubTree = !prune;

		return subTree;
	}

	/*
	* prune
	* template
	*
	* recursively deletes part of the tree
	* below the node given 
	*
	* @param TreeNode<T>* node - the node to delete along with it's children
	* @returns void
	*/
	void prune(TreeNode<T>* node)
	{
		LinkedList<TreeNode<T>*>::Iterator childIter = node->parent->children.begin();

		//sequential search for the LinkedNode that contains the child in the parent
		for (; childIter != node->parent->children.end(); childIter++)
		{
			if (childIter.m_node->value == node)
			{
				break;
			}
		}

		//remove the link from the parent
		node->parent->children.erase(childIter.m_node);

		delete node;
	}

	/*
	* getList
	* template
	* 
	* gets the tree as a referenced LinkedList
	* since there are multiple ways to display the order of a list, the
	* appropriate sub-function is called
	*
	* @param SearchMethod searchMethod - the method of adding the elements to the list
	* @returns LinkedList<TreeNode<T>*> - a list of pointed to elements (allows modification without duplication)
	*/
	LinkedList<T*> getList(SearchMethod searchMethod)
	{
		LinkedList<TreeNode<T>*>* nodeList = &(LinkedList<TreeNode<T>*>(0));

		//get a list of the desired tree nodes in order
		switch (searchMethod)
		{
		case SearchMethod::DEPTH_PRE_ORDER: getDepthPreList(m_root, nodeList); break;
		case SearchMethod::DEPTH_POST_ORDER: getDepthPostList(m_root, nodeList); break;
		case SearchMethod::BREADTH_ORDER: getBreadthList(nodeList); break;
		}

		LinkedList<T*> refList = LinkedList<T*>(0); //list to store pointers to the data
		LinkedList<TreeNode<T>*>::Iterator nodeIter = nodeList->begin(); //iterator for the tree node list

		//iterate through all of the tree nodes
		for (;nodeIter != nodeList->end(); nodeIter++)
		{
			refList.pushBack(&nodeIter.m_node->value->value);
		}

		return refList;
	}

private:

	//allow tree node to access the private variables
	friend TreeNode<T>;

	TreeNode<T>* m_root = nullptr;
	bool isSubTree = false; //set true if the root is parented to another node

	/*
	* getDepthPreList
	* template
	* 
	* gets the tree as a list of nodes transversed in Depth-First Pre-Order
	* parent node first then children
	*
	* @param TreeNode<T>* treeNode - the node that has been transversed to
	* @param LinkedList<TreeNode<T>*>* refList - the list, passed on through recursion, defaulted to an empty list
	* @returns void
	*/
	void getDepthPreList(TreeNode<T>* treeNode, LinkedList<TreeNode<T>*>* refList)
	{
		refList->pushBack(treeNode);

		LinkedList<TreeNode<T>*>::Iterator childIter = treeNode->children.begin();

		//iterate through all of the children
		for (; childIter != treeNode->children.end(); childIter++)
		{
			getDepthPreList(childIter.m_node->value, refList);
		}
	}

	/*
	* getDepthPostList
	* template
	*
	* gets the tree as a list of nodes transversed in Depth-First Post-Order
	* chilrden first then parent
	*
	* @param TreeNode<T>* treeNode - the node that has been transversed to
	* @param LinkedList<TreeNode<T>*>* refList - the list, passed on through recursion, defaulted to an empty list
	* @returns void
	*/
	void getDepthPostList(TreeNode<T>* treeNode, LinkedList<TreeNode<T>*>* refList)
	{
		LinkedList<TreeNode<T>*>::Iterator childIter = treeNode->children.begin();

		//iterate through all of the children
		for (;childIter != treeNode->children.end(); childIter++)
		{
			getDepthPostList(childIter.m_node->value, refList);
		}

		refList->pushBack(treeNode);
	}

	/*
	* getBreadthList
	* template
	*
	* gets the tree as a list of nodes transversed in Breadth-First Order
	* display the entire level of a tree first, then move on to the next level
	*
	* @param LinkedList<TreeNode<T>*>* refList - the list, passed on through recursion, defaulted to an empty list
	* @returns void
	*/
	void getBreadthList(LinkedList<TreeNode<T>*>* refList)
	{
		refList->pushBack(m_root);

		LinkedList<TreeNode<T>*>::Iterator refIter = refList->begin();

		//continue adding the children of every node to the same list that is being iterated through
		for (;refIter != refList->end(); refIter++)
		{
			LinkedList<TreeNode<T>*>::Iterator childIter = refIter.m_node->value->children.begin();

			//add the children of every node
			for (; childIter != refIter.m_node->value->children.end(); childIter++)
			{
				refList->pushBack(childIter.m_node->value);
			}
		}
	}
};