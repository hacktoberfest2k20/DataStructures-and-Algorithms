#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x; //n=number of values in array, x=target value
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> x;

	sort(a, a + n); //sorting the input array to apply binary search
	//can use any fast enough sorting algo
	int l = 0, h = n - 1; //l=lower limit, h= upper limit;

	while (l < h)
	{
		int mid = (l + h) / 2;
		if (a[mid] == x)
		{
			cout << "Target " << x << " found at index:" << mid + 1 << "\n";
			return 0;
		}
		else if (a[mid] > x)
		{
			h = mid - 1;
			l = l + 1 ; //if the no is not present between l to h then we should increase l index because the element we are searching for is not present at l
		}
		else if (a[mid] < x)
		{
			l = mid + 1;
		}
	}
	cout << "Target " << x << " not found in array.\n";
	return 0;
}
