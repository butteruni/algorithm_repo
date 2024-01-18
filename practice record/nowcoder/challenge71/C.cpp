#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
vector<ll> e[N];
ll dis[N][2];
ll pre[N];
void dfs1(int u,int pa)
{
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        pre[x] = u;
        dfs1(x, u);
        dis[u][0] = max(dis[u][0],1 + dis[x][0]);

    }

}
void dfs2(int u,int pa)
{
    int v = 0;
    dis[u][1] = dis[pa][1];
    for(auto x:e[u])
    {
        if(x == pre[u])
            continue;
        if(x == u)
            v = 1;
        else 
            dis[u][1] = max(dis[u][1],dis[x][0] + 1);
    }
    dis[u][1] += v;
    for(auto x:e[u])
    {   
        if(x == pa)
            continue;
        dfs2(x,u);
    }
}
void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n + m;++i)
    {
        pre[i] = 0;
        e[i].clear();
        dis[i][0] = 0;
        dis[i][1] = 0;
    }
    for(int i = 1;i < n + m - 1;++i)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    dfs1(1,0);    
    dfs2(1,0);

    dfs1(n + 1,0);

    dfs2(n + 1,0);

    ll sum = 0;
    ll ans = 0;
    for(int i = 1; i <= n;++i)
    {
        sum += max(dis[i][1],dis[i][0]);
    }
    cout << sum << endl;
    for(int i = n + 1;i <= n + m;++i)
    {
        ans += sum + (n * max(dis[i][1],dis[i][0]) + n);
    }
    cout << ans << '\n';
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