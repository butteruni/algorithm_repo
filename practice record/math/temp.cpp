#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll mod = 998244353;
const ll g = 3,invg = 332748118;
ll fac[N],invfac[N],inv[N];
ll rev[N];
ll n,m,k;
ll s[N],res[N];
void get_rev(ll p)
{
    for(int i = 1;i < (1 << p);i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((1 & 1) << (p - 1));
    }
}
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
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; ++i) 
        fac[i] = (fac[i - 1] * i) % mod;
    invfac[N - 1] = qpow(fac[N - 1],mod - 2);
    for (int i = N - 2; i >= 0; --i) 
    {
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
}
ll C(int n, int m)
{
    if (n < m || m < 0) return 0;
    return (fac[n] * invfac[m] % mod)*invfac[n - m] % mod;
}
void NTT(ll* a,ll len,ll type)
{
    for(int i = 0;i < len;++i)
        if(i < rev[i])
            swap(a[i],a[rev[i]]);
    for(int mid = 1;mid < len;mid <<= 1)
    {
        ll wn = 1;
        if(type == 1)
            wn = qpow(g,(mod - 1) / (mid << 1));
        else
            wn = qpow(invg,(mod - 1) / (mid << 1));
        for(int i = 0;i < len;i += (mid << 1))
        {
            for(int j = 0,w0 = 1;j < mid;++j,w0 = 1ll * w0 * wn % mod)
            {
                ll x = a[i + j], y = w0 * a[i + j + mid] % mod;
                a[i + j] = (x + y + mod) % mod;
                a[i + j + mid] = (x - y + mod) % mod; 
            }
        }
    }
    if(type == -1)
    {
        ll w = qpow(len,mod - 2);
        for(int i = 0;i < len;++i)
        {
            a[i] = (a[i] * w) % mod;
        }
    }
}
void poly_qpow(ll x,int len)
{
    while(x)
    {
        if(x & 1)
        {
            NTT(s,len,1);
            NTT(res,len,1);
            for(int i = 0;i < len;++i)
            {
                res[i] = res[i] * s[i] % mod;
            }
            NTT(res,len,-1);
            for(int i = k + 1;i < len;++i)
                res[i] = 0;
            cout << res[k] << "\n";
        }else 
        {
            NTT(s,len,1);
        }
        for(int i = 0;i < len;++i)
        {
            s[i] = (s[i] * s[i]) % mod;
        }
        NTT(s,len,-1);
        for(int i = k + 1;i < len;++i)
            s[i] = 0;
        // cout << s[k] << " ";
        x >>= 1;
    }
}
int main()
{
    init();
    cin >> n >> m >> k;
    ll len = 1,p = 0;
    for(p = 0;len <= 2 * k;len <<= 1,p++);
    get_rev(p);
    for(int i = 0;i <= k;i += 2)
    {
        s[i] = C(n ,i);
    }
    res[0] = 1;
    poly_qpow(m,len);
    cout << (res[k] * qpow(2,m)) % mod << "\n";
}