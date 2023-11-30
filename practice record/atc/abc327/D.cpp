#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll ans[N];
ll p[N];
vector<int>e[N + 1];
bool vis[N];
int find(int x)
{
    return x == p[x]? x:p[x] = find(p[x]);
}
void dfs(int u,int pa)
{
    for(auto v : e[u])
    {
        if(v == pa || vis[v])
            continue;
        ans[v] = ans[u] ^ 1;
        vis[v] = 1;
        dfs(v,u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>a(m),b(m);
    for(int i = 1;i <= n;++i)
        p[i] = i;
    for(int i = 0;i < m;++i)
        cin >> a[i];
    bool ok = 1;
    for(int i = 0;i < m;++i)
    {
        cin >> b[i];
        if(a[i] == b[i])
            ok = 0;
    }
    if(!ok)
    {
        cout << "No" << "\n";
    }else 
    {
        for(int i = 0;i < m;++i)
        {
            e[a[i]].push_back(b[i]);
            e[b[i]].push_back(a[i]);
        }
        for(int i = 1;i <= n; ++i)
        {
            if(e[i].size() != 0 && !vis[i])
            {
                vis[i] = 1;
                ans[i] = 0;
                dfs(i,0);
            }
        }
        for(int i = 0;i < m;++i)
        {
            if(ans[a[i]] == ans[b[i]] )
                ok = 0;
        }
        if(!ok)
            cout << "No\n";
        else 
            cout << "Yes\n";
    }
    
}