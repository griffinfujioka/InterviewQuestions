// Act-On Interview Question
//
// Given an input string, find the longest substring which occurs more than once in the input string

// Algorithm:
//	- Use two indices, nested while loops and the built-in substring on the original char array to generate all possible substring 
//	- Maintain variables for currentSubstring and currentLongestSubstring
//	- For each substring, look for another occurence in the input string
//			If(foundSubstring(currentSubstring, end + 1) && currentSubstring.Length > currentLongestSubstring.Length)
//				currentLongestSubstring = currentSubstring