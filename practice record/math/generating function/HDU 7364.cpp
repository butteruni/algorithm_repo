#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1e6;
ll fac[N + 10],invfac[N + 10];
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
    return fac[n] * invfac[m] % mod*invfac[n - m] % mod;
}
ll n,m,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    // cout << fac[5] << '\n';
    while(t--)
    {
        cin >> n >> m >> k;
        ll ans = 0;
        for(int i = 0;i <= m;++i)
        {
            if(i & 1)
            {
                ans = ((ans - C(m,i) * C(n - i * k - 1,m - 1) % mod) % mod + mod) % mod;
            }else 
            {
                ans = (ans + C(m,i) * C(n - i * k - 1,m - 1) % mod) % mod;
            }
            // cout << ans << " ";
        }
        cout << ((ans * fac[n] % mod) * invfac[m]) % mod<< "\n";
    }
    return 0;
}