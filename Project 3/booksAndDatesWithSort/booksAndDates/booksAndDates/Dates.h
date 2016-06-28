#include <iostream>
#ifndef DATE1_H
#define DATE1_H

using std::ostream;

class Date {

public:
   Date( int m = 1, int d = 1, int y = 1900 ); // constructor
   void setDate( int, int, int ); // set the date
   void operator+=( int ); // add days, modify object
   bool leapYear( ) const;    // is this a leap year?
   bool endOfMonth( ) const;  // is this end of month?
   int getMonth();
   int getDay();
   int getYear();

private:
   int month;
   int day;
   int year;

   static const int days[];       // array of days per month
   void helpIncrement();          // utility function
};

#endif

 