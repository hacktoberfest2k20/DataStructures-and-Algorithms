Kadane's Algorithm
Complexity: O(n) 


#include <bits/stdc++.h>
using namespace std; 
  
int maxSum(int a[], int size) 
{ 
   int max_in = a[0]; 
   int max_current = a[0]; 
  
   for (int i = 1; i < size; i++) 
   { 
        max_current = max(a[i], max_current+a[i]); 
        max_in = max(max_in, max_current); 
   } 
   return max_in; 
} 
  
int main() 
{ 
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   int max_sum = maxSum(a, n); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 
