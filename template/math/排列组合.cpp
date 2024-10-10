#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;
ll fac[N],invfac[N],inv[N];
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
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i) 
        fac[i] = (fac[i - 1] * i) % mod;
    invfac[N - 1] = qpow(fac[N - 1],mod - 2);
    for (int i = N - 2; i >= 0; --i) 
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
}
ll C(int n, int m)
{
    if (n < m || m < 0) return 0;
    return (fac[n] * invfac[m] % mod)*invfac[n - m] % mod;
}
ll A(int n,int m)
{
    if(n < m || m < 0)
        return 0;
    return fac[n] * invfac[n - m] % mod;
}
