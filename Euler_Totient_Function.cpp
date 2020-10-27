#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
ll phi(ll n)
{
	ll ans = n; 
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0)
		{
			ans = (ans * (i - 1)) / i;
 
			while(n  % i == 0)
			{
				n /= i;
			}
		}
		if(n > 1)
		{
			ans = (ans * (n - 1)) / n;
		}
		return ans;
}
 
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << phi(n) << endl;
	}
} 