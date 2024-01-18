#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
const ll N = 2e5 + 10;
const ll mod = 998244353;
ll a[N];
struct Tree
{
    int l, r;
    ll sum;
    ll lz;
    ll lz_v;
} tr[N * 4];
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        b /= 2;
    }
    return res;
}
void pushup(int p)
{
    tr[p].sum = tr[ls(p)].sum + tr[rs(p)].sum;
}

void pushdown(int p,int v,int x,ll inv_v)
{
    auto &root = tr[p], &left = tr[ls(p)], &right = tr[rs(p)];
    if (root.lz)
    {
        left.lz |= root.lz;
        left.sum = (ll) ((v - 1ll) * inv_v * left.sum + x) % mod;;
        right.lz |= root.lz;
        right.sum = (ll) ((v - 1ll) * inv_v * right.sum + x) % mod;;
        root.lz = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r};
    if (l == r)
    {
        tr[p] = {l, r, a[r], 0};
        return;
    }
    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}

void modify(int p, int l, int r, int v,int x,ll inv_v)
{
    if (tr[p].l >= l && tr[p].r <= r)
    {
        tr[p].sum = ((v - 1ll) * inv_v * tr[p].sum + x) % mod;
        tr[p].lz = 1;
        return;
    }
    pushdown(p,v,x,inv_v);
    tr[p].lz = 1;
    int mid = tr[p].l + tr[p].r >> 1;
    if (l <= mid)
        modify(ls(p), l, r, v,x,inv_v);
    if (r > mid)
        modify(rs(p), l, r, v,x,inv_v);
    pushup(p);
}

ll query(int p, int l, int r)
{
    if (tr[p].l >= l && tr[p].r <= r)
        return tr[p].sum;
    pushdown(p); // 要在前面pushdown
    int mid = tr[p].l + tr[p].r >> 1;
    ll res = 0;
    if (l <= mid)
        res += query(ls(p), l, r);
    if (r > mid)
        res += query(rs(p), l, r);
    return res;
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
    {
        a[i] += a[i - 1];
    }
    for(int i = 1;i <= m;++i)
    {
        
    }
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