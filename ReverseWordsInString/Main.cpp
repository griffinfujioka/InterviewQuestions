#include <iostream>
#include <string>
using namespace std; 


string ProcessSentence(string sentence);
void ReverseWord(string &word, int start, int end);
void swap(string &sentence, int i, int j);

int main()
{
	// Iterate through the initial string, finding the spaces and puncuation
	cout << "Welcome to the word reversal program!" << endl; 
	cout << "Our task: Reverse the words in a string in place. \nAssume words are separated by ' ' spaces and the sentence ends in a period." << endl; 

	string input1 = "This lecture is boring."; 
	string answer1 = ProcessSentence(input1); 

	cout << "Input 1: " + input1 << endl; 
	cout << "Answer 1: " + answer1 << endl; 

	string input2 = "I am a software developer.";
	string answer2 = ProcessSentence(input2); 

	cout << "Input 2: " + input2 << endl; 
	cout << "Answer 2: " + answer2 << endl; 
	

	cout << "Press any key to exit..." << endl;; 
	char ch; 
	ch = getchar(); 

	return 0;
}

// Wrapper function for processing sentances 
string ProcessSentence(string sentence)
{
	int length = sentence.length();
	int i=0; 
	int start = 0, end = 0;

	while(i < length)
	{
		if(sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == 0)
		{
			end = i -1; 

			ReverseWord(sentence, start, end); 

			start = i+1; 
		}
		i++; 
	}

	return sentence; 

}

// Reverse the word ranging from the start and end indices in place
void ReverseWord(string &sentence, int start, int end)
{
	if(start > end)
	{
		cout << "What is going on here...?" << endl; 
		return; 
	}

	while(start < end)
	{
		swap(sentence, start, end);				// Reverse the word 
		start++; 
		end--; 
	}
}

// Swap the letters at indices i and j 
void swap(string &sentence, int i, int j)
{
	char temp = sentence[i];
	sentence[i] = sentence[j]; 
	sentence[j] = temp;
}
