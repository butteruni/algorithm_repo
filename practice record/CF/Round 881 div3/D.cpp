#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int t;
ll n,q;
ll ans;
int e[N << 1],ne[N << 1],h[N],idx,g[N];
ll cnt[N];
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a] ,h[a] = idx++;
}
bool vis[N];
void dfs(int cur,int fa)
{
    if(g[cur] == 1 && cur != 1)
    {
        cnt[cur] = 1;
    }
    for(int i = h[cur]; i != -1;i = ne[i])
    {
        int j = e[i];
        if(j == fa)
            continue;
        dfs(j,cur);
        cnt[cur] += cnt[j];
    }
} 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        memset(h,-1,sizeof(h));
        memset(g,0,sizeof(g));
        memset(cnt,0,sizeof(cnt));
        cin >> n;
        for(int i = 1;i < n;++i)
        {
            int u,v;
            cin >> u >>v ;
            add(u,v);
            add(v,u);
            g[u]++,g[v]++;
        }
        dfs(1,0);
        cin >> q;
        for(int i = 1;i <= q;++i)
        {
            int x,y;
            cin >> x >> y;
            cout << cnt[x] * cnt[y] << '\n';
        }
        // for(int i = 1;i <= n;++i)
        //     cout << cnt[i] << " ";
        // cout << "\n";
    }
}