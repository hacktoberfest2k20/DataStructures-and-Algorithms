//Inversion Count 
//Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector> //vector lib
#define INF 1000000000

using namespace std;

//merge_sort function that orders a vector v
int merge_sort(vector<int> &v){
    //declare inv (total inversions)
    int inv = 0;

    // if the size of v is 1, there are no inversions  
    if(v.size() == 1) return 0;

    //if not
    //create two vectors
    vector<int> u1, u2;

    
    //and make each one receive half of v
    for(int i = 0; i < (int)v.size()/2; i++){
        u1.push_back(v[i]);
    }
    for(int i = v.size()/2; i < (int) v.size(); i++){
        u2.push_back(v[i]);
    }
    //order u1 and u2

    //add the inversions of each half of the vector to inv
    inv += merge_sort(u1);
    inv += merge_sort(u2);

    //add INF to the end of each one
    u1.push_back(INF);
    u2.push_back(INF);

    //declare begin1 and begin2 with initial value zero 
    int begin1 = 0, begin2 = 0;

    //scroll through each position of v
    for(int i = 0; i < (int) v.size(); i++){

        if(u1[begin1] <= u2[begin2]){ //if the unused minor of u1 is smaller or the same value in u2

            v[i] = u1[begin1]; //put in v
            begin1++; //add one in begin1

        }else{ //if not, do the analog with u2 and begin2

            v[i] = u2[begin2]; 
            begin2++;

            //not forgetting to add the number of elements in u1 to the total inversions in v
            inv += u1.size() - begin1 -1;
        }
    }
    //Finally, I return the amount of inversions
    return inv;
}

int main(){
    cin.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    vector<int> vec;
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(5);

    cout << merge_sort(vec) << endl;
    
    return 0;
}
