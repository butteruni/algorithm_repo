#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N = 2e5 + 10;
vector<int>e[N];
map<int,int>dis;
map<int,int>mark;
void dfs1(int u,int pa)
{
    if(mark[u])
    {
        dis[u] = 0;
    }
    for(auto ne:e[u])
    {
        if(ne == pa)
            continue;
        dfs1(ne,u);
        dis[u] = max(dis[u],dis[ne] + 1);
    }
}
void dfs2(int pre,int u,int pa)
{
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int k,n;
        dis.clear();
        cin >> n >> k;
        for(int i = 1;i <= n;++i)
        {
            dis[i] = 0x3f3f3f3f;
            e[i].clear();
            mark[i] = 0;
        }
        for(int i = 0;i < k;++i)
        {
            int x;
            cin >> x;
            mark[x] = 1;
        }
        for(int i = 1;i <= n - 1;++i)
        {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v),e[v].push_back(u);
        }   
        
        for(auto [x,val]:dis)
        {
            ans = min(ans,val);
        }
        cout << ans << '\n';
    }
}