/*==========================================================================*/
/*
  
Time Complexity for tree construction is O(n). 
Time complexity to query in given range is O(Logn).  
Time complexity for update a value at a given index is O(Logn).
Space complexity for the code is O(n)
*/
/*--------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
using pi = pair<int,int>;
 
#define f first
#define s second
// function to find the minimum value. 
int getMid(int s, int e) { return s + (e -s)/2; }  
  
// recursive function to find minimum and maximum in the given range.
pi rangefunc(pi st[], int ss, int se, int qs, int qe, int index)  
{  
        if (qs <= ss && qe >= se)  
        return st[index];  
  
     
    if (se < qs || ss > qe)  
        return {INT_MAX,INT_MIN};  
  
     
    int mid = getMid(ss, se);
    pi temp;  
    temp.f= min(rangefunc(st, ss, mid, qs, qe, 2*index+1).f,  
                rangefunc(st, mid+1, se, qs, qe, 2*index+2).f); 
    temp.s= max(rangefunc(st, ss, mid, qs, qe, 2*index+1).s,  
                rangefunc(st, mid+1, se, qs, qe, 2*index+2).s);
    return temp;   
}  
  
pi rangeminmax(pi st[], int n, int qs, int qe)  
{  
      
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return {-1,-1};  
    }  
  
    return rangefunc(st, 0, n-1, qs, qe, 0);  
}  
  
// recursive function to to create the segment tree  
pi construct(int arr[], int ss, int se, 
                                pi st[], int si)  
{  
    
    if (ss == se)  
    {  
        st[si].f= arr[ss];
        st[si].s=arr[ss];  
        return st[si];  
    }  
  
   
    int mid = getMid(ss, se);  
    st[si].f = min(construct(arr, ss, mid, st, si*2+1).f,  
                    construct(arr, mid+1, se, st, si*2+2).f); 
    st[si].s = max(construct(arr, ss, mid, st, si*2+1).s,  
                    construct(arr, mid+1, se, st, si*2+2).s);  
    return st[si];  
}  
  
// function to construct the tree
pi *constructsegmenttree(int arr[], int n)  
{  
    int x = (int)(ceil(log2(n)));  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    pi *st = new pi[max_size];  
  
   
    construct(arr, 0, n-1, st, 0);  
  
    return st;  
} 
// recursive function to update the value in the tree
void update(pi * st,int diff,int i,int ss,int se,int si){
    if(i<ss||i>se) return ;
   if (ss == se) 
    { 
        st[si].first = diff; 
        st[si].second = diff; 
        return ; 
    } 
 
    int mid = getMid(ss, se); 
    update(st,diff,i,ss,mid,si*2+1); 
    update(st,diff,i,mid+1,se, si*2+2); 
  
    st[si].first = min(st[si*2+1].first, st[si*2+2].first); 
    st[si].second= max(st[si*2+1].second, st[si*2+2].second); 
}
void updateValue(int *arr, pi *st, int n, int index, int new_val)
{
   //int diff=new_val-arr[index];
    arr[index]=new_val;
   update(st,new_val,index,0,n-1,0);
}  
int main()
{
     int arr[] = {1, 3, 2, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
  
      
    pi *st = constructsegmenttree(arr, n);  
  
    int qs = 1; // Starting index of query range  
    int qe = 5; // Ending index of query range  
  
     
   pi temp=rangeminmax(st,n,qs,qe);
   cout<<"minimum and maximum in the given range"<<" "<<temp.first<<" "<<temp.second<<endl; 
   int new_val=15;
   int index=3;
   updateValue(arr,st,n,index,new_val);
   // After update 
   temp=rangeminmax(st,n,qs,qe);
   cout<<"minimum and maximum in the given range"<<" "<<temp.first<<" "<<temp.second<<endl; 	
 return 0;
}
