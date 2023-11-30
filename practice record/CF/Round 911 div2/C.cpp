#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  N= 3e5 + 10;
ll l[N],r[N];
vector<int>e[N];
map<int,int>vis;
bool ok[N];
ll dp[N];
string s;
void dfs(int u,int pa)
{
    vis[u] = 1;
    if(l[u] == 0 && r[u] == 0)
    {
        ok[u] = 1;
        dp[u] = 0;
    }
    for(auto x:e[u])
    {
        if(x == 0 || x == pa || vis[x])
            continue;
        dfs(x,pa);
        if(ok[x])
        {
            if(x == l[u])
            {
                if(s[u] == 'L')
                    dp[u] = min(dp[u],dp[x]);
                else 
                    dp[u] = min(dp[u],dp[x] + 1);
            }else 
            {
                if(s[u] == 'R')
                {
                    dp[u] = min(dp[u],dp[x]);
                }else 
                {
                    dp[u] = min(dp[u],dp[x] + 1);
                }
            }
            ok[u] = 1;
        }
    }
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cin >> s;
        s = " " + s;
        // leaf.clear();
        vis.clear();
        for(int i = 1;i <= n;++i)
        {
            dp[i] = 0x3f3f3f3f3f;
            e[i].clear();
            ok[i] = 0;
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> l[i] >> r[i];
            e[l[i]].push_back(i);
            e[r[i]].push_back(i);
            e[i].push_back(l[i]);
            e[i].push_back(r[i]);
            if(l[i] == 0 && r[i] == 0)
            {
                ok[i] = 1;
                dp[i] = 0;
            }
        }
        dfs(1,0);    
        cout << dp[1] << '\n';
    }
}