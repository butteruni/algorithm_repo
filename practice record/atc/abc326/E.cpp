#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 3e5 + 10;
ll dp[N];
ll sum[N];
ll a[N];
map<ll,ll>cnt;
map<ll,ll>vis;
ll pre[N];
ll qpow(ll a,ll b)
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    // vector<ll>a(n + 1);
    ll ans = 0;
    ll p = qpow(n ,mod - 2);
    ll inv_n = p;
    // ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        ans = (ans + a[i] * p) % mod;
        p = (p + inv_n * p) % mod;
    }
    cout << ans << '\n';

}