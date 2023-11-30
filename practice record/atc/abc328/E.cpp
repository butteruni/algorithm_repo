#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
struct Edge
{
    ll u,v;
    ll w;
}e[N<<2];
int f[N];
int find(int x)
{
    return x == f[x]?x : find(f[x]);
}
void merge(ll x,ll y)
{
    ll px = find(x),py = find(y);
    f[px] = py; 
}
ll n,m,k;
ll ans;
void dfs(ll pos,ll cnt,ll w)
{
    if(cnt == n - 1)
    {
        // cout << w << '\n';
        ans = min(ans,w);
        return ;
    }
    for(ll i = pos + 1;i <= m;++i)
    {
        ll px = find(e[i].u),py = find(e[i].v);
        if(px == py)
            continue;
        merge(e[i].u,e[i].v);
        dfs(i,cnt + 1,(w + e[i].w) % k);
        f[px] = px;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ans = 1e18;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;++i)
        f[i] = i;
    for(int i = 1;i <= m;++i)
    {
        ll u,v,cost;
        cin >> u >> v >> cost;
        e[i].u = u,e[i].v = v;
        e[i].w = cost;
        e[i].w %= k;
    }
    // ll ans = 1e18;
    dfs(0,0,0);
    cout << ans << '\n';

}