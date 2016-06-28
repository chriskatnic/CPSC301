#ifndef NODE_H
#define NODE_H

//write all the prototypes
//two constructors, one for int, one for just a blank one
//all the info is public so you can add/subtract/edit whatever in main.cpp
class Node{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int);
	Node();
};

#endif