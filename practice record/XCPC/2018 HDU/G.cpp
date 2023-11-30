#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1e6 + 10;
const int MX = 1e6;
ll fac[N];
ll inv[N];
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res % mod;
}
void init()
{
    ll p = 1;
    fac[1] = inv[1] = 1;
    fac[0] = inv[0] = 1;
    for(ll i = 2;i <= MX;++i)
    {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[MX] = qpow(fac[MX],mod - 2);
    for(ll i = MX - 1;i >= 2;++i)
    {
        inv[i] = (inv[i + 1] * i) % mod;
    }  
}
ll C(int n, int m)
{
    if (n < m || m <= 0) return 0;
    return (fac[n] * inv[m] % mod)*inv[n - m] % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        for(int i = 0;i <= n;++i)
        {
            if(i & 1)
            {
                ans = ans - (C(n,i) * )
            }else 
            {

            }
        }
    }
}