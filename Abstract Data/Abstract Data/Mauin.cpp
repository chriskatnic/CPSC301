//Christopher Katnic
//894-68-7516
//Working with Abstract Data
#include <string>
#include <iostream>
#include "List.h"
#include "studentRecord.h"


template <class ItemType>
void printList(List<ItemType>&);


int main()
{

	
	std::cout << "\nA: Add a student\n"
			 << "R: Retrieve a student record\n"
			 << "D: Delete a student record\n"
		  	 << "M: Modify a student record\n"
			 << "Q: Quit the program and save\n"
			 << "P: Print out all student information\n";

	List<studentRecord> List1;
	char choice;
	bool stop = false;


while(!stop)
{
	std::cout << "\nEnter choice: ";
	std::cin >> choice;

	switch ( choice )
	{
		case 'A':
		case 'a':
			{
				std::cout << "\nEnter in the new student's ID, first name, last name, and GPA\n\n";
				studentRecord newGuy;
				std::cin >> newGuy;

				List1.insert(newGuy);

				break;
			}
		
		case 'r':
		case 'R':
			{
				int ID;
				std::cout << "\nEnter in the ID of the student to be retrieved: ";
				std::cin >> ID;

				retrieveData(List1, ID);
				break;
			}
		case 'D':
		case 'd':
			{
				List1.goToNext();
				break;
			}
		case 'E':
		case 'e':
			{
				if ( !List1.isAtEnd() )
					std::cout << "not at end\n";
				else
					std::cout << "current is at end\n";
				break;
			}
		case 'F':
		case 'f':
			{
				std::cout << List1.CurrentItem();
					break;
			}
		case 'G':
		case 'g':
			{
				std::cout << "\nEnter in a value: ";
				studentRecord thing;
				std::cin >> thing;

				List1.insert( thing );
				break;
			}
		case 'H':
		case 'h':
			{
				List1.deleteCurrentItem();
				break;
			}
		case 'I':
		case 'i':
			{
				std::cout << List1.currentPosition();
				break;
			}
		case 'J':
		case 'j':
			{
				printList(List1);
				break;
			}
		default:
			{
				stop = true;
			}
		}
}

	return 0;
}

template <class ItemType>
void printList(List<ItemType> &list1)
{
	list1.goToStart();

	while( !list1.isAtEnd() )
	{
		std::cout << list1.CurrentItem() << " -> ";
		list1.goToNext();
	}
	std::cout << "NULL\n";
	list1.goToStart();

}

