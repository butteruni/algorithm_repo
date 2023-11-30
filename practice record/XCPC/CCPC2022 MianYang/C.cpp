#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int p[N],sz[N],dep[N];
bool root[N];
vector<int>e[N];
int depth = 0;
void dfs(int u,int pa)
{
    depth = max(depth,dep[u]);
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dep[x] = dep[u] + 1;
        dfs(x,u);
    }
} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        dep[i] = 0;
        root[i] = 0;
    }
    for(int i = 1;i < n;++i)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(auto x:e[1])
    {
        root[x] = 1;
        // cout << x << "\n";
    }
    int ans = 0;
    for(int i = 1;i <= n;++i)
    {
        if(root[i])
        {   
            depth = 0;
            dep[i] = 1;
            // cout << i <<"  ";
            dfs(i,1);
            ans += depth;
            // cout << depth << " " ;
        }
    }
    cout << ans << '\n';
}