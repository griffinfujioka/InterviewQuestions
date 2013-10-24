// Act-On Interview Question
// 
// Populate an array to meet the following distribution criteria: 
//	- 800 elements between 1-100
//	- 150 elements between 101-500
//	- 50 elements between 501-1000


// Algorithm:
//	- Generate 800 random numbers with max=100 and populate the array indices 0 - 799
//	- Generate 150 random numbers with max=100, add 500 to each random number and populate indices 800-949
//	- Generate 50 random numbers with max=500, add 500 to each random number and populate indices 950-999
//	- Write a helper function with a prototype looking like:
//			int[] GenerateNumber(int n, int min, int max)		// Generate n numbers such that each is between min and max 
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

#define MAX_SIZE 1000

vector<int> GenerateNumbers(int n, int min, int max)
{
	const int size = n; 
	vector<int> vec(n); 
	int i = 0; 

	int num;
	srand(0); 
	while(i < n)
	{
		num = rand() % (max - min + 1);			// generate a random number between 1 and max 
		num += min + 1; 
		vec[i] = num; 
		i++; 
	}


	return vec;
}

int main()
{
	int arr[MAX_SIZE]; 
	int i = 0, j = 0; 
	int num; 

	vector<int> test = GenerateNumbers(800, 1, 100); 
	vector<int> test2 = GenerateNumbers(150, 101, 500); 
	test.insert(test.end(), test2.begin(), test2.end()); 

	vector<int> test3 = GenerateNumbers(50, 501, 1000); 

	test.insert(test.end(), test3.begin(), test3.end()); 


	while(i < MAX_SIZE)
	{
		cout << test[i] << endl; 
		i++;
	}

	return 0; 
}