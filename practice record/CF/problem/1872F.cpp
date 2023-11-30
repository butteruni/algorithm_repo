#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N],c[N];
vector<ll>circle[N];
int vis[N];
int in[N];
void dfs1(int u,ll *pos,ll *mx) // 环上最小点
{
    // cout << u << " ";
    if(vis[u])
        return;
    vis[u] = 1;
    if(c[u] < (*mx))
    {
        (*mx) = c[u];
        (*pos) = u;
    }
    for(auto &x:circle[u])
    {
        dfs1(x,pos,mx);
        vis[u] = 0;
    }
}
void dfs2(int u) // 删环
{
	if (vis[u])
	{
		return;
	}
	vis[u] = 1;
	cout << u << ' ';
	for (auto &x : circle[u])
	{
		dfs2(x);
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
        // vis.clear();
        for(int i = 1;i <= n;++i)
        {
            circle[i].clear();
            in[i] = 0;
            vis[i] = 0;
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            in[a[i]]++;
            circle[i].push_back(a[i]);
        }
        for(int i = 1;i <= n;++i)
            cin >> c[i];
        
        queue<int>q;
        for(int i = 1;i <= n;++i)
        {
            if(in[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            cout << tmp << " ";
            for(auto &x:circle[tmp])
            {
                in[x]--;
                if(in[x] == 0)
                {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        for(int i = 1;i <= n;++i)
        {
            ll pos = 0,mx = 1e18;
            if(!vis[i])
            {
                dfs1(i,&pos,&mx);
                // cout << mx << " ";
                vis[i] = 0;
                dfs2(circle[pos][0]);
            }
        }
        cout << '\n';
    }

}