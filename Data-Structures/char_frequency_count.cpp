#include <bits/stdc++.h>

using namespace std;
void char_frequency_count(string str)
{
    unordered_map<char,int> m;
    for(auto x: str)
    {
        m[x]++;
    }
    for(auto x:m)
    {
        cout<<x.first<<":"<<x.second<<endl;
    }
}

int main()
{
    cout<<"please enter string"<<endl;
    string str;
    cin>>str;
    char_frequency_count(str);

    return 0;
}
