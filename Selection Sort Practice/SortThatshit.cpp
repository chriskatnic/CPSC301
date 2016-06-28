//program designed to utilize selection sort in an array
//this array can hold as many values as the user needs

#include <iostream>
#include <string>


using namespace std;

template <class T>
void Swap(T &item1, T &item2);

template <class T>
void sSort(T* x, int elem);


int main()
{
	int unsorted[10];
	
	cout << "Enter in a string of values (int) and the algorithm will sort.:\n";
	
	for(int i = 0; i < 10; i++)
	{
		cin >> unsorted[i];
	}

	sSort(unsorted, 10);


	for(int i = 0; i < 10; i++)
	{
		cout << unsorted[i] << endl;
	}


	return 0;
}


//sorting function can sort any kind of array of class T
template <class T>
void sSort(T* x, int elem)
{
	//variables lowValue and lowIndex are to hold the values of the items that are deemed lowest
	//i and j are for iteration
	T lowValue; int lowIndex, i, j;

	//start with the first value i = 0 and compare to all other values j = 1:n
	for(i = 0; i<elem; i++)
	{
		lowValue = x[i]; lowIndex = i;

		for(j = i+1; j < elem; j++)
		{

			if(x[j] < lowValue)
			{ lowIndex = j; lowValue = x[j]; } 
		}
		//after finding what the currently lowest value is, swap it with value x[i] which is the lowest in the array at all times
		Swap(x[i], x[lowIndex]);
	}
}

//swap two things. Still untested in certain arrays.
template <class T>
void Swap(T &item1, T &item2)
{
	T temp = item1; item1 = item2; item2 = temp;
}
