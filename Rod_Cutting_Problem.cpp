int main()
{
	//CODE FOR FINDING MAX VALUE OBTAINED BY CUTTING ROD INTO PIECES OF Ith SIZE GIVES PRICE OF A[i] AND FINDING FOR ROD OF LENGTH N WITH PRICE[0..N-1] GIVEN.
	ll n; cin >> n; ll a[n];
	for (int i = 0; i < n; i++)  cin >> a[i];
	int dp[n + 5] = {0};
	for (int i = 1; i <= n; i++)
	{
		int max_val = INT_MIN;
		for (ll j = 0; j < i; j++)
		{
			max_val = max(max_val, a[j] + dp[i - j - 1]); //i-j is difference needed for j to complete till i
		}
		dp[i] = max_val;
	}
	cout << dp[n];
}