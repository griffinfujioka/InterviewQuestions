#include <iostream>
using namespace std; 

/************************************************/ 
/* math.h wasn't working for me, so I defined	*/ 
/* my own round function (which I found online	*/ 
/************************************************/ 
int round(double d)
{
    return static_cast<int>(d + 0.5);
}

/************************************************/ 
/* Draw a circle on the screen by making use of */ 
/* the equation r = x^2 + y^2					*/ 
/************************************************/ 
void DrawCircle(int radius)
{
	int i, j; 

	cout << "================================" << endl; 
	cout << "Radius = " << radius << endl; 
	cout << "================================" << endl; 

	for(i = -radius; i <= radius; i++)
	{
		for(j = -radius; j <= radius; j++)
		{
			if(round(sqrt(i*i + j*j)) == radius)
			{
				cout << '*'; 
			}
			else
			{
				cout << ' '; 
			}
		}

		cout << endl; 
	}
}

int main()
{
	

	DrawCircle(1); 
	DrawCircle(2); 
	DrawCircle(4); 
	DrawCircle(8); 

	cout << "Press any key to exit..." << endl; 
	char ch = getchar(); 
	return 0; 
}