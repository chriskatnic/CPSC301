 #include <iostream>
#include <cstring>
#ifndef BOOK1_H
#define BOOK1_H
#include "Dates.h"
class Book {

	public:
		Book ( const char*, const char*, const char*, Date, Date);
		Book ( );   //CONSTRUCTOR WITH NO ARGUMENTS, OVERLOADED FOR INITIAL DECLARATION
		~Book();
		Book & setCheckOutDate ( Date);
		Book & setDueDate( Date);
		Book & setFirstName ( const char*);
		Book & setLastName ( const char*);
		Book & setTitle ( const char*);
		const char* getFirstName();
		const char* getLastName();
		const char* getTitle();
		Date getCheckOutDate();
		Date getDueDate();

		static int getCount();

	private:
		char firstName[30];
		char lastName[30];
		char title[40];
		Date  checkOut;
		Date	due;
		static int count;
};
#endif

