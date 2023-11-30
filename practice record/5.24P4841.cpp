#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 130000 + 10;
const ll MOD = 1004535809;
int n,len;
ll inv[N],fac[N],ifac[N];
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void NTT(ll *a,int type,int len)
{
    for(int i = 0;i < len;++i)
        if(i < r[i])
            swap(a[i],a[r[i]]);
    for(int mid = 1;mid < len;mid <<= 1)
    {
        ll wn = 1;
        if(type == 1)
            wn = qpow(g,(MOD - 1) / (mid << 1));
        else
            wn = qpow(invg,(MOD - 1) / (mid << 1));
        for(int i = 0;i < len;i += (mid << 1))
        {
            for(int j = 0,w0 = 1;j < mid;++j,w0 = 1ll * w0 * wn % mod)
            {
                ll x = a[i + j], y = w0 * a[i + j + mid] % mod;
                a[i + j] = (x + y) % mod;
                a[i + j + mid] = (x - y + mod) % mod; 
            }
        }
    }
}
void init()
{
    inv[0] = inv[1] = 1;
    fac[1] = 1;
    for(int i = 1;i < N ;++i)
    {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for(int i = 2;i < N;++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
}