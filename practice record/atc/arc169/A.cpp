#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 250000 + 10;
ll a[N];
ll p[N];
vector<ll>e[N];
ll depth[N];
ll sumdepth[N];
ll sum = 0;
ll mx_depth;
void dfs(int u,int pa)
{
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        depth[x] = depth[u] + 1;
        mx_depth = max(mx_depth,depth[x]);
        dfs(x,u);
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        e[i].clear();
    }
    for(int i = 2;i <= n;++i)
    {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    dfs(1,0);
    // cout << sum << " ";
    for(int i = 1;i <= n;++i)
    {
        sumdepth[depth[i]] += a[i];
    }
    for(int i = 1;i <= mx_depth;++i)
    {
        sumdepth[i - 1] += sumdepth[i];
    }
    
    if(sum < 0)
    {
        cout << '-' << '\n';
    }else if(sum == 0)
    {
        if(a[1] == 0)
        {
            cout << "0\n";
        }else if(a[1] < 0)
        {
            cout << "-\n";
        }else if(a[1] > 0)
        {
            cout << "+\n";
        }
    }else
    {
        cout << "+" << '\n';
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