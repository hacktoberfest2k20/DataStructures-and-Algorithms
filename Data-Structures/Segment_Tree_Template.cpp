// Name : Segment tree for range sum queries and point updates.
// Time complexity : build : nlogn
//                   query : logn
//                   update : logn
// Space Complexity : n

struct segtree {
    vector<int> arr;
    int sz = 1;
    void  init(int n) {
        while(sz < n) sz *= 2;
        arr.assign(2*sz,0);
    }
    void update(int pos, int val, int curr_node, int l, int r) {
        if(r-l == 1) {
            // here the curr_node will become = to i;
            
            
            arr[curr_node] = val;
            return;
        }
        // now decide where to go - left subtree or right subtree
        
        
        int m = (l+r)/2;
        if(pos < m) {
            // go left
            
            update(pos,val,2*curr_node+1,l,m);
            
            // curr_node becomes the left child of x i.e 2*x+1;
        } else {
            // go right
            
            update(pos,val,2*curr_node+2,m,r);
            
            // curr_node becomes the right child of x i.e 2*x+2;
        }
        // and here the sum of curr_node = sum of left child and right child
        
        
        arr[curr_node] = arr[2*curr_node+1]+arr[2*curr_node+2];
        return;
    }

    void update(int pos, int val) {
        update(pos,val,0,0,sz);
        
        
        // 0 means the root; we start update with the root
    }

    /*------------
    this is where all the changes will be made for point updates;
    -------------*/
    
    
    int sum(int l, int r, int curr_node, int currL, int currR) {
        if(currL >= r || currR <= l) return 0; // outside the segment
        if(currL >= l && currR <= r) return arr[curr_node]; // totally inside the segment
        int m = (currL+currR)/2;
        int ans = sum(l,r,2*curr_node+1,currL,m) + sum(l,r,2*curr_node+2,m,currR);
        return ans;
    }

    int sum(int l, int r) {
        return sum(l,r,0,0,sz);
    }
};
