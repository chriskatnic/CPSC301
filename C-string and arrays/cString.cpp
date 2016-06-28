// Chris Katnic
// 09.30.13
// C-strings and arrays

#include <cstring>
#include <iostream>

using namespace std;

int welcome();
// welcome(): Prints out a welcome page and returns the number of books that the user wants to enter

void readInfo(int, char[][70], char[][70]);
// readInfo(): Takes in the information that the user types in into arrays

char getSelection();
// getSelection(): Gets the user's choice of how to sort the books

void sort(char, char [][70], char [][70], int);
// sort(): Using the user's choice, choose sorting method 

void selectionSort(int, char[][70]);
// selectionSort(): Using selection sort, change the order of the books in the array, as per the user's chosen method

void swap(char[70], char[70]);
// swap(): Utilized within function selectionSort(), swaps the positions of two cstrings in an array

void display(int, char[][70]);
// display(): Prints out the now ordered list, to the specifications of the user

int main()
{
	char nameTitle[20][70], titleName[20][70];  // 20 for the amount of books, 60 characters;
	char sentinel = 'c';						
	
	int numBooks = welcome();					// Get the number of books
	readInfo(numBooks, nameTitle, titleName);   // Read in book info
	
	while(sentinel != 'q' && sentinel != 'Q')   // While loop to sort until the user says to quit 'q'
	{
		sentinel = getSelection();						 // Check to see how the user would like to sort
		sort(sentinel, nameTitle, titleName, numBooks);	 // Sort function starts all other functions within it
	}
	

	return 0;
}







int welcome()
{
	cout << "Welcome to the CS Library program \nPlease enter the number of books:\t";
	int x; cin >> x;
	return x;
}

void readInfo(int numBooks, char nameTitle[][70], char titleName[][70])
{
	char lname[15], fname[15], title[30], temp[70]; // C-Strings to hold names, title, and one temporary to hold all
	cout << "Enter the first name, last name, and book title:\n";
	
	for(int i=0;i<numBooks;i++)		// While the user has not typed in [number of books] titles, first names, and last names
	{                               // Continue to read in titles, and concatenate them to one large temporary c-string
		cin >> fname >> lname;		
		cin.ignore(1);   //ignore whitespace between comma and title
		cin.getline(title, 999, '\n');

		strcpy_s(temp, lname);
		strcat_s(temp, ", ");
		strcat_s(temp, fname);
		strcat_s(temp, ", ");
		strcat_s(temp, title);

		strcpy_s(nameTitle[i], temp); // Take temporary c-string and copy to the appropriate array
									  // Then, overwrite the temporary string to create a new order
		strcpy_s(temp,title);
		strcat_s(temp, ", ");
		strcat_s(temp, lname);
		strcat_s(temp, ", ");
		strcat_s(temp, fname);

		strcpy_s(titleName[i], temp); // Take temporary c-string and copy to the appropriate array
		cout << endl;
	}
}


char getSelection()
{
	cout << "The program will display all books sorted according to your choice.\n" 
		 <<	"Please enter your one letter choice as follows:\n"
		 << "A:  sort the books by the last names of the authors\n"
		 << "T:  sort the books by the titles\n"
		 << "Q:  quit this program\n" << endl;
	char x;
	cin >> x;
	return x;
}

void sort(char sentinel, char nameTitle[][70], char titleName[][70], int numBooks)
{
	switch(sentinel)			// Switch statement depending on the character inputted by the user
	{
		case 'a':
		case 'A':
			{
				selectionSort(numBooks, nameTitle);	// Sort by last name first if choice is 'a' or 'A'
				display(numBooks, nameTitle);		// Display newly sorted array
				cout << endl;
				break;
			}
		case 't':
		case 'T':
			{
				selectionSort(numBooks, titleName);	// Sort by title first if choice is 't' or 'T'
				display(numBooks, titleName);		// Display newly sorted array
				cout << endl;
				break;
			}
		case 'q':
		case 'Q':
			{
				break;
			}
	}
}

void selectionSort(int numBooks, char x[][70])
{
	int i, j, lowIndex;
	char lowCString[70];

	for(i=0; i<numBooks; i++)
	{
		lowIndex = i;
		strcpy_s(lowCString, 70, x[i]);

		for(j=i+1; j<numBooks; j++)
		{
			if(strcmp(lowCString, x[j]) > 0)
			{
				strcpy_s(lowCString, x[j]);
				lowIndex = j;
			}
		}
		swap(x[i], x[lowIndex]);
	}
}

void swap(char cstring1[70], char cstring2[70])
{
	char temp[70];
	strcpy_s(temp, cstring1);
	strcpy_s(cstring1, 70, cstring2);
	strcpy_s(cstring2, 70, temp);
}

void display(int numBooks, char x[][70])
{
	for(int i=0; i<numBooks; i++)
	{
		cout << x[i] << endl;
	}
}