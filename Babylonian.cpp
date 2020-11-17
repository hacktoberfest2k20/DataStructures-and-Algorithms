#include <iostream> 
using namespace std; 
class gfg { 
    /*Returns the square root of n. Note that the function */
public: 
    float squareRoot(float n) 
    { 
        /*We are using n itself as initial approximation 
          This can definitely be improved */
        float x = n; 
        float y = 1; 
        float e = 0.000001; /* e decides the accuracy level*/
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
    } 
}; 
  
/* Driver program to test above function*/
int main() 
{ 
    gfg g;
    int n;
    cout<<"Enter number to find square root:";
    cin>>n; 
    cout << "Square root of " << n << " is " << g.squareRoot(n); 
    getchar(); 
} 
