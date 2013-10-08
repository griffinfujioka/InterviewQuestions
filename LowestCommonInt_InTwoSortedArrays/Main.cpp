#include <iostream>
using namespace std; 

int LowestCommonElement(int a1[10], int a2[10]);

// Given two sorted arrays of integers, determine the lowest common integer between the two arrays 
int main()
{
	int a1[10] = { 1, 3, 5, 6, 7, 9, 11, 13, 15, 17 } ; 
	int a2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20 }; 

	cout << LowestCommonElement(a1, a2) << endl; 

	char ch = getchar();
	return 0; 
}

int LowestCommonElement(int a1[10], int a2[10])
{
	int i = 0;		// iterator for a1 
	int j = 0;		// iterator for a2 

	while(i < 10 && j < 10)
	{
		if(a1[i] < a2[j])
			i++; 
		else if(a1[i] > a2[j])
			j++; 
		else if(a1[i] == a2[j])
			return a1[i]; 
	}


	return -1; 
}