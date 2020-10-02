/*Space complexity: O(1), Time complexity: log(min(a,b))*/
#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
	if(b == 0)
	return a;
	else
	{
		a = a % b;
		return gcd(b, a); /*Famous euclid theorem,property of gcd is used here*/
	}
}

int main()
{
	long long int a, b, n;
	scanf("%lld %lld",&a,&b);
	n = gcd(a, b);
	printf("%lld",n);
	return 0;
}
