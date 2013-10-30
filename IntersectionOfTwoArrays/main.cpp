// Given two vector<int>, return the intersection of the arrays (i.e., common elements)
// Algorithm: Put all elements from array A in a map. If an element in A is duplicated (i.e., it's already a Key in the map)
// DO NOTHING. However, if an element from B is already in the map, increment the value by 1. 
// Finally, to find the intersection, look through all Key, Value pairs in the map and return the Keys whose Value > 1 

#include <iostream>
#include <algorithm>			// sort 
#include <vector>		
#include <map>
using namespace std; 


vector<int> Intersection(vector<int> a, vector<int> b)
{

	vector<int> returnVector; 
	map<int, int> myMap;	
	
	int aLength = a.size(); 
	int bLength = b.size(); 

	int i = 0; 

	while(i < aLength)
	{
		if(myMap[a[i]] == 0)		// check if the element is already a Key in myMap 
			myMap[a[i]] = 1; 

		i++; 
	}

	i = 0; 

	while(i < bLength)
	{
		if(myMap[b[i]] == 1)		// check if the element is already a Key in myMap 
			myMap[b[i]] += 1; 

		i++; 

	}

	map<int, int>::iterator mapItr = myMap.begin(); 

	while(mapItr != myMap.end())
	{
		if(mapItr->second > 1)
			returnVector.push_back(mapItr->first);

		mapItr++; 
	}


	return returnVector; 
}

void ExecuteTestSuite()
{
	int myints[] = {16,1, 6, 3, 7, 8, 1, 9, 2};
	vector<int> A(myints, myints + sizeof(myints)/ sizeof(int)); 

	memset(&myints, 0, sizeof(myints)); 
	vector<int> B; 
	B.push_back(16); 
	B.push_back(1); 
	B.push_back(6); 
	B.push_back(3); 
	B.push_back(5); 
	B.push_back(6); 
	B.push_back(1); 
	B.push_back(5); 

	vector<int> test = Intersection(A, B); 

	vector<int>::iterator it1 = test.begin(); 

	while(it1 != test.end())
	{
		cout << *it1 << endl; 
		it1++; 
	}

}

int main()
{
	ExecuteTestSuite(); 

	cout << "Press any key to exit..." << endl; 
	char ch = getchar(); 

	return 0; 
}