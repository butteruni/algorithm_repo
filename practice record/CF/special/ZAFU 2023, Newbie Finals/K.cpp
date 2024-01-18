#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll mod = 998244353;
const ll N= 2e5 + 10;
ll dp[N];
ll inv[N];
ll qpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    ll inv_n = qpow(n,mod - 2);
    inv[1]=1;
    for(int i = 2;i <= n + 5;++i)
    {
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    }
    ll sum = 0;
    for(int i = n;i >= 1;--i)
    {
        if(i == n)
        {
            dp[n] = 1;
        }else 
        {
            dp[i] = (1 + inv[n - i] * sum) % mod;
        }
        sum = (sum + dp[i]) % mod;
    }
    sum = sum * inv_n % mod;
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    // cout << ((3ll * qpow(2,mod - 2)) % mod) << '\n';
    while(t--)
    {
        solve();
    }
}