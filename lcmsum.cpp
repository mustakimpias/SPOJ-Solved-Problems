#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll n = 1e6+2;
vector <ll> numCp(n + 1);
vector <ll> isPrime(n + 1);
vector <ll> LcmSum(n + 1);

void CoPrime()
{
    for(ll i = 1; i <= n; i++)
        numCp[i] = i;
    for(ll i = 2; i <= n; i += 2)
        numCp[i] /= 2;
    for(ll i = 3; i <= n; i += 2)
    {
        if(isPrime[i] == 0)
        {
            numCp[i] -= 1;
            for(ll j = i * 2; j <= n; j += i)
            {
                isPrime[j] = 1;
                numCp[j] = (numCp[j] * (i - 1)) / i;
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i; j <= n; j += i)
        {
            LcmSum[j] += i * numCp[i];
        }
    }
}

int main()
{
    CoPrime();
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", ((LcmSum[n] + 1) * n) / 2);
    }
    return 0;
}