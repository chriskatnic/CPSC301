#include <iostream >
#include < fstream >

//practice writing to and getting from a file.



int main()
{
	char c[3] = { '1', '2', '3' };
	char d[3];
	char e[3];
	char * s;
	int length;

	
	std::ofstream output("other.bin");		//open da file
	output.write( c, 3);					//writing to a binary file, write( char[], int ) int for how many characters from the array to write onto the file
	output.close();							//done with the file

	std::ifstream input("other.bin");		//open da file
	input.read(d, 3);						//simple way to read everything in a binary file, read ( char[], int ) int for how many characters to read

	input.seekg(0, input.end);				//places the cursor at the end of the file, 0 means that it's at position 0
	length = input.tellg();					//tellg() returns the int value of how many characters long the file is
	input.seekg(0, input.beg);				//places the cursor at the beginning of the file at position 0

	s = new char [ length ];				//make the character array [length] which we just got above
	input.read(s, length);					// read( char *, int ) reads all the data in a binary file up to [length] characters
	input.close();							//done with the file
		
	std::cout.write(s, length);				//function to print out everything in char array
	std::cout << "\n";						//make it pretty
	delete s;								// *s was dynamic, gotta delete it

	std::ofstream output2 ( "other.txt" );
	output2 << c[0] << " " << c[1] << " " << c[2];
	output2.close();

	std::ifstream input2 ( "other.txt" );
	input2 >> e[0] >> e[1] >>  e[2];
	input2.close();

	std::cout << e[0] << " " << e[1] << " " << e[2] << "\n";
	std::cout << d[0] << " " << d[1] << " " << d[2] << "\n";

	

	return 0;
}
