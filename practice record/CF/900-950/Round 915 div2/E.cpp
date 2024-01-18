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
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
ll get_inv(ll val)
{
    return qpow(val,mod - 2);
}
const int N = 65;
map<ll,array<ll,3> >mp;
array<ll,3>calc(ll n)
{
    if(mp.count(n))
        return mp[n];
    if(n == 1)
    {
        return mp[n] = {1,0,1};
    }
    array<ll,3>&res = mp[n];
    auto [kl,bl,cl] = calc((n + 1) / 2);
    auto [kr,br,cr] = calc(n / 2);
    res[0] = (res[0] + kl * 2ll + kr * 2ll + cl * cr) % mod;
    res[1] = (res[1] + bl + br + kr) % mod;
    res[2] = (cl * cr + cl + cr + res[2]) % mod;
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    auto [k,b,c] = calc(n);
    cout << (k + b) % mod << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}