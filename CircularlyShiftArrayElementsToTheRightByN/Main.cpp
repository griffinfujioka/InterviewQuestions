// Given an array of integers, shift the elements to the right by N circularly
// ALGORITHM: Determine the index at which you'll need to start shifting the elements circularly 
// by evaluating sizeOfArray - N, which will give you the index at which to start the cycling, aka the pivotIndex. 
// Iterate through the array swapping A[i+N] and A[i]

#include <iostream>
#include <vector>
using namespace std; 


void ShiftElementsRightByN(vector<int> &A , int N)
{
	int i = 0, j = 0; 
	int pivotIndex = A.size()  - N;		// index where circular shift begins 
	int temp; 

	for(i=0; i < pivotIndex; i++)
	{
		temp = A[i + N]; 
		A[i+N] = A[i]; 
		A[i] = temp;
	}
}

void PrintVector(vector<int> A)
{
	int i=0; 

	for(i=0; i < A.size(); i++)
	{
		cout << A[i] << ' '; 
	}
	cout << endl; 
}

int main()
{
	int myints[] = {1, 2, 3, 4}; 
	vector<int> a (myints, myints + sizeof(myints) / sizeof(int)); 
	
	PrintVector(a); 
	ShiftElementsRightByN(a, 2); 
	PrintVector(a); 

	cout << "Press any key to exit... " << endl; 
	char ch = getchar(); 
	return 0; 
}