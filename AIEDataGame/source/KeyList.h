#pragma once
#include "LinkedTree.h"

int const MAX_KEY = 500;

//forward decleration for KeyNode (required because KeyList and KeyNode both reference each other)
TEMPLATE
class KeyList;

/*
* class KeyNode
* template
*
* stores data with an associated key used to identify
* the data when searching in a KeyList
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class KeyNode
{
public:

	/*
	* KeyNode<T>()
	* template
	* default constructor
	*/
	KeyNode<T>() {}

	/*
	* KeyNode<T>()
	* template
	* constructor, assigns values to the key and value
	*
	* @param char _key[MAX_KEY] - what to assign the key to
	* @param T _value - what to assign the held value to
	*/
	KeyNode<T>(char _key[MAX_KEY], T _value) : value(_value) 
	{
		strcpy_s(key, _key);
	}

	/*
	* KeyNode<T>()
	* template
	* default destructor
	*/
	~KeyNode<T>() {}

	/*
	* checkAlpha
	*
	* checks if the stored key comes in relation to 'other'
	* in alphabetical order by examining the letters ascii numbers (a = 97, b = 98)
	*
	* @param char other[MAX_KEY] - the key to compare the stored key to
	* @returns int - indicates the order -1 for higher order 'a' vs 'c', 1 for lower order 'c' vs 'a', 0 for equal 'b' vs 'b'
	*/
	int checkAlpha(char other[MAX_KEY])
	{
		//iterate through all of the letters
		for (int i = 0; i < MAX_KEY; i++)
		{
			if (key[i] > other[i]) //the stored key's letter has a higher ascii number, indicating lower alphabetical order
			{
				return -1;
			}
			else if (key[i] < other[i]) //the stored key's letter has a lower ascii number, indicating higher alphabetical order
			{
				return 1;
			}
			else if (key[i] == '\0' && other[i] == '\0') //both are terminating at the same time, indicating that they are identical
			{
				break;
			}

			//continue to the next letter, the letters of the stored key and 'other' match
		}

		return 0; //the keys are identical
	}

	/*
	* getKey
	* template
	*
	* gets the key held by the node
	* @returns char* - the key held by the node
	*/
	char* getKey()
	{
		return key;
	}

	/*
	* getValue
	* template
	*
	* gets the value held by the node
	* @returns T - the value held by the node
	*/
	T getValue()
	{
		return value;
	}

	bool active = true; //used to denote an unused branch
	char key[MAX_KEY]; //used when searching for the node
	T value; //information held by the node
};



/*
* class KeyList
* template
*
* stores data in a binary search tree, this data can be accessed
* by keys assigned to it inside the tree, the binary search tree
* also offers significant performance improvements when searching
* for data without knowing if this data is already in the list
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class KeyList
{
public:

	/*
	* KeyList<T>()
	* template
	* default constructor
	*/
	KeyList<T>() {}

	/*
	* KeyList<T>()
	* template
	* default destructor
	*/
	~KeyList<T>() {}

	/*
	* insert
	* template
	*
	* inserts an element with the specified 
	* key and value into the tree
	*
	* @param char key[MAX_KEY] - the name of the new element, used to access the item
	* @param T value - the value of the new element
	* @returns void
	*/
	void insert(char key[MAX_KEY], T value) 
	{
		//the tree doesn't have a root, place the item here
		if (m_tree.getRoot() == nullptr || !m_tree.getRoot()->value.active)
		{
			//create the new root node
			TreeNode<KeyNode<T>>* newRoot = new TreeNode<KeyNode<T>>();

			//copy the key and the value
			strcpy_s(newRoot->value.key, key);
			newRoot->value.value = value;

			//delete the previous root
			delete m_tree.getRoot();

			//give the tree the new root
			m_tree.setRoot(newRoot);

			//create two in-active children nodes for use later
			TreeNode<KeyNode<T>>* inActiveNodeLeft = new TreeNode<KeyNode<T>>();
			TreeNode<KeyNode<T>>* inActiveNodeRight = new TreeNode<KeyNode<T>>();

			inActiveNodeLeft->value.active = false;
			inActiveNodeRight->value.active = false;

			m_tree.extend(m_tree.getRoot(), inActiveNodeLeft);
			m_tree.extend(m_tree.getRoot(), inActiveNodeRight);

		}
		else
		{
			//remember the current node and the node previously transversed to
			TreeNode<KeyNode<T>>* currentNode = m_tree.getRoot();

			//transverse down the tree until a leaf is reached
			while (currentNode->value.active)
			{
				int order = currentNode->value.checkAlpha(key);

				//check if the key comes before or after the current node's key alphabetically
				if (order == 1)
				{
					currentNode = currentNode->children[1]; //continue down the right branch
				}
				else //if the key comes before or belongs in the same position
				{
					currentNode = currentNode->children[0]; //continue down the left branch
				}
			}

			//leaf has been reached
			currentNode->value.active = true;

			//copy the key and the value
			strcpy_s(currentNode->value.key, key);
			currentNode->value.value = value;

			//create two in-active children nodes for use later
			TreeNode<KeyNode<T>>* inActiveNodeLeft = new TreeNode<KeyNode<T>>();
			TreeNode<KeyNode<T>>* inActiveNodeRight = new TreeNode<KeyNode<T>>();

			inActiveNodeLeft->value.active = false;
			inActiveNodeRight->value.active = false;

			m_tree.extend(currentNode, inActiveNodeLeft);
			m_tree.extend(currentNode, inActiveNodeRight);

		}
	
	}

	/*
	* remove
	* template
	*
	* removes the element that matches the specified key
	*
	* @param char key[MAX_KEY] - the name of the new element, used to access the item
	* @returns void
	*/
	void remove(char key[MAX_KEY]) 
	{
		TreeNode<KeyNode<T>>* toDelete = searchForNode(key);

		//exit early if the node couldn't be found
		if (toDelete == nullptr)
		{
			return;
		}

		//get the two children
		TreeNode<KeyNode<T>>* leftChild = toDelete->children[0];
		TreeNode<KeyNode<T>>* rightChild = toDelete->children[1];

		//get the parent
		TreeNode<KeyNode<T>>* parent = toDelete->parent;

		//remove the link of the two children from the node to be removed
		leftChild->parent = nullptr;
		rightChild->parent = nullptr;

		//remove the link to the two children from the node to be removed
		toDelete->children.clear();

		//create a new node that is in-active
		TreeNode<KeyNode<T>>* newNode = new TreeNode<KeyNode<T>>();
		newNode->value.active = false;
		newNode->parent = parent;
		newNode->children = toDelete->children;

			
		if (parent != nullptr) //the node isn't the root
		{
			//get the correct index (indicates if the node to be removed is the left or right child)
			int index = 0;

			if (parent->children[1] == toDelete)
			{
				index = 1;
			}

			//remove the node
			m_tree.prune(toDelete);

			//link the new node back into the parent as a child
			if (index == 0)
			{
				parent->children.pushFront(newNode);
			}
			else
			{
				parent->children.pushBack(newNode);
			}
		}
		else //the node is the root
		{
			//remove the root
			delete m_tree.getRoot();

			//set the new root
			m_tree.setRoot(newNode);
		}
		

		if (leftChild->value.active && rightChild->value.active) //both nodes are active
		{
			insertNode(leftChild);
			insertNode(rightChild);
		}
		else if (leftChild->value.active && !rightChild->value.active) //only the left node is active
		{
			insertNode(leftChild);
			delete rightChild;
		}
		else if (!leftChild->value.active && rightChild->value.active) //only the right node is active
		{
			insertNode(rightChild);
			delete leftChild;
		}
		else //both nodes are inactive
		{
			delete leftChild;
			delete rightChild;
		}

	}

	/*
	* searchFor
	* template
	*
	* gets the value associated with the specified key from the key list
	* returns nullptr if the value doesn't exist
	*
	* @param char key[MAX_KEY] - the name of the new element, used to access the item
	* @returns T* - pointer to the data associated with the key, nullptr if the item doesn't exist
	*/
	T* searchFor(char key[MAX_KEY]) 
	{
		//remember the current node and the node previously transversed to
		TreeNode<KeyNode<T>>* currentNode = m_tree.getRoot();
		TreeNode<KeyNode<T>>* prevNode = m_tree.getRoot();

		//test if there is nothing in the container
		if (currentNode == nullptr)
		{
			return nullptr;
		}

		//transverse down the tree until a leaf is reached
		while (currentNode->value.checkAlpha(key) != 0 && currentNode->value.active)
		{
			int order = currentNode->value.checkAlpha(key);

			//check if the key comes before or after the current node's key alphabetically
			if (order == 1)
			{
				currentNode = currentNode->children[1]; //continue down the right branch
			}
			else //if the key comes before or belongs in the same position
			{
				currentNode = currentNode->children[0]; //continue down the left branch
			}
		}

		//an active node terminated the loop, meaning that it is the node that was searched for
		if (currentNode->value.active)
		{
			return &currentNode->value.value;
		}
		else
		{
			return nullptr;
		}
	}

private:
	LinkedTree<KeyNode<T>> m_tree = LinkedTree<KeyNode<T>>(); //binary search tree of key nodes

	/*
	* searchForNode
	* template
	*
	* gets the tree node associated with the specified key from the key list
	* returns nullptr if the value doesn't exist
	*
	* @param char key[MAX_KEY] - the name of the new element, used to access the item
	* @returns TreeNode<KeyNode<T>>* - pointer to the TreeNode associated with the key, nullptr if the item doesn't exist
	*/
	TreeNode<KeyNode<T>>* searchForNode(char key[MAX_KEY])
	{
		//remember the current node and the node previously transversed to
		TreeNode<KeyNode<T>>* currentNode = m_tree.getRoot();

		//transverse down the tree until a leaf is reached
		while (currentNode->value.checkAlpha(key) != 0 && currentNode->value.active)
		{
			int order = currentNode->value.checkAlpha(key);

			//check if the key comes before or after the current node's key alphabetically
			if (order == 1)
			{
				currentNode = currentNode->children[1]; //continue down the right branch
			}
			else //if the key comes before or belongs in the same position
			{
				currentNode = currentNode->children[0]; //continue down the left branch
			}
		}

		//an active node terminated the loop, meaning that it is the node that was searched for
		if (currentNode->value.active)
		{
			return currentNode;
		}
		else
		{
			return nullptr;
		}
	}

	/*
	* insertNode
	* template
	*
	* inserts an existing element into the tree
	*
	* @param TreeNode<KeyNode<T>>* node - node to add to the tree
	* @returns void
	*/
	void insertNode(TreeNode<KeyNode<T>>* node)
	{
		//the tree doesn't have a root, place the item here

		if (m_tree.getRoot() == nullptr)
		{
			//give the tree the new root
			m_tree.setRoot(node);

			TreeNode<KeyNode<T>>* inActiveNodeLeft = new TreeNode<KeyNode<T>>();
			TreeNode<KeyNode<T>>* inActiveNodeRight = new TreeNode<KeyNode<T>>();

			inActiveNodeLeft->value.active = false;
			inActiveNodeRight->value.active = false;

			m_tree.extend(node, inActiveNodeLeft);
			m_tree.extend(node, inActiveNodeRight);
		}
		else
		{
			//remember the current node and the node previously transversed to
			TreeNode<KeyNode<T>>* currentNode = m_tree.getRoot();
			TreeNode<KeyNode<T>>* prevNode = nullptr;

			//transverse down the tree until a leaf is reached
			while (currentNode->value.active)
			{
				prevNode = currentNode;

				int order = currentNode->value.checkAlpha(node->value.key);

				//check if the key comes before or after the current node's key alphabetically
				if (order == 1)
				{
					currentNode = currentNode->children[1]; //continue down the right branch
				}
				else //if the key comes before or belongs in the same position
				{
					currentNode = currentNode->children[0]; //continue down the left branch
				}
			}

			currentNode->value = node->value;
			currentNode->parent = prevNode;
			
			delete node;

			TreeNode<KeyNode<T>>* inActiveNodeLeft = new TreeNode<KeyNode<T>>();
			TreeNode<KeyNode<T>>* inActiveNodeRight = new TreeNode<KeyNode<T>>();

			inActiveNodeLeft->value.active = false;
			inActiveNodeRight->value.active = false;

			m_tree.extend(currentNode, inActiveNodeLeft);
			m_tree.extend(currentNode, inActiveNodeRight);

		}

	}
};