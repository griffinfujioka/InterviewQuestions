// Amazon Interview Question (Online Assessment) 


#include<iostream>
using namespace std; 

struct ListNode 
{
  int value;
  ListNode *next;
};

bool hasLoops(ListNode *myList) 
{
	ListNode *slowIterator = myList; 
	ListNode *fastIterator = myList; 

	while(slowIterator->next != NULL)
	{
		fastIterator = slowIterator->next->next;		// advance fast iterator by 2 
		slowIterator = slowIterator->next;				// advance fast iterator by 1 

		if(&fastIterator == &slowIterator)
			return true; 

	}


	return false; 
}

void ExecuteTestSuite()
{
	ListNode head; 
	head.value = 1; 
	
	ListNode one; 
	one.value = 2 ; 

	ListNode tail; 
	tail.value = 3; 

	head.next = &one; 
	one.next = &tail; 
	tail.next = &head; 

	if(hasLoops(&head))
		cout << "Found loops in the list!" << endl; 
	else
		cout << "No loops were found in the list." << endl; 
}

int main()
{
	ExecuteTestSuite(); 

	cout << "Press any key to exit..." << endl; 
	char ch = getchar(); 
	return 0; 
}