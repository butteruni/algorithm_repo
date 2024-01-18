#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e6 + 10;
vector<int>e[N];
int val[N];
int vis[N];
int score[N];
bool cmp(int x,int y)
{
    return val[x] < val[y];
}
void dfs(int u,int p)
{
    // cout << u << " ";
    for(auto x:e[u])
    {
        if(x == p)
            continue;
        // vis[x] = 1;
        if(val[x] < val[u])
            continue;
        else 
        {
            if(val[x] == val[u])
            {
                if(score[x] < score[u])
                {
                    score[x] = score[u];
                    dfs(x,u);
                }

            }
            else
            {
                if(score[x] < score[u] + 1)
                {
                    score[x] =  score[u] + 1;
                    dfs(x,u);
                }

            } 
        }
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> val[i];
    for(int i = 1;i <= m;++i)
    {
        int u,v;
        cin >> u >> v;
        if(val[u] <= val[v])
            e[u].push_back(v);
        if(val[v] <= val[u])
            e[v].push_back(u);
    }
    for(int i = 1;i <= n;++i)
    {
        if(e[i].size())
        {
            sort(e[i].begin(),e[i].end(),cmp);
        }
    }
    score[1] = 1;
    vis[1] = 1;
    dfs(1,0);
    cout << score[n] << ' ';
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