#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
typedef long long ll;
#define lc tr[x].s[0]
#define rc tr[x].s[1]
ll n,m,p,t;
ll tim[N];
struct Node
{
    int s[2],siz,f;
    ll sum,v,mul;
	int rev;
}tr[N];
ll stk[N];
inline void pushrev(int x)
{
    swap(lc,rc);
    tr[x].rev ^= 1;   
}
inline void pushmul(int x,ll k)
{
	tr[x].mul = tr[x].mul * k % p;
	tr[x].sum = tr[x].sum * k % p;
	tr[x].v = tr[x].v * k % p;
}
inline void pushup(int x)
{
	tr[x].siz = 1 + tr[lc].siz + tr[rc].siz;
    tr[x].sum = (tr[lc].sum + tr[rc].sum + tr[x].v) % p;
}
inline void pushdown(int x)
{
    if(tr[x].rev)
    {
        pushrev(lc);
        pushrev(rc);
        tr[x].rev = 0;
    }
	if(tr[x].mul != 1)
	{
		if(rc)
		{
			pushmul(rc, tr[x].mul);
		}
		if(lc)
		{
			pushmul(lc, tr[x].mul);
		}
		tr[x].mul = 1;
	}
}
inline bool is_root(int x)
{
    return tr[tr[x].f].s[0] != x && tr[tr[x].f].s[1] != x;
}
inline void rotate(int x)
{
    int y = tr[x].f,z = tr[y].f;
    int k = tr[y].s[1] == x;
    tr[x].f = z;
    if(!is_root(y))
    {
        tr[z].s[tr[z].s[1] == y] = x;
    }
    tr[y].s[k] = tr[x].s[1 - k],tr[tr[x].s[1 - k]].f = y;
    tr[x].s[1 - k] = y,tr[y].f = x;
    pushup(y),pushup(x);
}
inline void splay(int x)
{
    int top = 0, r = x;
    stk[++top] = r;
    while(!is_root(r))
    {
        stk[++top] = r = tr[r].f;
    }
    while(top)
    {
        pushdown(stk[top--]);
    }
    while(!is_root(x))
    {
        int y = tr[x].f,z = tr[y].f;
        if(!is_root(y))
        {
            if((tr[y].s[1] == x) == (tr[z].s[1] == y))
            {
                rotate(y);
            }else  
            {
                rotate(x);
            }
        }
        rotate(x);
    }
    pushup(x);
}
inline void access(int x) //建立一条根到x的路径，并将x变为splay根节点
{
    for(int y = 0;x;y = x,x = tr[x].f)
    {
        splay(x);
        rc = y;
        pushup(x);
    }
}
inline void make_root(int x) //将x变成原树的根节点
{

    access(x);
    splay(x);
    pushrev(x);
}
inline int find_root(int x) 
{
    access(x);
    splay(x);
    while(lc)
    {
        pushdown(x);
        x = lc;
    }
    splay(x);
    return x;
}
inline void split(int x,int y)
{
    make_root(x);
    access(y);
    splay(y);
}
inline void link(int x,int y)
{
    make_root(x);
    make_root(y);
    tr[x].f = y;
    // pushup(y);
}
inline void cut(int x,int y)
{
    make_root(x);
    if(find_root(y) == x && tr[y].f == x && !tr[y].s[0])
    {
        tr[x].s[1] = tr[y].f = 0;
        pushup(x);
    }
}
inline int get_idx(int x,int k)
{
	if(!rc && !lc)
		return x;
	if(tr[lc].siz + 1 == k)
		return x;
	pushdown(x);
	if(tr[lc].siz + 1 < k)
	{
		return get_idx(rc, k - tr[lc].siz - 1);
	}
	return get_idx(lc, k);
}
inline void update(int x,int l,int r,ll k)
{
	split(1, x);
	int LL = get_idx(x,l + 1),RR = get_idx(x, r + 1);
	split(LL, RR);
	pushmul(RR, k);
}
inline ll get_sum(int x,int l,int r)
{
	split(1, x);
	int LL = get_idx(x,l + 1);
    int RR = get_idx(x,r + 1);
	split(LL, RR);
	return tr[RR].sum;
}
int pre[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> m >> p >> t;
	ll prea = 0;
	int u = 1;
    int op;
	n = 1,tr[n].mul = 1;
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
            int a = tr[j].f;
		cin >> op;
        if(op == 1)
        {
			ll x;
			cin >> x;
			if(t)
			{
				x ^=  prea;
			}
			if(x == 0)
			{
				u = pre[u];
			}else 
			{
				++n;
				tr[n].v = x,tr[n].sum = x,tr[n].mul = 1;
				pre[n] = u;
				link(n, u);
				u = n;
                // cout << tr[n].f << endl;
			}
			tim[i] = u;
        }else if(op == 2)
		{
			ll x,l,r,k;
			cin >> x >> l >> r >> k;
            if(t)
                k ^= prea;
			update(tim[x], l, r, k);
			tim[i] = tim[i - 1];
		}else
		{
			ll x,l,r;
			cin >> x >> l >> r;
			prea = get_sum(tim[x], l, r) % p;
			cout << prea << '\n';
            tim[i] = tim[i - 1];
		}
    }
    return 0;
}
