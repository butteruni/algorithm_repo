#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10,mod = 998244353;
ll x[N],y[N];
ll n,k;
ll qpow(ll a,ll b,ll c)
{
    ll res = 1ll;
    while(b)
    {
        if(b & 1)
            res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
ll inv(ll a)
{
    return qpow(a, mod - 2,mod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> x[i] >> y[i];
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ll cur = y[i];
        ll temp = 1ll;
        for(int j = 1;j <= n;++j)
        {
            if(j == i)
                continue;
            cur = cur * (k - x[j]) % mod;
            temp = temp * (x[i] - x[j]) % mod;
        }
        ans += cur * inv(temp) % mod;
        // cout << ans << endl;
    }
    cout << (ans % mod + mod) % mod << endl;
}