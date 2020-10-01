//Bucket sort
//Time Complexity

//Data is uniformly distributed....
//best case is O(n).....

//When data is not uniformly distributed....
//worst case O(n**2)..........

#include<bits/stdc++.h>
using namespace std;

void bucket_sort(int *a,int total_bucket,int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
        m=max(m,a[i]);
    m=m+1;
    vector<int>buckets[total_bucket];
    for(int i=0;i<n;i++)
    {
        int bucket_index=a[i]*total_bucket/m;
        buckets[bucket_index].push_back(a[i]);

    }
    for(int i=0;i<total_bucket;i++)
    {
        sort(buckets[i].begin(),buckets[i].end());

    }
    //Finally concatination
    int index=0;
    for(int i=0;i<total_bucket;i++)
    {
        for(int j=0;j<buckets[i].size();j++)
        {
            a[index++]=buckets[i][j];
        }
    }

}
int main()
{
    int a[]={30,40,10,80,5,12,70};
    bucket_sort(a,4,7);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    return 0;
}
