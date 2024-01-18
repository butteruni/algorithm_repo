#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
const ll mod = 998244353;
const int N = 3030;
ll p[N];
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
ll dp[N];
ll sum[N];
void solve()
{
    ll n;
    cin >> n;
    dp[1] = 1;
    ll inv_2 = qpow(2,mod - 2);
    p[0] = 1;
    for(int i = 1;i <= n;++i)
    {
        p[i] = p[i - 1] * inv_2 % mod;
    }
    for(int i = 2;i <= n;++i)
    {
        for(int j = 1;j < i;++j)
        {
            dp[i] = (dp[i] + dp[j] * C(i - 1,i - j)) % mod;
        }
        dp[i] = dp[i] * qpow(qpow(2,i) - 1,mod - 2) % mod;
    }
    for(int i = 1;i <= n;++i)
    {
        for(int d = 0;d < i;++d)
        {
            sum[i] = (sum[i] + dp[n - d] * C(i - 1,d)) % mod;
        }
        sum[i] = (sum[i] * p[i - 1]) % mod;
    }
    for(int i = 1;i <= n;++i)
    {
        cout << sum[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}