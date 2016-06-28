//Christopher Katnic
//894-68-7516
//Problem 2

#include <iostream>
#include <climits>

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


int min ( TreeNodeType* );



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



	//return lowest value in tree
	std::cout << "Lowest value in tree = " << min( root ) << "\n\n";


	//deallocate memory
	delete left, right1, right, root;

	//exit
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


int min ( TreeNodeType * root ) 
{
	//if there was an empty list, or the function has reached the end, return some arbitrarily high number
	if ( root == NULL )
	{
		return  INT_MAX;
	}

	//if there exists a tree that is not empty, run function
	else if ( root != NULL )
	{
		//declare variables for comparing
		int rootValue = root -> info;
		int minValue, left, right;

		//recurse through the entire tree
		left = min ( root -> leftPtr );
		right = min ( root -> rightPtr );


		//compare the three variables
		if ( right < left )
		{
			minValue = right;
		}
		else
		{
			minValue = left;
		}
		if ( minValue > rootValue )
		{
			minValue = rootValue;
		}
		

		//return lowest value found
		return minValue;
	}	

}


