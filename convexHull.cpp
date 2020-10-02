/** 
* Reference: http://www.dcs.gla.ac.uk/~pat/52233/slides/Hull1x1.pdf
==================================================================================================================================================
1) Find the bottom-most point by comparing y coordinate of all points. 
If there are two points with the same y value, then the point with smaller x coordinate value is considered. 
Let the bottom-most point be P0. Put P0 at first position in output hull.
2) Consider the remaining n-1 points and sort them by polar angle in counterclockwise order around points[0]. 
If the polar angle of two points is the same, then put the nearest point first.
3 After sorting, check if two or more points have the same angle. If two more points have the same angle, 
then remove all same angle points except the point farthest from P0. Let the size of the new array be m.
4) If m is less than 3, return (Convex Hull not possible).
5) Create an empty stack ‘S’ and push points[0], points[1] and points[2] to S.
6) Process remaining m-3 points one by one. Do following for every point ‘points[i]’
        6.1) Keep removing points from stack while orientation of following 3 points is not counterclockwise (or they don’t make a left turn).
            a) Point next to top in stack
            b) Point at the top of stack
            c) points[i]
         6.2) Push points[i] to S
7) Print contents of S
==================================================================================================================================================
* Time Complexity: Let n be the number of input points. The algorithm takes O(nLogn) time if we use a O(nLogn) sorting algorithm.
* Step 1: Finding the bottom-most point takes O(n) time. 
* Step 2: Sorting the points takes O(nLogn) time. 
* Step 3: Every element is pushed and popped at most one time which takes O(n) time.
* Step 4: Process points one by one takes O(n) time. 
* Assuming that the stack operations take O(1) time. Overall complexity is O(n) + O(nLogn) + O(n) + O(n) which is O(nLogn)
==================================================================================================================================================
*/

#include <bits/stdc++.h>
using namespace std; 
  
struct Point 
{ 
    int x, y; 
}; 
  
// A global point needed for  sorting points with reference 
// to  the first point Used in compare function of qsort() 
Point p0; 
  
// A utility function to find next to top in a stack 
Point nextToTop(stack<Point> &S) 
{ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 
  
// A utility function to swap two points 
int swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  
// A utility function to return square of distance 
// between p1 and p2 
int distSq(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// A function used by library function qsort() to sort an array of 
// points with respect to the first point 
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   // Find orientation 
   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
  
// Prints convex hull of a set of n points. 
void convexHull(Point points[], int n) 
{ 
   // Find the bottommost point 
   int ymin = points[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     int y = points[i].y; 
  
     // Pick the bottom-most or chose the left 
     // most point in case of tie 
     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   // Place the bottom-most point at first position 
   swap(points[0], points[min]); 
  
   // Sort n-1 points with respect to the first point. 
   // A point p1 comes before p2 in sorted output if p2 
   // has larger polar angle (in counterclockwise 
   // direction) than p1 
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   // If two or more points make same angle with p0, 
   // Remove all but the one that is farthest from p0 
   // Remember that, in above sorting, our criteria was 
   // to keep the farthest point at the end when more than 
   // one points have same angle. 
   int m = 1; // Initialize size of modified array 
   for (int i=1; i<n; i++) 
   { 
       // Keep removing i while angle of i and i+1 is same 
       // with respect to p0 
       while (i < n-1 && orientation(p0, points[i], 
                                    points[i+1]) == 0) 
          i++; 
  
  
       points[m] = points[i]; 
       m++;  // Update size of modified array 
   } 
  
   // If modified array of points has less than 3 points, 
   // convex hull is not possible 
   if (m < 3) return; 
  
   // Create an empty stack and push first three points 
   // to it. 
   stack<Point> S; 
   S.push(points[0]); 
   S.push(points[1]); 
   S.push(points[2]); 
  
   // Process remaining n-3 points 
   for (int i = 3; i < m; i++) 
   { 
      // Keep removing top while the angle formed by 
      // points next-to-top, top, and points[i] makes 
      // a non-left turn 
      while (orientation(nextToTop(S), S.top(), points[i]) != 2) 
         S.pop(); 
      S.push(points[i]); 
   } 
  
   // Now stack has the output points, print contents of stack 
   while (!S.empty()) 
   { 
       Point p = S.top(); 
       cout << "(" << p.x << ", " << p.y <<")" << endl; 
       S.pop(); 
   } 
} 
  

int main() 
{ 
    int n;
    cout<<"Enter number of points: "<<endl;
    cin>>n;
    Point points[n];
    for(int i=0;i<n;i++) {
      int x,y;
      cout<<"Enter x,y: "<<endl;
      cin>>x>>y;
      points[i].x=x;
      points[i].y=y;
    }
    cout<<"The convex hull is: "<<endl;
    convexHull(points, n); 
    return 0; 
} 
