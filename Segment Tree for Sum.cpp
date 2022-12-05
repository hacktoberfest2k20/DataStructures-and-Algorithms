// Segment Tree for updating ith index with value val and find sum from range [l,r)

#include <bits/stdc++.h>
using namespace std;
#include <vector>
using namespace std;
#define ll long long
#define pp pair<ll, ll>
#define vii vector<ll>

struct segment
{
    ll size;
    vector<ll> v;

    // initialize
    void make(ll n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }

        v.assign(2 * size + 1, 0);
    }

    // set function to set ith index to val
    void set(ll i, ll val, ll x, ll l, ll r)
    {
        if (r - l == 1)
        {
            v[x] = val;
            return;
        }

        ll m = (l + r) / 2;
        if (i < m)
        {
            set(i, val, 2 * x + 1, l, m);
        }
        else
        {
            set(i, val, 2 * x + 2, m, r);
        }

        v[x] = v[2 * x + 1] + v[2 * x + 2];
        return;
    }

    void set(ll i, ll val)
    {
        set(i, val, 0, 0, size);
    }

    // find the sum from range [lx,rx)
    ll sums(ll l, ll r, ll x, ll lx, ll rx)
    {
        // case 1
        if (r <= lx || l >= rx)
            return 0;

        // case 2
        if (l <= lx && r >= rx)
        {
            return v[x];
        }

        ll mid = (lx + rx) / 2;
        ll sum1 = sums(l, r, 2 * x + 1, lx, mid);
        ll sum2 = sums(l, r, 2 * x + 2, mid, rx);
        return sum1 + sum2;
    }

    ll sum(ll l, ll r)
    {
        return sums(l, r, 0, 0, size);
    }
};
int main()
{

    ll n, m;
    cin >> n >> m;
    segment st;
    st.make(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.set(i, x);
    }

    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            st.set(b, c);
        }
        else
        {
            cout << st.sum(b, c) << "\n";
        }
    }
}
