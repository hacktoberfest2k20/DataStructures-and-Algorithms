/*
Problem: To check if given bracket sequence is balanced or not.
Complexity: O(N)
*/
#include <iostream>

using namespace std;

int main()
{
	//input a string with only '(' or ')' characters
	string s;
	cin >> s;
	int var = 1;
	if (s[0] == ')')
	{
		cout << "Not balanced\n"; //since a balanced sequence cannot start from ')'
		return 0;
	}

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			var++;
		}
		else if (s[i] == ')')
		{
			var--;
		}
		else
		{
			cout << "Illeagal input string.\n";
			return 0;
		}
		//if at any point var<0 => the string uptil now has more ')'s than '(' and hence cannot be balanced.
		if (var < 0)
		{
			cout << "Not balanced\n";
			return 0;
		}
	}

	if (var != 0)
	{
		cout << "Not balanced\n";
		//this implies that number of '(' != number of ')' hence sequence is not balanced.
	}
	else
	{
		cout << "Balanced sequence\n";
	}
	return 0;
}