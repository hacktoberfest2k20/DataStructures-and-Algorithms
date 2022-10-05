/* Insertion Sort is a sorting algorithm.
Time Complexity of Insertion Sort in worst and average cases is O(n^2) and in best case is O(n). */
#include <bits/stdc++.h> 
using namespace std; 
void iSort(int b[], int n)  
{  
    int i,v,j;  
    for (i = 1; i < n; i++) 
    {  
        v = b[i];  
        j = i - 1;  
        while (j >= 0 && b[j] > v) 
        {  
            b[j + 1] = b[j];  
            j = j - 1;  
        }  
        b[j + 1] = v;  
    }  
}  
void ans(int b[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)
    {
        cout << b[i] << " "; 
    }
    cout <<"\n"; 
}  
int main()  
{  
    int b[] = { 7, 3, 5, 1, 9, 2 };  
    int n = sizeof(b) / sizeof(b[0]);  
    iSort(b, n);  
    ans(b, n);  
    return 0;  
}  
