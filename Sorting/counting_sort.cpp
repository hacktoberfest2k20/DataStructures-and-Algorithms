/*
Author:- Yogesh kansal
Algorithm:- Counting sort
time complexity:- O(n)
space complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int i,n;
    cin>>n;
    int A[n+1];
    for(i=1;i<=n;i++)
        cin>>A[i];

    int B[n+1],C[n+1];

    for(i=1;i<=n;i++) 
        C[i] = 0;

    for(i=1;i<=n;i++) 
        C[A[i]] = C[A[i]] + 1;

    for(i=2; i<=n;i++)
        C[i] = C[i] + C[i-1];

    for(i=n; i>=1;i--) 
    { 
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    
    }
    for(i=1;i<=n;i++) 
        A[i] = B[i];

    for(i=1;i<=n;i++)
        cout<<A[i]<<" ";
    return 0;
}