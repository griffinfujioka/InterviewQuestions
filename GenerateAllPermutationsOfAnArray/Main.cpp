// Act-On Interview Question
//
// Say you're given a function and an array of integers A and you want to call that function 
// on all possible permutations of A. How do you generate all permutations of A? 

// Algorithm:
//	- Make sure each element of A gets to be A[0] at least once 
//	- Generate all permutations on the rest of the array, A[1] thru A[n]