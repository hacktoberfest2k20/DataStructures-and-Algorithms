\* program to calculate gcd (greatest common divisor) of two numbers a and b
If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. 
So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.
*\

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
       
ll gcd(ll a,ll b){
     if(b==0) return a;  //base case
     return gcd(b,a%b);     
}
        
int main(void)
{
    ll a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
        
        
    
        
