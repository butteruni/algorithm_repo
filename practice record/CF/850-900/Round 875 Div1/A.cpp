#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 10;
bool vis[N];
int e[N << 1], ne[N << 1], h[N], pre[N];
ll cnt[N];
int idx;
void add(int a, int b, int id)
{
    e[idx] = b;
    ne[idx] = h[a];
    pre[idx] = id;
    h[a] = idx++;
}
void dfs(int u, int id)
{
    vis[u] = 1;
    for(int i = h[u];i != -1;i = ne[i])
    {
        int x = e[i];
        if(!vis[x])
        {
            cnt[x] = cnt[u] + (pre[i] < id);
            dfs(x,pre[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        idx = 0;
        cin >> n;
        for (int i = 0; i <= n; ++i)
        {
            vis[i] = 0;
            h[i] = -1;
        }
        // cnt[1] = 0;
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            add(u,v,i);
            add(v,u,i);
        }
        dfs(1,2 * n);
        // for(int i = 1;i <= n;++i)
        //     cout << cnt[i] << " ";
        cout << *max_element(cnt + 1, cnt + n + 1) << '\n';
    }
}
