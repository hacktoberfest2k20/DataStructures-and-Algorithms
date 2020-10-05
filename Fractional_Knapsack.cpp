/*
Solution of Fractional Knapsack Problem

The Fractional Knapsack problem is that given a set of items, each with a weight and 
a value, determine the number of each item to include in a collection so that the total weight 
is less than or equal to a given limit and the total value is as large as possible. 
We also consider taking fractions of items to fill in the knapsack.

Using the Greedy Approach the Fractional Knapsack problem is solved in O(n^2) time complexity. 
The Space occupied is directly proportional to the number of items to be picked, primararily occupied by the 
W, V and cost arrays each occupying elements equal to the number of items.
Though on accounts of readibility a SIZE macro has been defined it can be tweaked 
as per need to accomodate any amout of items. 

Therefore, Time Complexity O(n^2)
& Space Complexity O(n)
where n is the number of items to be picked.
*/
#include <bits/stdc++.h>
#define SIZE 50

using namespace std;

//Utility function to help in Bubble-Sort
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    /*	n:-> Number of Items
	W:-> Array Containing weights of the Items
	V:-> Array Containing the values of the Items
	cost:-> Array that will contain the V/W ratio for each item
	M:-> Maximum weight carrying capacity of the Knapsack
*/
    int n, W[SIZE], V[SIZE], cost[SIZE], M;
    float total = 0.0f;
    float frac = 0.0f;
    int i, j;
    cout << "Enter the number of Items to be picked" << endl;
    cin >> n;
    cout << "Enter the Size of the bag" << endl;
    cin >> M;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the weight and value for item " << (i + 1) << endl;
        cin >> W[i];
        cin >> V[i];
        cost[i] = V[i] / W[i];
    }
    //Sorting The items in a Descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (cost[j] < cost[j + 1])
            {
                swap(&cost[j], &cost[j + 1]);
                swap(&W[j], &W[j + 1]);
                swap(&V[j], &V[j + 1]);
            }
        }
    }

    cout << endl
         << endl
         << "The values sorted by value/weight ratio are" << endl;
    cout << "Item\tweights\tvalue\tcost" << endl;
    for (i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t" << W[i] << "\t" << V[i] << "\t" << cost[i] << endl;
    }

    cout << endl
         << endl;

    i = 0;
    //Maximizing the profit
    while (i < n)
    {
        if (W[i] <= M)
        {
            M = M - W[i];
            total += V[i];
            cout << "Filled Bag with item of Weight " << W[i] << " and value " << V[i] << endl;
        }
        if (W[i] > M)
        {
            frac = (float)M / W[i];
            total = total + frac * V[i];
            cout << "Filled " << frac << " of last item with weight " << W[i] << " and value " << frac * V[i] << endl;
            break;
        }
        i++;
    }
    //Final Profit attained
    cout << "The total profit attained is " << total;
    return 0;
}
