#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000;
const ll INF = 1e9;

ll n, m, c, d, obs;
int cnt=1, head[MAXN], s, t;
int dep[MAXN], gap[MAXN], cur[MAXN], lv[MAXN];
char mp[MAXN][MAXN];
ll maxflow;
struct Edge
{
    int to, val, next;
}edge[MAXN<<4];

void addEdge(int from, int to, int val)
{
    edge[++cnt].to = to;
    edge[cnt].val = val;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

// // 反向初始化深度
// void bfs()
// {
//     memset(dep, -1, sizeof(dep));
//     memset(gap, 0, sizeof(gap));
//     queue<int> q;
//     q.push(t);
//     dep[t] = 0;
//     gap[0] = 1;
//     while(!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for(int k = head[u]; k; k = edge[k].next)
//         {
//             int v = edge[k].to;
//             if(dep[v] == -1)
//             {
//                 dep[v] = dep[u] + 1;
//                 ++gap[dep[v]];
//                 q.push(v);
//             }
//         }
//     }
// }

// int dfs(int u, int flow)
// {
//     if(u == t)
//     {
//         maxflow += flow;
//         return flow;
//     }
//     int used = 0;
//     for(int k = cur[u]; k; k = edge[k].next)
//     {
//         cur[u] = k;  // 当前弧优化
//         int v = edge[k].to, vol = edge[k].val;
//         if(vol > 0 && dep[u] == dep[v] + 1)
//         {
//             int c = dfs(v, min(flow - used, vol));
//             edge[k].val -= c;
//             edge[k^1].val += c;
//             used += c;
//             if(used == flow)
//                 return used;
//         }
//     }
//     // used < flow
//     // 当前点已经无法再走
//     --gap[dep[u]];
//     if(gap[dep[u]] == 0)
//         dep[s] = n+1;  // 标记，可直接结束算法
//     ++dep[u];
//     ++gap[dep[u]];
//     return used;
// }
// ll ISAP()
// {
//     maxflow = 0;
//     // 只需一次bfs
//     bfs();
//     while(dep[s] < n)
//     {
//         memcpy(cur, head, sizeof(head));
//         dfs(s, INF);
//     }
//     return maxflow;
// }

bool bfs()
{
    memset(lv, -1, sizeof(lv));
    queue<int> q;
    q.push(s);
    lv[s] = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int k = head[p]; k; k = edge[k].next)
        {
            int to = edge[k].to, val = edge[k].val;
            if(val > 0 && lv[to] == -1)
            {
                lv[to] = lv[p] + 1;
                q.push(to);
            }
        }
    }
    return lv[t] != -1;
}
ll dfs(int p = s, int flow = INF)
{
    if(p == t)
        return flow;
    int rmn = flow;
    for(int k = cur[p]; k && rmn; k = edge[k].next)
    {
        cur[p] = k;
        int to = edge[k].to, val = edge[k].val;
        if(val > 0 && lv[to] == lv[p] + 1)
        {
            int c = dfs(to, min(val, rmn));
            rmn -= c;
            edge[k].val -= c;
            edge[k ^ 1].val += c;
        }
    }
    return flow - rmn;
}
inline ll dinic()
{
    ll ans = 0;
    while(bfs())
    {
        memcpy(cur, head, sizeof(head));
        ans += dfs();
    }
    return ans;
}

void build(ll k)
{
    cnt = 1;
    memset(head, 0, sizeof(head));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
            if(mp[i][j] == '.')
            {
                addEdge(i, j+n+1, 1);
                addEdge(j+n+1, i, 0);
            }
    }
    for(int i = 1; i <= n; ++i)
    {
        addEdge(s, i, k);
        addEdge(i, s, 0);
    }
    for(int j = 1; j <= m; ++j)
    {
        addEdge(j+n, t, k);
        addEdge(t, j+n, 0);
    }
}
ll calc(int val)
{
    build(val);
    ll tmp = dinic();
    ll res = c * val + d * (obs - tmp);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> c >> d;
    s = 0, t = n + m + 10;
    for(int i = 1; i <= n; ++i)
    {
        cin >> mp[i];
        for(int j = 0; j < m; ++j)
            if(mp[i][j] == '.')
                ++obs;
    }

    long long ans = 1e18;
    ll l = 0,r = n + m;
    while(l <= r)
    {
        ll mid = (r - l) / 3;
        ll lmid = l + mid;
        ll rmid = r - mid;
        ll lans = calc(lmid);
        ll rans = calc(rmid);
        if(lans > rans)
        {
            l = lmid + 1;
        }else 
        {
            r = rmid - 1;
            ans = rans;
        }
    }
    cout << ans << '\n';
    return 0;
}
