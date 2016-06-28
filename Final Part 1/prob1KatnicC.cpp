//Christopher Katnic
//894-68-7516
//Problem 1

#include <iostream>


class TreeNodeType{
public:
	TreeNodeType ( int = 0 );

	int info;
	TreeNodeType * leftPtr;
	TreeNodeType * rightPtr;

};

TreeNodeType::TreeNodeType ( int data )
{
	info = data;
	leftPtr = NULL;
	rightPtr = NULL;
}


TreeNodeType * createTree ( int, TreeNodeType* , TreeNodeType* );

int main ()
{
	//create two "branches"
	TreeNodeType *left = createTree ( 31, NULL, NULL );
	TreeNodeType *right1 = createTree ( 4, NULL, NULL );
	TreeNodeType *right = createTree ( 2, right1,  NULL ); 

	//combine two "branches" to create one tree
	TreeNodeType * root = createTree ( 12, left, right );


	//print out tree
	std::cout << "Root -> info = " << root -> info;
	std::cout << "\n\nRoot -> left = " << root ->leftPtr -> info;
	std::cout << " \n\nRoot -> right = " << root -> rightPtr -> info;
	std::cout << "\n\nRoot -> right -> left = " << root -> rightPtr -> leftPtr -> info << "\n\n";


	//deallocate memory
	delete left, right1, right, root;
	return 0;
}




TreeNodeType * createTree ( int value, TreeNodeType * branchL, TreeNodeType * branchR )
{

	TreeNodeType * root  = new TreeNodeType;
	root -> leftPtr = branchL;
	root -> rightPtr = branchR;
	root -> info = value;

	return root;

}





