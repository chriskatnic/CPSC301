//Christopher Katnic
//894-68-7516
//Problem 3

#include <iostream>
#include <iomanip> 

float average ( int [], int );
void findCounts ( int[], int, int[] );



int main ()

{
	int n;
	int scores[100];
	int scoreCount[11] = {0};

	//get number of scores
	std::cout << "Enter in the number of scores\n";
	std::cin >> n;
	
	//get scores
	std::cout << "Enter the quiz scores, separated by spaces\n";
	for ( int i = 0; i < n; i++ )
	{
		std::cin >> scores[i];
	}

	//get values for average and count
	float averageScore = average(scores, n);
	findCounts(scores, n, scoreCount);

	//output average
	std::cout << std::setprecision(3) << "The average:\t" << averageScore << "\n\n";


	//output histogram
	std::cout << "Histogram:\n";
	for ( int j = 0; j < 11; j++ )
	{
		std::cout << j << "\t";
		
		for ( int k = 0; k < scoreCount[j]; k++ )
		{
			std::cout <<"*";
		}
		std::cout << "\n";
	}



	return 0;
}

float average ( int scores[], int n )
{
	float sum = 0;
	for ( int i = 0; i < n; i++ )
		sum+= scores[i];
	return ( sum / n );
}

void findCounts ( int scores[], int n, int scoreCount[] )
{
	for ( int i = 0; i < 11; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			if ( scores[j] == i )
			{
				scoreCount[i]++;
			}
		}
	}
}


