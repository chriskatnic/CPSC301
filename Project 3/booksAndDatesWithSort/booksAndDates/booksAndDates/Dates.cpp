#include "Dates.h"
// Member function definitions for Date class

// Initialize static member at file scope; 
// one class-wide copy.
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int m, int d, int y ) { setDate( m, d, y ); }

// Set the date
void Date::setDate( int mm, int dd, int yy )
{
   month = ( mm >= 1 && mm <= 12 ) ? mm : 1;
   year = ( yy >= 1900 && yy <= 2100 ) ? yy : 1900;

   // test for a leap year
   if ( month == 2 && leapYear() )
      day = ( dd >= 1 && dd <= 29 ) ? dd : 1;
   else
      day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
}



// Add a specific number of days to a date
void Date::operator+=( int additionalDays )
{
   for ( int i = 0; i < additionalDays; i++ )
      helpIncrement();

}

// If the year is a leap year, return true; 
// otherwise, return false
bool Date::leapYear(  ) const
{
   if ( year % 400 == 0 || ( year % 100 != 0 && year % 4 == 0 ) )
      return true;   // a leap year
   else
      return false;  // not a leap year
}

// Determine if the day is the end of the month
bool Date::endOfMonth( ) const
{
   if ( month == 2 && leapYear( ) )
      return (day == 29); // last day of Feb. in leap year
   else
      return (day == days[ month ]);
}

 
// Function to help increment the date
void Date::helpIncrement()
{
   if ( ! endOfMonth( )) {  // date is not at the end of the month
      day++;
   }
   else if (month < 12 ) {       // date is at the end of the month, but month < 12
      day = 1;
      ++month;
   }
   else       // end of month and year: last day of the year
   {  
	   day = 1;
      month = 1;
      ++year;
	}
}

int Date::getDay()
{ return day; }

int Date::getMonth()
{ return month; }

int Date::getYear()
{ return year; }
