// Act-On Interview Question
//
// Given an input string, find the longest substring which occurs more than once in the input string

// Algorithm:
//	- Use two indices, nested while loops and the built-in substring on the original char array to generate all possible substring 
//	- Maintain variables for currentSubstring and currentLongestSubstring
//	- For each substring, look for another occurence in the input string
//			If(foundSubstring(currentSubstring, end + 1) && currentSubstring.Length > currentLongestSubstring.Length)
//				currentLongestSubstring = currentSubstring

#include <iostream>
#include <string>
using namespace std; 

// Look for substring in the originalSubstring beginning at startIndex 
bool FoundSubstring(string originalString, string substring, int startIndex)
{
	int length = substring.length();

	while(startIndex != originalString.length())
	{
		
		if(!originalString.compare(startIndex, length, substring))
		{
			cout << "Found substring " << substring << " starting at index " << startIndex << endl; 
			return true; 
		}

		startIndex++; 
	}
	return false; 
}

string LongestSubstringWithMultipleOccurences(string originalString)
{
	int start = 0, end = 0; 
	string currentSubstring; 
	string currentLongestSubstring; 

	while(start < originalString.length())
	{
		end = start + 1;
		while(end < originalString.length())
		{
			currentSubstring = originalString.substr(start, end);

			if(FoundSubstring(originalString, currentSubstring, end) && (currentSubstring.length() > currentLongestSubstring.length()))
			{
				currentLongestSubstring = currentSubstring; 
			}

			end++; 
		}

		start++;
	}

	cout << "Longest substring which occurs more than once: " << currentLongestSubstring << endl; 

	return currentLongestSubstring; 
}

void ExecuteTestSuite()
{
	string s = "There is a string here."; 
	cout << "Test 1: " << s << endl; 
	LongestSubstringWithMultipleOccurences(s); 

	s = "aa"; 
	cout << "Test 2: " << s << endl; 
	LongestSubstringWithMultipleOccurences(s); 

	s = "HeyThereHey"; 
	cout << "Test 3: " << s << endl; 
	LongestSubstringWithMultipleOccurences(s); 
}

int main()
{
	ExecuteTestSuite();

	cout << "Press any key to exit..." << endl; 
	char ch = getchar();


	return 0; 
}