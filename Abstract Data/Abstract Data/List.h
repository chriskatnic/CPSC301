#include <iostream>




template <class ItemType>
struct NodeType
{
	ItemType value;
	NodeType<ItemType> *nextPTR;
};

template <class ItemType>
class List
{
public:
	
	List();
	// Initialization
	// Pre: None
	// Post: List is an empty linked list. First position is 1


	void makeEmpty();
	// Makes the list empty if it is not empty already
	// Pre: List may or may not be empty
	// Post: List is now an empty linked list. Any dynamically allocated memory which is no longer used is returned to the system. The current position is 1

	bool isEmpty();
	// Checks to see if the list is empty
	// Pre: a list is given, may or may not be empty
	// Post: The list remains unchanged

	void goToStart();
	// Moves the current position to the start of the list
	// Post: Current position is set to 1

	void goToNext();
	// If the current position is not at the end of the list, moves the current position to next position.
	// Post: Position has been moved to the next position, unless position was already at the end of the list. If the position was already at the end of the list,
	// The position remains unchanged. If the list is empty, nothing has changed.

	bool isAtEnd();
	// Checks to see if the current pointer is at the end of the list.
	// Post: Position remains unchanged; list remains unchanged.

	ItemType CurrentItem();
	// Returns the value of the current item in the linked list. Assumes that the current item exists; i.e. the current position is not at the end of the list.
	// Pre: The list is not empty, and the current position is not at the end of the list
	// Post: List and current position remains unchanged


	void insert( ItemType );
	// Inserts the given newItem in the linked list before the item at the current position.
	// After the insertion, the current potiion remains unchanged, but the newly inserted item is there. If there was
	// an item at the current position before the insertion, that item would now be at the current position +1
	// Pre: The list may or may not be empty
	// Post: The newItem is inserted in the linked list before any item that was at the current position. The current position is unchanged and the newly inseted item will not be at that position

	void deleteCurrentItem();
	// Deletes the item in the linked list at the current position. Assumes that the current item exists
	// Preconditions: List is not empty and the current position is not at the end of the list
	// Post: The item at the current position has been deleted. The current position remains unchanged with respect to the list
	// If the item had been the last item, the current position would be at the end of the list.

	int currentPosition();
	// Returns the number of the current position. If there is an item at the current position, it will return the relative position of the item in the list
	// If the position is at the end of the list, it will return 1 + n where n is the num of items in the list
	// Post: List and current position remains unchanged
	

	~List();

private:
	NodeType<ItemType> *head;
	NodeType<ItemType> *previous;
	NodeType<ItemType> *current;
	int position;



};


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
	NodeType<ItemType>* temp = head;
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
bool List<ItemType>::isAtEnd()
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

}

template <class ItemType>
void List<ItemType>::insert( ItemType newItem )
{
	//case 1, position = 1
	//case 2, position != 1

	NodeType<ItemType> *temp = new NodeType<ItemType>;
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
int List<ItemType>::currentPosition()
{
	return position;
}

template <class ItemType>
List<ItemType>::~List()
{
	List::makeEmpty();
}