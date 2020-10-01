#include <iostream>
#include <vector>

using namespace std;

/*
This algorithm generates a list of all prime factors of n in O(sqrt(n)) complexity.
*/

int main()
{
	int n, nog;
	cin >> n;
	nog = n;

	vector<int> ans;

	for (int x = 2; x * x <= n; x++)
	{
		while (n % x == 0)
		{
			ans.push_back(x);
			n /= x;
		}
	}

	if (n > 1)
	{
		ans.push_back(n);
	}

	cout << "Prime factors of " << nog << " :";

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}