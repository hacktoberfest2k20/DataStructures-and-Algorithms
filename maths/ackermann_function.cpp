/*
Author -Yogesh kansal

problem description:-
Ackermann function is defind from non-negative numbers,as-
f(a,b) = b+1; if a=0,
f(a,b) =  f(a-1,1), if a>0 && b==0,
f(a,b) = f(a-1, f(a,b-1)); if a>0 &&b>0,
To solve this we can recurisvely call function with sufficient conditions.

*/
#include<bits/stdc++.h>
using namespace std;
int Ackermann_Function(int m, int n)
{
	if(m==0)
		return n+1;
		
	else if(m>0&&n==0)
		return Ackermann_Function(m-1,1);
		
	else if(m>0&&n>0)
		return Ackermann_Function(m-1,Ackermann_Function(m,n-1));
}

int main()
{
	int A,B;
	cin>>A>>B;
	cout<<"Output is: "<<Ackermann_Function(A,B);
	return 0;
}

/*
time complexity:-O(mA(m, n)) to compute A(m, n)
space complexity:- O(m) to compute A(m, n)
Examples:-
(1). m=1,n=2
	  output=4
(2). m=3,n=3
	  output=61
*/