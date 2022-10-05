
// in this approach we use recursion and take the help of the auxilary rod to move all the discs from
//one rod to another
// our refrenced auxilary rod changes everytime and we call the function recursively

// Time complexity: O(2^N)
//Auxiliary Space: O(N)
//code
#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
 

int main()
{
    int N = 3;
 
    
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}