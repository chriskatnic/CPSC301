#include "Books.h"
#include <cstring>
#include "Dates.h"

//Constructor for book
	Book::Book( const char *ff, const char *ll, const char *tt, Date checkOut, Date dueDate)
	{
		setCheckOutDate(checkOut);
		setDueDate(dueDate);
		setFirstName(ff);
		setLastName(ll);
		setTitle(tt);
	}

	Book::Book()
	{
		Date x;
		setCheckOutDate(x);
		setDueDate(x);
		setFirstName("NULL");
		setLastName("NULL");
		setTitle("NULL");
	}
	Book & Book::setCheckOutDate( Date x )
	{
		checkOut = x;
		return(*this);
	}

	Book & Book::setDueDate( Date x )
	{
		x += 14;
		due = x;
		return(*this);
	}

	Date Book::getCheckOutDate()
	{
		return checkOut;
	}

	Date Book::getDueDate()
	{
		return due;
	}
	
	Book::~Book()
	{
		
	}

	Book & Book::setFirstName( const char *x )
	{
		strcpy_s(firstName, x);
		return(*this);

	}
	Book & Book::setLastName( const char *x )
	{
		strcpy_s(lastName, x);
		return(*this);
	}
	Book & Book::setTitle( const char *x )
	{
		strcpy_s(title, x);
		return(*this);
	}

	const char *Book::getFirstName()
	{
		return firstName;
	}
	const char *Book::getLastName()
	{
		return lastName;
	}
	const char *Book::getTitle()
	{
		return title;
	}

