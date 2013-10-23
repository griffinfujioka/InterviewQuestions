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