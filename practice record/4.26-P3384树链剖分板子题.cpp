#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int sum[N << 2],laz[N << 2];
int n,m,r,mod;
int son[N],id[N],fa[N],cnt,dep[N],siz[N],top[N];
int w[N],wt[N];
int ans;
int e[N],ne[N],h[N],idx;

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a] ,h[a] = idx++;
}
void pushup(int x)
{
    sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % mod;
}
void pushdown(int x,int len)
{
    // cout << x << "|" << endl;
    if(laz[x])
    {
        laz[x << 1] += laz[x];
        laz[x << 1 | 1] += laz[x];
        sum[x << 1] = (sum[x << 1] + laz[x] * (len - (len >> 1))) % mod;
        sum[x << 1 | 1] = (sum[x << 1 | 1] + laz[x] * (len >> 1)) % mod;;
        laz[x] = 0;
    }
    return;
}
void build(int l,int r,int x)
{
    laz[x] = 0;
    if(l == r)
    {
        sum[x] = wt[l];
        sum[x] %= mod;
        return;
    } 
    int mid = (l + r) >> 1;
    build(l,mid,x << 1);
    build(mid + 1, r, x << 1 | 1);
    pushup(x);
}
void update(int L,int R,int c,int l,int r,int x)
{
    if(L <= l && r <= R)
    {
        laz[x] += c;
        sum[x] = (sum[x] + c * (r - l + 1)) % mod;
        return;
    }
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    if(L <= mid)
        update(L,R,c,l,mid,x << 1);
    if(R > mid)
        update(L,R,c,mid + 1,r,x << 1 | 1);
    pushup(x);
}
void query(int L,int R,int l,int r,int x)
{
    if(L <= l && r <= R)
    {
        ans = (ans + sum[x]) % mod;
        return;
    }
// cout << L << "--" << R << "--" << l << "--" << r << endl;
    pushdown(x, r - l + 1);
    int mid = (l + r) >> 1;
    if(L <= mid)
        query(L,R,l,mid,x << 1);
    if(R > mid)
        query(L,R,mid + 1, r,x << 1 | 1);
}
void dfs1(int x,int f,int depth)
{
    dep[x] = depth;
    fa[x] = f;
    siz[x] = 1;
    int maxson = -1;
    for(int i = h[x];i != -1;i = ne[i])
    {
        int j = e[i];
        if(j == f)
            continue;
        dfs1(j,x,depth + 1);
        siz[x] += siz[j];
        if(siz[j] > maxson)
        {
            son[x] = j;
            maxson = siz[j];
        }
    }
}
void dfs2(int x,int topf)
{
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = topf;
    if(!son[x])
        return;
    dfs2(son[x],topf);
    for(int i = h[x];i != -1;i = ne[i])
    {
        int j = e[i];
        if(j == fa[x] || j == son[x])
            continue;
        dfs2(j,j);
    }
}
void uprange(int x,int y,int k)
{
    k %= mod;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x,y);
        update(id[top[x]], id[x],k,1,n,1);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    update(id[x],id[y],k,1,n,1);
}
int qrange(int x,int y)
{
    int res = 0;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans = 0;
        query(id[top[x]],id[x],1,n,1);
        res = (res + ans) % mod;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    ans = 0;
    query(id[x],id[y],1,n,1);
    res = (res + ans) % mod;
    return res;
}
void upson(int x,int k)
{
    update(id[x],id[x] + siz[x] - 1,k,1,n,1);
}
void qson(int x)
{
    ans = 0;
    query(id[x],id[x] + siz[x] - 1,1,n,1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    memset(h,-1, sizeof(h));
    cin >> n >> m >> r >> mod;
    for(int i = 1;i <= n;++i)   
        cin >> w[i];
    for(int i = 1;i < n;++i)
    {
        int x,y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }    
    dfs1(r,0,1);
    dfs2(r,r);
    build(1,n,1);
    // for(int i = 1;i <= n;++i)
    //     cout << top[i] << endl;
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x,y,z;
            cin >> x >> y >> z;
            uprange(x,y,z);
        }else if(op == 2)
        {
            int x,y;
            cin >> x >> y;
            cout << qrange(x,y) << "\n";
        }else if(op == 3)
        {
            int x,z;
            cin >> x >> z;
            upson(x,z);
        }else if(op == 4)
        {
            int x;
            cin >> x;
            qson(x);
            cout << ans << "\n";
        }
    }
    return 0;
}