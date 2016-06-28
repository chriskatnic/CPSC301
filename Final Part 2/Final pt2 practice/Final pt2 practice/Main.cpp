//Christopher Katnic
//894-68-7516
//EPP practice for pt 2

/**********************************************************
Concepts covered:
	Creating classes/objects using multiple files
	Binary search tree
	printing out a BST in some sort of order
**********************************************************/
#include <iostream>
#include "Node.h"

//two functions to create trees. one from the EPP pt1, which is a sloppy way of doing it
//and the other for a binary search tree, where all of the shit is sorted accordingly
Node * createTree (int, Node*, Node* );
void insert ( int, Node*&);

//print function for looking through the tree to the right
//I forget what that is called, but if you change the positions of the three
//lines of code within the function, it prints out differently due to the order
//that the function recurses back in.
void print ( Node* );

int main()
{

	Node * leaf1 = new Node;
	Node * leaf2 = new Node;
	Node * leaf3 = new Node;

	leaf1 = createTree ( 1, NULL, NULL );
	leaf2 = createTree ( 3, NULL, NULL );
	leaf3 = createTree ( 2, leaf1, leaf2 );

	//tree should be 2 at root, 1 at left, 3 at right
	print ( leaf3 );


	//new tree with root 10, using insert, all other values should be sorted accordingly.
	Node * root = new Node ( 10 );

	//left of 10
	insert ( 5, root );

	//right of 10
	insert ( 11, root );

	//right of 10, right of 11
	insert ( 20, root );

	//left of 10, right of 5
	insert ( 6, root );
	

	print ( root );



	delete leaf1, leaf2, leaf3, root;
	return 0;
}




//create tree from the previous assignment on the EPP
Node * createTree ( int x, Node* left1, Node* right1 )
{

	Node * temp = new Node;
	temp -> data = x;
	temp -> right = right1;
	temp -> left = left1;

	return temp;
}

//prints the nodes from right to left. postorder traversal??? just switch the order of print, std::cout, print around and play
//with it to get a different order
void print ( Node * root )
{
	if ( root != NULL ) 
	{
		print ( root -> right );
		std::cout << root ->data << " ";
		print ( root -> left );
		
	
	}

}

//insert into a binary search tree, looks through the tree until it gets to the proper position
//will be null, then creates a new node, and throws it in order
void insert( int x, Node *& root )
{
	if ( root != NULL )
	{
		if ( x < root -> data ) 
		{
			insert ( x, root -> left );
		}
		else
		{
			insert ( x, root -> right );
		}
	}
	else
	{
		Node * temp = new Node;
		temp -> data = x;
		temp -> left=  NULL;
		temp -> right = NULL;

		root = temp;
	}
}
