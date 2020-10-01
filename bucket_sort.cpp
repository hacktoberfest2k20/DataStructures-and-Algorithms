//bucket sort
//time complexity:average case-O(n + k)
//               :worst case-O(n²)
//space complexity: O(n + k)

#include<bits/stdc++.h>
using namespace std;

void bucketSort(float a[],int n){
vector<float> buckets[n];
int i,j;
for(i=0;i<n;i++){
    buckets[(int)(n*a[i])].push_back(a[i]);
}
for(i=0;i<n;i++){
    sort(buckets[i].begin(),buckets[i].end());
}
int index=0;
for(i=0;i<n;i++){
    for(j=0;j<buckets[i].size();j++){
        a[index++]=buckets[i][j];
    }
}

}

void print(float *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int main(){
float a[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
int n = sizeof(a)/sizeof(float);
bucketSort(a,n);
print(a,n);
return 0;
}
