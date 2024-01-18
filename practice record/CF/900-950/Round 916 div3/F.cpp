#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
vector<int> e[N];
int dep[N];
int cnt[N];
int sz[N];
void dfs(int u,int pa)
{
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dfs(x,u);
            sz[u] += sz[x];
    }
}
int calc(int u,int pa)
{
    int mx = 0;
    for(auto x:e[u])
        mx = max(mx,sz[x]);
    if(mx * 2 > sz[u] - 1)
    {
        for(auto x : e[u])
        {
            if(sz[x] == mx)
            {
                int res = calc(x,u);
                return  res + min((sz[u] - 1 - 2 * res) / 2,sz[u] - 1 - mx); 
            }
        }
    } else 
    {
        return (sz[u] - 1) / 2;
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        dep[i] = 0;
        cnt[i] = 0;
        sz[i] = 1;
        e[i].clear();
    }
    for(int i = 2;i <= n;++i)
    {
        int u;
        cin >> u;
        e[u].push_back(i);
    }
    dfs(1,0);
    cout << calc(1,0) << "\n";

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