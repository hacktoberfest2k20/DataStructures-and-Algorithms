/*
    PRINTS AREA OF NESTED REACTANGLE UNION USING SWEEPLINE
*/

/*
 KUNAL RAUT (ZUKONIT14)  :- "DO WHAT YOU LIKE!"
 -PICT,PUNE! :)
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define mod9 1000000009
#define pi 3.1415926535
#define MAXN 1000005
#define N 1000001
#define MAX2N 1*1000 + 10
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define forci(p,n) for(ll i=p;i<(ll)n;i++)
#define forcj(p,n) for(ll j=p;j<(ll)n;j++)
#define bolt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define bits(a) __builtin_popcount(a)
#define test ll t;cin>>t;for(ll testi=1;testi<=t;testi++)
#define djokovic  freopen("input00.txt", "r", stdin);freopen("output00.txt", "w", stdout);
ll gcd(ll a, ll b) {    if (b == 0) return a;    return gcd(b, a % b);}
ll lcm(ll a, ll b) {    return (a / gcd(a, b) * b);}
ll expo(ll x, ll y) {
	ll res = 1; x = x % mod; while (y > 0) {
		if (y & 1)res = (1ll * res * x) % mod;
		y = y >> 1; x = (1ll * x * x) % mod;
	} return res;
}
ll ncr(ll n, ll r) { ll res = 1; if (r > n - r)r = n - r; for (ll i = 0; i < r; i++) {  res *= n - i;  res /= i + 1; } return res;}
ll max(ll a, ll b) {return (a > b) ? a : b;}
bool prime(ll n) {ll i; for (i = 2; i <= sqrt(n); i++) {if (n % i == 0)return false;} return true;}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{	if (a.second == b.second)
		return a.first < b.first;
	return (a.second < b.second);
}

//https://www.youtube.com/watch?v=WTJSt4wP2ME

ll rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
struct event
{
	ll x, t, y1, y2;
};
bool comp(const event &a, const event &b)
{
	if (a.x == b.x)
		return (a.t < b.t);
	return (a.x < b.x);
}
ll n, k, ans, p[MAXN], a[MAXN], vis[MAXN];
vector<event>ve;
multiset<ll>low, up;
void solve()
{
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
		ve.pb({x1, 1, y1, y2});
		ve.pb({x2, -1, y1, y2});
	}
	sort(all(ve), comp);
	ll laste = ve[0].x;
	for (auto e : ve)
	{
		//cout << e.x << " " << e.t << "\n";
		if (e.t == 1)   //ADDING EVENT PUTTING Y1 INTO LOW SET AND Y2 IN UP SET AND TAKING THE MAX IN UP SET AND MIN IN LOW SET AND TAKING THEIR DIFFERENCE AND MUKLTIPLE NY X DIFF
		{
			if (up.size())
			{
				auto it = up.end(); it--;
				auto it1 = low.begin();
				ans += ((*it - *it1) * (e.x - laste));
			}
			up.insert(max(e.y1, e.y2));
			low.insert(min(e.y1, e.y2));
		}
		else    //REMOVING EVENT ALSO ERASING Y1 AND Y2 AND TAKING ANSWER AND THEN REMOVING THE Y1 AND Y2
		{
			auto it = up.end(); it--;
			auto it1 = low.begin();
			ans += ((*it - *it1) * (e.x - laste));
			up.erase(up.find(max(e.y1, e.y2)));
			low.erase(low.find(min(e.y1, e.y2)));
		}
		laste = e.x;
		//cout << ans << " " << e.x << " " << e.t << " " << "\n";
	}
	cout << ans;
}
signed main()
{
	bolt;
#ifndef ONLINE_JUDGE
	djokovic;
#endif
	solve();
}

//SOMETHING LIKE THIS : https://codeforces.com/blog/entry/20377
// FOR TGHE CODE ALIGNED THE BASE ON OX JUST TAKING ONE Y AND TAKIBNG THAT SET'S TOP WITH X DIFF