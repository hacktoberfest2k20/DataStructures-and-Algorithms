#include <bits/stdc++.h>
#define ll long long int
#define int long long
#define loop(i, x, n) for (int i = x; i < n; i++)
#define rloop(i, x, n) for (int i = n - 1; i >= x; i--)
using namespace std;

int sz;
void makeSubsets(int i, vector<int> &v, vector<vector<int>> &res, int arr[])
{
    if(i>=sz)
    {
        res.push_back(v);
        return ;
    }
    //pick..
    v.push_back(arr[i]);
    makeSubsets(i+1, v, res, arr);
    v.pop_back();

    //not pick..
    makeSubsets(i+1, v, res, arr);
}

void code()
{
    int n; cin>>n;
    sz=n;
    int arr[n];
    loop(i,0,n) cin>>arr[i];
    vector<vector<int>> res;
    vector<int> v;
    makeSubsets(0, v, res, arr);
    cout<<"no of subsets: "<<res.size()<<endl;
    for(int i=0; i<res.size(); i++)
    {
        if(res[i].size()==0){
            cout<<"null"<<endl; 
            continue;
        }
        loop(j, 0, res[i].size())   cout<<res[i][j]<<" ";
        cout<<endl;
    }
}

signed main()
{
    cin.tie(NULL);
    cout.tie(NULL);
        code();
    return 0;
}
