#include <string> 
#include <iostream>



class studentRecord
{

public:

	studentRecord();
	// Constructor
	// Pre: None
	// Post: New student will be created with nothing?

	void setFName(std::string);
	// Set the last name
	// Pre: New student has been created
	// Post: Student will have a last name
	
	void setLName(std::string);
	// Set the first name
	// Pre: New student has been created
	// Post: Student will have a first name
	
	void setID(int);
	// Set the ID
	// Pre: New student has been created
	// Post: Student will have an ID
	
	void setGPA(double);
	// Set the GPA
	// Pre: New student has been created
	// Post: Student will have a GPA

	int getID();
	// Return the ID of the student
	// Pre: A Student
	// Post: Will return the ID of the student

	double getGPA();
	// Return the GPA of the student
	// Pre: A student
	// Post: Will return the GPA of the student

	std::string getFname();
	// Return the first name of the student
	// Pre: There will be a student
	// Post: Will return the name of the student

	std::string getLname();
	// Return the last name of the student
	// Pre: There will be a student
	// Post: Will return the name of the student


	friend std::ostream &operator << ( std::ostream& out, studentRecord& s)
	{
		return out << s.getFname() << " " << s.getLname() << " ID: " << s.getID() <<
			" GPA: " << s.getGPA();
	}

	friend std::istream &operator >> ( std::istream& in, studentRecord& s)
	{
		return in >> s.ID >> s.fName >> s.lName >>  s.GPA;
	}


private:
	std::string lName, fName;
	int ID;
	double GPA;

};

studentRecord::studentRecord()
{
	lName = " ";
	fName = " ";
	ID = 0;
	GPA = 0.00;

}

void studentRecord::setFName(std::string n)
{
	fName = n;
}

void studentRecord::setLName(std::string n)
{
	lName = n;
}

void studentRecord::setID(int n)
{
	if ( n < 1000000000 && n > 0 )
	ID = n;
}

void studentRecord::setGPA(double n)
{
	if ( n < 4 && n > 0 )
	
		GPA = n;
}

std::string studentRecord::getFname()
{
	return fName;
}

std::string studentRecord::getLname()
{
	return lName;
}

int studentRecord::getID()
{
	return ID;
}

double studentRecord::getGPA()
{
	return GPA;
}