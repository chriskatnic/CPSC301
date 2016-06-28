#include "List.h"

template <class ItemType>
List<ItemType>::List()
{
	head = NULL;
	previous = NULL;
	current = NULL;
	position = 1;
}
 
template <class ItemType>
void List<ItemType>::makeEmpty()
{
	NodeType* temp = head;
	while ( head != NULL )
	{
		head = head -> nextPTR;
		delete temp;
		temp = head;
	}
	previous = NULL;
	current = NULL;
	position = 1;
}

template <class ItemType>
bool List<ItemType>::isEmpty()
{
	if ( head == NULL )
		return true;
	else 
		return false;
}

template <class ItemType>
void List<ItemType>::goToStart()
{
	current = head;
	previous = NULL;
	position = 1;
}

template <class ItemType>
void List<ItemType>::goToNext()
{
	//statement 1, if there is more than one node
	if ( current != NULL ) 
	{
		previous = current;
		current = current -> nextPTR;
		position++;
	}
	else if ( current == NULL )
	{
		std::cout << "\nThere are no nodes in the list!\n";
	}
}

template <class ItemType>
bool List<ItemType> ::isAtEnd()
{
	if ( current == NULL ) 
		return true;
	else 
		return false;
}

template <class ItemType>
ItemType List<ItemType> ::CurrentItem()
{
	if ( !isAtEnd() )
		return current->value;
	else
		std::cout << "Currently at the end of the list!";
		return 0;
}

template <class ItemType>
void List<ItemType>::insert( ItemType newItem )
{
	//case 1, position = 1
	//case 2, position != 1

	NodeType  *temp = new NodeType;
	temp -> value = newItem;
	temp -> nextPTR = NULL;

	if( position == 1 )
	{
		temp -> nextPTR = head;
		head = temp;
		current = temp;
	}
	else
	{
		previous ->nextPTR = temp;
		temp ->nextPTR = current;
		current = temp;
	}


		
}

template <class ItemType>
void List<ItemType> ::deleteCurrentItem()
{
	//delete from beginning, delete from middle.

	if( current == head )
	{
		head = current -> nextPTR;
		delete current;
		current = head;
	}
	else 
	{
		previous -> nextPTR = current -> nextPTR;
		delete current;
		current = previous -> nextPTR;

	}

}

 template <class ItemType>
int List<ItemType> ::currentPosition()
{
	return position;
}

 template <class ItemType>
List<ItemType>::~List()
{
	List::makeEmpty();
}