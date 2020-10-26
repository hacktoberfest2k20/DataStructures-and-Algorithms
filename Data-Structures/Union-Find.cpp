/*
Implements Unioun Find operations
Complexity: O(logN) amortized is O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    int numberOfComponents;
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n)
    {
        numberOfComponents = n;
        parent = vector<int>(n);
        size = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    //returns root node of the component where p belongs
    int find(int n)
    {
        int root = n;

        //find root of this component
        while (parent[root] != root)
        {
            root = parent[root];
        }

        //path-compression i.e. making all nodes in the route to point directly to the root
        while (parent[n] != n)
        {
            int temp = parent[n];
            parent[n] = root;
            n = temp;
        }
        return root;
    }

    //unites two components of n1 and n2
    void unite(int n1, int n2)
    {
        int root1 = find(n1);
        int root2 = find(n2);

        if (root1 == root2) //if belong to same component then no need to unite
            return;
        if (size[root1] < size[root2])
        {
            size[root2] += size[root1];
            parent[root1] = root2;
        }
        else
        {
            size[root1] += size[root2];
            parent[root2] = root1;
        }
        //number of components decrease by one
        numberOfComponents--;
    }

    //returns number of different components
    int getNumberOfComponents()
    {
        return numberOfComponents;
    }

    //returns true if n1 and n2 belong to same component and false otherwise
    bool isConnected(int n1, int n2)
    {
        return find(n1) == find(n2);
    }
};

// int main()
// {
//     UnionFind uf(10);
//     cout << uf.find(5) << endl;
//     cout << uf.getNumberOfComponents() << endl;
//     uf.unite(6, 5);
//     cout << uf.find(5) << endl;
//     cout << uf.getNumberOfComponents() << endl;
//     cout << uf.isConnected(1, 2) << endl;

//     return 0;
// }