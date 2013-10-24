// Act-On Interview Question
//
// Say you're given a function and an array of integers A and you want to call that function 
// on all possible permutations of A. How do you generate all permutations of A? 

// Algorithm:
//	- Make sure each element of A gets to be A[0] at least once 
//	- Generate all permutations on the rest of the array, A[1] thru A[n]

#include <iostream>
#include <vector> 
using namespace std; 

void swap(int* a, int* b)
{
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void permutate(vector<int> vec, int current, int size)
{
	if(current == size - 1)
	{
		for(int i = 0; i < vec.size(); i++)
			cout << vec[i] << "\t"; 

		cout << endl; 
	}
	else
	{
		for(int i = current; i < size; i++)
		{
			swap(&vec[current], &vec[i]);
			permutate(vec, current + 1, size); 
			swap(&vec[current], &vec[i]); 
		}
	}
}

int main() 
{
	vector<int> vec; 
	vec.push_back(1); 
	vec.push_back(2); 
	vec.push_back(3); 

	permutate(vec, 0, vec.size());

	char ch = getchar();

	return 0; 
}