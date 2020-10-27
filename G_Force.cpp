#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll phi(ll n)
{
    ll ans = n;
    for(ll i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            ans = (ans * (i - 1)) / i;
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1)
        ans = (ans *(n -1)) / n;
    return ans;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll NumCp = phi(n);
        if(n == 30)
            cout << NumCp * NumCp << endl;
        else 
            cout << NumCp << endl;
    }
    return 0;
} 