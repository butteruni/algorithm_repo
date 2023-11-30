#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
typedef pair<ll,ll>PLL;
map<ll,ll>mp[60];
unordered_map<ll,ll>vis;
ll sum(ll f,ll val)
{
    // auto x = make_pair(f,val);
    if(mp[f].count(val))
        return mp[f][val];
    ll res = 0;
    ll l = 1,r;
    for(ll i = 1;i <= 60;++i) // 分块求和
    {
        // r = l * f;
        if((__int128_t)l * f > (__int128_t)val)
            break;
        l *= f;
        r = min((__int128_t)l * f - 1,(__int128_t)val);
        res = (res + (__int128_t)i * (r - l + 1) % mod) % mod;
    }
    return mp[f][val] = res;
}
ll calc(ll val) // 枚举f
{
    if(vis.count(val))
        return vis[val];
    ll ans = 0;
    for(ll i = 2;i <= 60;++i)
    {
        ll l = (1ll << i),r = (1ll << (i + 1)) - 1;
        if(l > val)
            break;
        r = min(r,val);
        ans = ((ans + sum(i, r)) % mod + mod) % mod;
        ans = ((ans - sum(i, l - 1)) % mod + mod) % mod;
    }
    return vis[val] = ans ;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (calc(r) - calc((l - 1)) % mod + mod) % mod << '\n';
    }   
}