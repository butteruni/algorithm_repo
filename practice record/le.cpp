#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int N = 4e6 + 1000;
struct Mat
{
    ll a[2][2];
    Mat()
    {
        memset(a,0,sizeof(a));
    }
    void init(ll x1,ll x2,ll y1,ll y2)
    {
        a[0][0] = x1;
        a[0][1] = x2;
        a[1][0] = y1;
        a[1][1] = y2;
    }
    void reverse()
    {
        swap(a[0][0],a[1][1]);
        swap(a[1][0],a[0][1]);
    }
    Mat operator*(const Mat &b)
    {
        Mat res;
        for(int i = 0;i < 2;++i)
        {
            for(int j = 0;j < 2;++j)
            {
                for(int k = 0;k < 2;++k)
                {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j])% mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for(int i = 0 ;i < 2;++i)
        {
            for(int j = 0;j < 2;++j)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
Mat tr[N],add1,add2,unit;
string s;
bool tag[N];
int n,q;
void pushup(int u)
{
    assert(u < N * 6);
    tr[u] = tr[u << 1] * tr[u << 1 | 1];
}
void pushdown(int u)
{
    // cout << u << " ";
    if(tag[u])
    {
        tr[u << 1].reverse();
        tr[u << 1 | 1].reverse();
        tag[u << 1] ^= 1;
        tag[u << 1 | 1] ^= 1;
        tag[u] ^= 1;
    }
}
void update(int u,int l,int r,int ll,int rr)
{
    // cout << u << endl;
    // cout << u << " ";
    if(ll <= l && r <= rr)
    {
        tag[u] ^= 1;
        tr[u].reverse();
        return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if(ll <= mid)
        update(u << 1,l,mid,ll,rr);
    if(rr > mid)
        update(u << 1 | 1,mid + 1,r,ll,rr);
    pushup(u);
}
void build(int u,int l,int r)
{
    // cout << u << " ";
    if(l == r)
    {
        if(s[l] == '1')
            tr[u] = add1;
        else 
            tr[u] = add2;
        return ;
    }   
    int mid = (l + r) >> 1;
    build(u << 1,l,mid);
    build(u << 1 | 1,mid + 1,r);
    pushup(u);
}
Mat query(int u,int l,int r,int ll,int rr)
{
    // cout << u << " ";
    if(ll <= l && r <= rr)
    {
        return tr[u];
    }
    pushdown(u);
    int mid = l + r >> 1;
    Mat res = unit;
    if(ll <= mid)
        res = res * query(u << 1,l,mid ,ll, rr);
    if(rr > mid)
        res = res * query(u << 1 | 1,l, mid + 1,ll,rr);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    ll a1,a2,b1,b2;
    // cout << n << " ";
    cin >> a1 >> a2 >> b1 >> b2;
    cin >> s;
    s = " " + s;
    unit.init(1,0,0,1);
    add1.init(1,0,1,1);
    add2.init(1,1,0,1);
    Mat ans;
    ans.init(a1,a2,b1,b2);
    build(1,1,n);

    for(int i = 1;i <= q;++i)
    {
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 1)
        {
            update(1,1,n,l,r);
        }else 
        {
            Mat res = query(1,1,n,l,r);
            // cout << res.a[0][0] << '\n';
            res = ans * res;

            cout << (res.a[0][0] * res.a[1][0] % mod - res.a[0][1] * res.a[1][1] % mod + mod) % mod << '\n';
        }
    }
}