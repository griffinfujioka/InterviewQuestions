#include <iostream>
using namespace std; 

void FindMaxAndMin(int arr[]);

int main()
{
	int arr[10] = {1, 15, 17, 20, 5, 4, 25, 30, 45, 10};
	FindMaxAndMin(arr); 
	char ch = getchar(); 
	return 0; 
}

void FindMaxAndMin(int arr[])
{ 
	int i = 0; 
	int max = arr[i], min = arr[i]; 

	while(i < 10)
	{
		if(arr[i] < min)
			min = arr[i]; 

		if(arr[i] > max)
			max = arr[i]; 
		i++; 
	}

	cout << "Max: " << max << endl; 
	cout << "Min: " << min << endl; 
}

