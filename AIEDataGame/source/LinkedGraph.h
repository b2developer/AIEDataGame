#pragma once
#include "LinkedList.h"

/*
* class GraphNode
* template
*
* an item that belongs to a LinkedGraph, holds a value and
* two containers representing incoming and outgoing connections
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class GraphNode
{
public:

	/*
	* GraphNode()
	* default constructor
	*/
	GraphNode<T>() {}

	/*
	* ~GraphNode()
	* default destructor
	*/
	~GraphNode<T>() {}

	T value;

	LinkedList<GraphNode<T>*> incoming = LinkedList<GraphNode<T>*>(0); //all nodes that have connections towards the node
	LinkedList<GraphNode<T>*> outcoming = LinkedList<GraphNode<T>*>(0); //all nodes that have connections away from the node
};



/*
* class LinkedGraph
* template
*
* manages a collection of interconnected nodes that
* can contain an infinite amount of connections going out or in
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class LinkedGraph
{
public:
};