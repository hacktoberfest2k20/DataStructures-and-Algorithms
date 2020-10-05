// Name : GCD of two numbers in log(max(a,b)) time.
// Time Complexity : log(max(a,b));
// Space Complexity : constant

#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
    // use the result that gcd(a,b) = gcd(b%a,a) recursively;
    if(b == 0) return a;
    if(a == 0) return b;
    return gcd(b%a,a);
}

signed main()
{
    int a, b;
    // Enter the 2 numbers to calculate the gcd;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;   
}
