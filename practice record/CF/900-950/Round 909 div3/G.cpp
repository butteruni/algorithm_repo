#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<int>e[N];
int tr[N];
int in[N],out[N];
int n,q;
int idx;
struct node
{
    int pos,i,tag;
};
int lowbit(int x)
{
    return x & (-x);
}
void update(int x,int val)
{
    for(int i = x;i <= n;i += lowbit(i))
        tr[i] += val;
}
int query(int x)
{
    int res = 0;
    for(int i = x;i ;i -= lowbit(i))
        res += tr[i];
    return res;
}
void dfs(int u,int pa)
{
    in[u] = ++idx;
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dfs(x,u);
    }
    out[u] = idx; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        idx = 0;
        for(int i = 0;i <= n;++i)
        {
            e[i].clear();
            in[i] = out[i] = 0; // in表示进入子树，out表示出去
            tr[i] = 0;
            
        }
        // for(int i = 0;i < n;++i)
        for(int i = 1;i < n;++i)
        {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,-1);
        vector<int>p(n + 1);
        for(int i = 1;i <= n;++i)
            cin >> p[i];
        vector<vector<node> >qu(n + 1);
        vector<array<int,2> >ans(q);
        for(int i = 0;i < q;++i)
        {
            int l,r,x;
            cin >> l >> r >> x;
            qu[l - 1].push_back(node{x,i,0});
            qu[r].push_back(node{x,i,1});
        }
        for(int i = 1;i <= n;++i)
        {
            update(in[p[i]],1);
            for(auto x:qu[i])
            {
                ans[x.i][x.tag] = query(out[x.pos]) - query(in[x.pos] - 1);
            }
        }
        for(auto [x,y]:ans) 
        {
            if(x != y)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        cout << '\n';
    }
}