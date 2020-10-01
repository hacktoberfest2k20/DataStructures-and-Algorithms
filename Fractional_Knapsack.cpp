/*
Solution of Fractional Knapsack Problem using Greedy Approach
*/
#include <bits/stdc++.h>
#define SIZE 50

using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


int main()
{
    int n, W[SIZE], V[SIZE], cost[SIZE], M;
    float total=0.0f;
    float frac=0.0f;
    int i,j;
    cout << "Enter the number of Items to be stolen" << endl;
    cin>>n;
    cout << "Enter the Size of the bag" << endl;
    cin>>M;
    for(i=0;i<n;i++){
        cout<< "Enter the weight and value for item "<<(i+1)<<endl;
        cin>>W[i];
        cin>>V[i];
        cost[i]=V[i]/W[i];
    }

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (cost[j] < cost[j+1]){
                swap(&cost[j], &cost[j+1]);
                swap(&W[j], &W[j+1]);
                swap(&V[j], &V[j+1]);
            }
        }
    }

    cout<<endl<<endl<<"The values sorted by value/weight ratio are"<<endl;
    cout<<"Item\tweights\tvalue\tcost"<<endl;
    for(i=0;i<n;i++){
        cout<<(i+1)<<"\t"<<W[i]<<"\t"<<V[i]<<"\t"<<cost[i]<<endl;
    }

    cout<<endl<<endl;

    i=0;
    while(i<n){
        if(W[i]<=M){
            M=M-W[i];
            total+=V[i];
            cout<<"Filled Bag with item of Weight "<<W[i]<<" and value "<<V[i]<<endl;

        }
        if(W[i]>M){
            frac=(float)M/W[i];
            total=total+frac*V[i];
            cout<<"Filled "<<frac<<" of last item with weight "<<W[i]<<" and value "<<frac*V[i]<<endl;
            break;
        }
        i++;
    }
    cout<<"The total profit attained is "<<total;
    return 0;
}
