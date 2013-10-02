#include <iostream>
using namespace std; 


int matrix[4][4] = {
	{11, 12, 13, 14},
	{21, 22, 23, 24},
	{31, 32, 33, 34},
	{41, 42, 43, 44} 
};

void PrintMatrix(int n);

int main()
{


	PrintMatrix(4);

	//PrintMatrix(matrix);

	cout << "Press Enter to exit..." << endl; 
	getc(stdin);
	return 0; 
}

// Print a matrix given the size of the matrix 
void PrintMatrix(int n)
{
	int i=0, j=0; 

	// i = row iterator, j = column iterator 

	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			cout << matrix[i][j] << " "; 
		}
		cout << endl; 
	}

	cout << endl; 
}

void PrintMatrix(int matrix[4][4])
{
	int i=0, j=0; 

	for(i=0; matrix[i][j] != NULL; i++)
	{
		for(j=0; matrix[i][j] != NULL; j++)
		{
			cout << matrix[i][j] << " "; 
		}

		cout << endl; 
	}
}
