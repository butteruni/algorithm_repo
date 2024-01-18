#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll mod = 998244353;
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
    return res;
}
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        ll x;
        cin >> x;
        sum += x;
        sum %= mod;
    }
    sum = sum * qpow(n, mod - 2);
    sum %= mod;
    for(ll i = 1;i <= n;++i)
    {
        cout << ((sum * i) % mod )<< " ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}