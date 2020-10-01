#include<iostream>
using namespace std;

class root
{
	
	public:
		float squareRoot(float n)
		{
			float x = n;
			float y = 1;
			
			while(x>y)
			{
				x=(x+y)/2;
				y=n/x;
			}
			return x;
		}
};

int main()
{
	root r;
	int n=0;
	cout << "Enter the number :";
	cin >>n;
	cout <<"Square root of is"<<r.squareRoot(n);
	getchar();
}
