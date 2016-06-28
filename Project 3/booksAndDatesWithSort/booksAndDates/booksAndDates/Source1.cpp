//Christopher Katnic
//Project 3
//894-68-7516


#include <iostream>
#include <iomanip>
#include <cstring>
#include "Books.h"
#include "Dates.h"

char promptUser();
void addBook(Book[], int, Date);
void showList(Book[], int);

void selectionSort(int, Book[]);
// selectionSort(): Using selection sort, change the order of the books in the array, as per the user's chosen method

void swap(Book&, Book&);
// swap(): Utilized within function selectionSort(), swaps the positions of two cstrings in an array



using namespace std;

int main()
{
	Book bookList[30]; 
	int m, d, y, numBooks; char choice; bool stop = false;
	cout << "Welcome to the bookstore\n" << "Please enter in the date in the format mm dd yyyy: ";
	cin >> m >> d >> y;
	Date checkOut(m, d, y); numBooks = 0;




	//while the user has not chosen to stop yet, do everything
	while(!stop)
	{
		choice = promptUser();

		switch(choice)
		{

		case 'C':
		case 'c':
			{ addBook(bookList, numBooks, checkOut); numBooks++; break; }
		case 't':
		case 'T':
			{ showList(bookList, numBooks); break; }
		case 's':
		case 'S':
			{ selectionSort(numBooks, bookList);
				cout << "--------------\n" << "Sort complete\n"<< "--------------\n";
				break; }
		case 'Q':
		case 'q':
		default:
			{ stop = true; break; }
		};
	}
	
	
	return 0;

}


char promptUser()
	{
		char choice;
		cout << "\nPlease choose one of the three choices below\n";
		cout << "C: Check out a new book\n";
		cout << "T: Get a list of all books checked out thus far\n";
		cout << "S: Sort the books you currently have by first name of author\n";
		cout << "Q: Quit this program\n-----------------------------------------------\n";

		cin >> choice;
		return choice;
	}

void addBook(Book bookList[], int numBooks, Date checkOut)
{
	char f[30], l[30], t[40];
	cout << "\nPlesae enter in the first name, last name, and title of the book to check out,\nseparated by spaces\n";
	cin >> f >> l;
	cin >> ws;
	cin.getline(t, 50);

	//then after that add everything to the array of books, to be printed later
	bookList[numBooks].setCheckOutDate(checkOut);
	bookList[numBooks].setDueDate(checkOut);
	bookList[numBooks].setFirstName(f);
	bookList[numBooks].setLastName(l);
	bookList[numBooks].setTitle(t);

}

void showList(Book bookList[], int numBooks)
{
	char n[50], t[40];
	Date checkOut, due;
	cout << "\nThe following is a list of books already checked out from ye olde book shoppe:\n";
	cout <<left << setw(25)<< "Author" << setw(22) << "Title" << setw(17) <<  "Check Out Date" << setw(20) << "Due Date" << endl;

	for(int i = 0; i < numBooks; i++)
	{
		strcpy_s(n, bookList[i].getFirstName());
		strcat_s(n, " ");
		strcat_s(n, bookList[i].getLastName());
		strcpy_s(t, bookList[i].getTitle());
		checkOut = bookList[i].getCheckOutDate();
		due = bookList[i].getDueDate();

		cout << left << setw(25) << n << setw(23) << t <<   
			checkOut.getMonth() << " " << checkOut.getDay() << ", " << setw(10) << checkOut.getYear()<< 
			due.getMonth() << " " << due.getDay() << ", " << due.getYear() << "\n\n";

	}
}


void selectionSort(int numBooks, Book x[])  //Sorting by first name.
{
	int i, j, lowIndex;
	Book lowBook;

	for(i=0; i<numBooks; i++)
	{
		lowIndex = i;
		lowBook = x[i];

		for(j=i+1; j<numBooks; j++)
		{
			if(strcmp(lowBook.getFirstName(), x[j].getFirstName()) > 0)
			{
				lowBook = x[j];
				lowIndex = j;
			}
		}
		swap(x[i], x[lowIndex]);
	}
}

void swap(Book &book1, Book &book2)
{
	Book temp = book2;
	book2 = book1;
	book1 = temp;
}