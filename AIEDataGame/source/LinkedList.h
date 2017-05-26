#pragma once

//conveinient macro for template declarations
#define TEMPLATE template<typename T>

/*
* class LinkedNode
* template
*
* an item that belongs to a LinkedList, holds a value and a link
* to the item in the list before it and after it (if either exists)
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class LinkedNode
{
public:

	/*
	* LinkedNode()
	* default constructor
	*/
	LinkedNode<T>() {}

	/*
	* ~LinkedNode()
	* default destructor
	*/
	~LinkedNode<T>() {}

	T value; 

	LinkedNode<T>* next = nullptr; //the node positioned after this
	LinkedNode<T>* prev = nullptr; //the node positioned before this
};



/*
* class LinkedList
* template
*
* manages a resizable collection of interlinked nodes
* boasts fast insertion and deletion, but poor random access speeds
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class LinkedList
{
public:

	/*
	* class Iterator
	* template
	*
	* a helper object for iterating through the nodes of a LinkedList
	*
	* author: Bradley Booth, Academy of Interactive Entertainment, 2017
	*/
	class Iterator
	{
	public:

		/*
		* Iterator()
		* default constructor
		*/
		Iterator() {};

		/*
		* Iterator()
		* template
		* constructor, assigns the node immediately
		*
		* @param LinkedNode<T>* node - pointer to the node that the iterator is on
		*/
		Iterator(LinkedNode<T>* node) : m_node(node) {};

		/*
		* ~Iterator()
		* default destructor
		*/
		~Iterator() {};

		/*
		* operator++
		*
		* iterates through to the next node
		*
		* @param int - amount to add
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator++(int) 
		{
			//don't attempt to go to the next node when there isn't one
			if (m_node != nullptr)
			{
				m_node = m_node->next;
			}

			return *this;
		}

		/*
		* operator+
		*
		* iterates through the specified amount of nodes
		*
		* @param int num - the amount of loops
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator +(int num)
		{
			for (int i = 0; i < num; i++)
			{
				//if the node is null, stop pointlessly iterating
				if (m_node == nullptr)
				{
					break;
				}
				else
				{
					m_node = m_node->next;
				}
			}

			return *this;
		}

		/*
		* operator+=
		*
		* iterates through the specified amount of nodes
		*
		* @param int num - the amount of loops
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator +=(int num) 
		{
			for (int i = 0; i < num; i++)
			{
				//if the node is null, stop pointlessly iterating
				if (m_node == nullptr)
				{
					break;
				}
				else
				{
					m_node = m_node->next;
				}
			}

			return *this;
		}

		/*
		* operator--
		*
		* iterates back to the previous node
		*
		* @param int - amount to subtract
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator --(int)
		{
			//don't attempt to go to the previous node when there isn't one
			if (m_node != nullptr)
			{
				m_node = m_node->prev;
			}

			return *this;
		}

		/*
		* operator-
		*
		* iterates back the specified amount of nodes
		*
		* @param int num - the amount of loops
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator -(int num)
		{
			for (int i = 0; i < num; i++)
			{
				//if the node is null, stop pointlessly iterating
				if (m_node == nullptr)
				{
					break;
				}
				else
				{
					m_node = m_node->prev;
				}
			}

			return *this;
		}

		/*
		* operator-
		*
		* iterates back the specified amount of nodes
		*
		* @param int num - the amount of loops
		* @returns Iterator& - the new iterator
		*/
		Iterator& operator -=(int num)
		{
			for (int i = 0; i < num; i++)
			{
				//if the node is null, stop pointlessly iterating
				if (m_node == nullptr)
				{
					break;
				}
				else
				{
					m_node = m_node->prev;
				}
			}

			return *this;
		}
		

		///*
		//* operator*
		//* template
		//*
		//* returns the value held by the iterator's node
		//*
		//* @returns T& - reference to the value
		//*/
		//T& operator *() 
		//{
		//	return m_node->value;
		//}
		//
		///*
		//* operator->
		//* template
		//*
		//* returns a pointer to the value held by the iterator's node
		//*
		//* @returns T* - pointer to the value
		//*/
		//T* operator ->()
		//{
		//	return &m_node->value;
		//}
		

		/*
		* operator==
		*
		* compares two iterators to see if they are equal
		*
		* @param const Iterator& rhs - the other Iterator in the comparison
		* @returns bool - true if the iterators are the same
		*/
		bool operator ==(const Iterator& rhs) 
		{
			return m_node == rhs.m_node;
		}

		/*
		* operator!=
		*
		* compares two iterators to see if they aren't the same
		*
		* @param const Iterator& rhs - the other Iterator in the comparison
		* @returns bool - false if the are the same
		*/
		bool operator !=(const Iterator& rhs) 
		{
			return m_node != rhs.m_node;
		}

		LinkedNode<T>* m_node = nullptr;
	};

	/*
	* LinkedList<T>()
	* template
	* default constructor
	*/
	LinkedList<T>() {};

	/*
	* LinkedList<T>()
	* template
	* constructor, creates the specified amount of uninitialised nodes to be used
	*
	* @param size_t _size - the amount of nodes in the LinkedList to add initially
	*/
	LinkedList<T>(size_t _size) 
	{
		size = _size;

		LinkedNode<T>* prevPtr = nullptr;

		for (size_t i = 0; i < size; i++)
		{
			//create a new node
			LinkedNode<T>* nodePtr = new LinkedNode<T>();

			//assign m_first or m_last
			if (i == 0)
			{
				m_first = nodePtr;
			}
			else if (i == size - 1)
			{
				m_last = nodePtr;
			}

			//assign the previous node of the newly created node
			nodePtr->prev = prevPtr;

			//assign the next node of the previously created node if it exists
			if (prevPtr != nullptr)
			{
				prevPtr->next = nodePtr;
			}

			//set the previous node for the pass of the loop
			prevPtr = nodePtr;
		}
	}

	/*
	* LinkedList<T>(const LinkedList<T> & other)
	* template
	* copy constructor
	*
	* @param const LinkedList<T> & other - reference to the LinkedList to copy from
	*/
	LinkedList<T>(const LinkedList<T> & other) 
	{
		LinkedNode<T>* nodePtr = other.m_first;

		//make new nodes with the same values
		for (size_t i = 0; i < other.size; i++)
		{
			pushBack(nodePtr->value);
			nodePtr = nodePtr->next;
		}
	}

	/*
	* operator=
	* template
	* 
	* copies the contents of one LinkedList to another
	*
	* @param const LinkedList & other - the LinkedList to copy from
	* @returns LinkedList<T> & - reference to the new LinkedList
	*/
	LinkedList<T> & operator=(const LinkedList<T> & other)
	{
		clear();

		LinkedNode<T>* nodePtr = other.m_first;

		//make new nodes with the same values
		for (size_t i = 0; i < other.size; i++)
		{
			pushBack(nodePtr->value);
			nodePtr = nodePtr->next;
		}

		return *this;
	}

	/*
	* ~LinkedList<T>()
	* template
	* destructor, deletes all of the nodes
	*/
	~LinkedList<T>() 
	{
		LinkedNode<T>* nodePtr = m_first;

		//temp value used to remember the previously deleted pointer to the next node
		LinkedNode<T>* nextPtr = nullptr;

		//iterate through all nodes
		for (size_t i = 0; i < size; i++)
		{
			//set the next node
			nextPtr = nodePtr->next;

			//delete it and set up the next node for deletion
			delete nodePtr;
			nodePtr = nextPtr;
		}
	}

	/*
	* pushList
	* template
	*
	* adds the contents of one LinkedList to another
	*
	* @param const LinkedList & other - the LinkedList to copy from
	* @returns LinkedList<T> & - reference to the new LinkedList
	*/
	LinkedList<T> & pushList(const LinkedList<T> & other)
	{
		LinkedNode<T>* nodePtr = other.m_first;

		//make new nodes with the same values
		for (size_t i = 0; i < other.size; i++)
		{
			pushBack(nodePtr->value);
			nodePtr = nodePtr->next;
		}

		return *this;
	}

	/*
	* begin
	*
	* gets the first node in the collection
	* and constructs an Iterator out of it
	*
	* @returns Iterator - an iterator that can iterate through the entire collection
	*/
	Iterator begin()
	{
		return Iterator(m_first);
	}

	/*
	* end
	*
	* gets an iterator at the end of a collection
	* the end of a collection is always a nullptr
	*
	* @returns Iterator - an iterator that represents the end of a collection
	*/
	Iterator end()
	{
		return Iterator(nullptr);
	}

	/*
	* clear
	* template
	*
	* erases all elements in the collection
	*
	* @returns void
	*/
	void clear()
	{
		LinkedNode<T>* nodePtr = m_first;

		//temp value used to remember the previously deleted pointer to the next node
		LinkedNode<T>* nextPtr = nullptr;

		//iterate through all nodes
		for (size_t i = 0; i < size; i++)
		{
			//set the next node
			nextPtr = nodePtr->next;

			//delete it and set up the next node for deletion
			delete nodePtr;
			nodePtr = nextPtr;
		}

		size = 0;
	}

	/*
	* isEmpty
	*
	* checks if a list has any elements in it
	* 
	* @return bool - indicates if the list is empty or not
	*/
	bool isEmpty()
	{
		return size == 0;
	}

	/*
	* operator []
	* template
	*
	* accesses the linked list using array notation
	*
	* @param const int index - the item number to get
	* @return T& - reference to the value at the node
	*/
	T& operator[] (const int index)
	{
		LinkedNode<T>* node = m_first;

		//iterate through all of the nodes
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		return node->value;
	}

	/*
	* pushFront
	* template
	*
	* adds a new element with a specified value to the front of the list
	*
	* @param T value - the value to give the new element
	* @returns void
	*/
	void pushFront(T value)
	{
		if (size == 0) //set up the collection element for linking with others later
		{
			m_first = new LinkedNode<T>();
			m_last = m_first;

			m_first->value = value;
		}
		else //link the elements already in the collection
		{
			LinkedNode<T>* second = m_first; //remember the previous first node

			m_first = new LinkedNode<T>(); //give the first pointer the new node
			m_first->value = value;

			//link the new first and second nodes
			m_first->next = second;

			if (second != nullptr)
			{
				second->prev = m_first;
			}
		}

		size++;
	}

	/*
	* pushBack
	* template
	*
	* adds a new element with a specified value to the back of the list
	*
	* @param T value - the value to give the new element
	* @returns void
	*/
	void pushBack(T value)
	{
		if (size == 0) //set up the collection element for linking with others later
		{
			m_last = new LinkedNode<T>();
			m_first = m_last;

			m_last->value = value;
		}
		else
		{

			LinkedNode<T>* secondLast = m_last; //remember the previous last node

			m_last = new LinkedNode<T>(); //give the first pointer the new node
			m_last->value = value;

			//link the new last and second-last nodes	
			m_last->prev = secondLast;

			if (secondLast != nullptr)
			{
				secondLast->next = m_last;
			}
		}

		size++;
	}

	/*
	* insert
	* template
	*
	* inserts a new element with a specified value
	* into the collection after another specified node
	*
	* @param LinkedNode<T>* afterPtr - pointer to the node that the new node will be placed before
	* @param T value - the value of the new element
	* @returns void
	*/
	void insert(LinkedNode<T>* afterPtr, T value)
	{
		LinkedNode<T>* newNode = new LinkedNode<T>();
		newNode->value = value;

		//set the next link of the previous node
		if (afterPtr->prev != nullptr)
		{
			afterPtr->prev->next = newNode;
		}

		//set the links of the new node 
		newNode->prev = afterPtr->prev;
		newNode->next = afterPtr;

		//set the previous link of the next node to the new node
		afterPtr->prev = newNode;

		//reset the first node holder if it changed
		if (m_first == afterPtr)
		{
			m_first = newNode;
		}

		size++;
	}

	/*
	* popFront
	* template
	*
	* removes the first element in the collection
	* does nothing if the collection is empty
	*
	* @returns void
	*/
	void popFront()
	{
		//return if the list is empty
		if (isEmpty())
		{
			return;
		}

		LinkedNode<T>* second = m_first->next; //remember the second node

		//remove the first element
		delete m_first;

		//is there another element after the removed element
		if (second != nullptr)
		{
			//reassign the first element to the second
			m_first = second;

			//the node before it was just remoed
			m_first->prev = nullptr;
		}
		else
		{
			m_first = nullptr;
			m_last = nullptr;
		}

		size--;
	}

	/*
	* popBack
	* template
	*
	* removes the first element in the collection
	* does nothing if the collection is empty
	*
	* @returns void
	*/
	void popBack()
	{
		//return if the list is empty
		if (isEmpty())
		{
			return;
		}

		LinkedNode<T>* secondLast = m_last->prev; //remember the second last node

		//remove the last element
		delete m_last;

		//is there another element before the removed element
		if (secondLast != nullptr)
		{
			//reassign the last element to the second last
			m_last = secondLast;

			//the node after it was just removed
			m_last->next = nullptr;
		}
		else
		{
			m_first = nullptr;
			m_last = nullptr;
		}

		size--;
	}

	/*
	* erase
	* template
	*
	* removes the specified element from the list
	*
	* @param LinkedNode<T>* afterPtr - pointer to the node that will be remove
	* @returns void
	*/
	void erase(LinkedNode<T>* afterPtr)
	{
		//link the previous and next node directly, skipping this node
		if (afterPtr->prev != nullptr)
		{
			afterPtr->prev->next = afterPtr->next;
		}

		if (afterPtr->next != nullptr)
		{
			afterPtr->next->prev = afterPtr->prev;
		}

		//replace the first node if it is the node being erased
		if (m_first == afterPtr)
		{
			m_first = afterPtr->next;
		}

		//replace the first node if it is the node being erased
		if (m_last == afterPtr)
		{
			m_last = afterPtr->prev;
		}

		delete afterPtr;

		size--;
	}

	size_t size = 0; //tracks the size of the collection

private:

	//allow linked node and iterator to access the private variables
	friend LinkedNode<T>;
	friend Iterator;
	
	LinkedNode<T>* m_first = nullptr; //first node in the collection
	LinkedNode<T>* m_last = nullptr; //last node in the collection

};