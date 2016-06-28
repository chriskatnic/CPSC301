#include "Node.h"
#include <iostream>

//just define the functions from the .h file, there's not much
Node::Node(int x)
{
	data = x;
	left = NULL;
	right = NULL;
}

Node::Node()
{
	left = NULL;
	right = NULL;
}
