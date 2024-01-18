#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
vector<int> e[N];
ll c[N];
ll dp1[N],dp2[N];
ll dep[N];
bool vis[N];
void dfs1(int u,int pa)
{
    for(auto x:e[u])
    {
        dep[x] = dep[u] + 1;
        dfs1(x,u);
    }
}
void dfs2(int u,int pa)
{
    dp1[u] = c[u];
    ll mx = -1e18;
    ll mn = 1e18;
    for(auto x : e[u])
    {
        dfs2(x,u);
        mx = max(mx,max(dp1[x], dp2[x]));
    }
    if(e[u].size())
    {
        dp1[u] = dp1[u] - mx; // 从自己开始
        dp2[u] = max(dp2[u],mx); // 从自己的子孙开始
    }

}
void solve()
{
    int n;
    cin >> n;
    // memset(dp,-0x3f,sizeof(dp));
    for(int i = 1;i <= n;++i)
    {
        e[i].clear();
        dp1[i] = 0;
        dp2[i] = 0;
        dep[i] = 0;
        vis[i] = 0;
    }
    c[1] = 0;
    for(int i = 2;i <= n;++i)
    {
        cin >> c[i];
    }
    for(int i = 2;i <= n;++i)
    {
        int u;
        cin >> u;
        e[u].push_back(i);
    }
    dep[1] = 0;
    // dfs1(1,0);
    // for(int i = 1;i <= n;++i)
    // {
    //     cout << dep[i] << " ";
    // }
    // cout << "\n";
    dfs2(1,0);
    ll ans = 0;
    for(int i = 1;i <= n;++i)
        ans = max(ans,max(dp1[i],dp2[i]));
    cout << ans << "\n";
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