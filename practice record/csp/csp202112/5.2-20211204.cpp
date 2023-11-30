#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define un_blocked 0
#define blocked 1
#define freed 2
#define multi 2000000020

const int N = 200005;
struct node
{
    ll l, r,val,id,st;
}tr[N << 4]; 
struct op
{
    int type;
    ll id,p,x,l,r;
}ops[N << 2];
int id[N << 2];
ll a[N << 2];
int n,m,k,cnt;
void pushup(int x)
{
    if(tr[x << 1].id == tr[x << 1 | 1].id)
        tr[x].id = tr[x << 1].id;
    else 
        tr[x].id = multi;
    if(tr[x << 1].val == tr[x << 1 | 1].val)
        tr[x].val = tr[x << 1].val;
    else 
        tr[x].val = multi;
    if(tr[x << 1].st == tr[x << 1 | 1].st)
        tr[x].st = tr[x << 1].st;
    else 
        tr[x].st = multi;
}
void pushdown(int x)
{
    if(tr[x].l == tr[x].r)
        return;
    if(tr[x].id != multi)
    {
        tr[x << 1].id = tr[x << 1 | 1].id = tr[x].id;
    }
    if(tr[x].val != multi)
    {
        tr[x << 1].val = tr[x << 1 | 1].val = tr[x].val;
    }
    if(tr[x].st != multi)
    {
        tr[x << 1].st = tr[x << 1 | 1].st = tr[x].st;
    }
}
void build(int x,int l,int r)
{
    tr[x].l = l,tr[x].r = r;
    if(l == r)
    {
        return;
    }else 
    {
        int mid = l + r >> 1;
        build(x << 1,l,mid),build(x << 1 | 1,mid + 1, r);
        pushup(x);
    }
}
int write_check(int x,int l,int r,int id)
{
    if(tr[x].st == un_blocked || tr[x].id == id || tr[x].st == freed)//整个区间可直接写入或已经写完
        return tr[x].r;
    else if(tr[x].st == blocked && tr[x].id != multi)//全被占用
        return -1;
    else
    {
        int mid = tr[x].l + tr[x].r >> 1;
        pushdown(x);
        int r1 = 0,r2 = 0;
        if(l <= mid) //从左子树开始写
        {
            r1 = write_check(x << 1,l,r,id); 
            if(r1 < mid) //写不完左边
                return r1;
            else 
            {
                r2 = write_check(x << 1 | 1,l,r,id);
                if(r2 == -1)
                    return r1;
                else 
                    return r2;
            }
        }else //从右子树开始写
        {
            return write_check(x << 1 | 1,l,r,id);
        }
    }
}
void write(int x,int l,int r,int val,int id)
{
    // cout << tr[x].l << ' ' << tr[x].r << ' ' << r << "|";
    if(tr[x].l == l && tr[x].r == r)
    {
        tr[x].st = blocked;
        tr[x].id = id;
        tr[x].val = val;
        return;
    }
    int mid = tr[x].l + tr[x].r >> 1;
    pushdown(x);
    if(l <= mid)
        write(x << 1,l,min(mid,r),val,id);
    if(r > mid)
        write(x << 1 | 1,max(mid + 1,l),r,val,id);
    pushup(x);
}
bool delet_check(int x,int l,int r,int id)
{
    if(tr[x].l == l && tr[x].r == r)
    {
        if(tr[x].st == blocked && tr[x].id == id)
            return true;
        else 
            return false;
    }
    int mid = tr[x].l  + tr[x].r >> 1;
    pushdown(x);
    bool success = 1;
    if(l <= mid)
        success &= delet_check(x << 1,l,min(mid,r),id);
    if(r > mid)
        success &= delet_check(x << 1 | 1,max(mid + 1,l),r,id);
    pushup(x);
    return success;
}
void delet(int x,int l,int r,int id)
{
    if(tr[x].l == l && tr[x].r == r)
    {
        tr[x].st = freed;
        return;
    }
    int mid = tr[x].l + tr[x].r >> 1;
    pushdown(x);
    if(l <= mid)
        delet(x << 1,l,min(mid,r),id);
    if(r > mid)
        delet(x << 1 | 1,max(mid + 1,l),r,id);
    pushup(x);
}
bool resume_check(int x,int l,int r,int id)
{
    if(tr[x].l == l && tr[x].r == r)
    {
        return tr[x].id == id && tr[x].st == freed;
    }
    int mid = tr[x].l  + tr[x].r >> 1;
    pushdown(x);
    bool success = 1;
    if(l <= mid)
        success &= resume_check(x << 1,l,min(r,mid),id);
    if(r > mid)
        success &= resume_check(x << 1 | 1,max(mid + 1, l),r,id);
    return success;
}
void resume(int x,int l,int r,int id)
{
    if(tr[x].l == l && tr[x].r == r)
    {
        tr[x].st = blocked;
        return;
    }
    int mid = tr[x].l + tr[x].r >> 1;
    pushdown(x);
    if(l <= mid)
        resume(x << 1,l,min(r,mid),id);
    if(r > mid)
        resume(x << 1 | 1,max(l,mid + 1),r,id);
    pushup(x);
}
int query(int x,int p)
{
    if(tr[x].l == tr[x].r)
    {
        return x;
    }else if(tr[x].st != multi && tr[x].id != multi && tr[x].val != multi)
    {
        return x;
    }else 
    {
        int mid = tr[x].l + tr[x].r >> 1; 
        pushdown(x);
        if(p <= mid)
            return query(x << 1,p);
        else 
            return query(x << 1 | 1,p);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= k;++i)
    {
        int op;
        cin >> op;
        if(op == 0)
        {
            int id,l,r,x;
            cin >> id >> l >> r >> x;
            ops[i].type = 0,ops[i].id = id,ops[i].l = l,ops[i].r = r;
            ops[i].x = x,a[++cnt] = l,a[++cnt] = r;
            if(l != 1)
                a[++cnt] = l - 1;
            if(r != m)
                a[++cnt] = r + 1;
        }else if(op == 1)
        {
            int id,l,r;
            cin >> id >> l >> r;
            ops[i].type = 1,ops[i].id = id,ops[i].l = l,ops[i].r = r;
            ops[i].x = 0,a[++cnt] = l,a[++cnt] = r;
            if(l != 1)
                a[++cnt] = l - 1;
            if(r != m)
                a[++cnt] = r + 1;
        }else if(op == 2)
        {
            int id,l,r;
            cin >> id >> l >> r;
            ops[i].type = 2,ops[i].id = id,ops[i].l = l,ops[i].r = r;
            ops[i].x = 0,a[++cnt] = l,a[++cnt] = r;
            if(l != 1)
                a[++cnt] = l - 1;
            if(r != m)
                a[++cnt] = r + 1;
        }else if(op == 3)
        {
            int p;
            cin >> p;
            ops[i].type = 3;
            ops[i].p = p;
            a[++cnt] = p;
        }
    }
    sort(a,a + cnt);
    m = unique(a,a + cnt) - a;
    // cout << m - 1 << endl;
    for(int i = 1;i <= k;++i)
    {
        // cout << ops[i].l << '-' << ops[i].r << endl;
        if(ops[i].type == 3)
        {
            ops[i].p = lower_bound(a,a + m,ops[i].p) - a;
            // cout << ops[i].p << "|";
            continue;
        }
        ops[i].l = lower_bound(a,a + m,ops[i].l) - a;
        ops[i].r = lower_bound(a,a + m,ops[i].r) - a;
        // cout << ops[i].l << '-' << ops[i].r << endl;
        // cout << "----" << endl;
    }
    // for(int i = 0;i < m;++i)
    //     cout << a[i] << '|';
    build(1,1,m - 1);
    for(int i = 1;i <= k;++i)
    {
        if(ops[i].type == 0)
        {
            ll output = write_check(1,ops[i].l,ops[i].r,ops[i].id);
            // cout << ops[i].r;
            output = min(output,ops[i].r);
            if(output == -1)
            {
                cout << -1 << '\n';
                continue;
            } 
            cout << a[output] << '\n';
            write(1,ops[i].l,output,ops[i].x,ops[i].id);
        }else if(ops[i].type == 1)
        {
            if(delet_check(1,ops[i].l,ops[i].r,ops[i].id))
            {
                cout << "OK" << endl;
                delet(1,ops[i].l,ops[i].r,ops[i].id);
            }else 
            {
                cout << "FAIL" << "\n";
            }
        }else if(ops[i].type == 2)
        {
            if(resume_check(1,ops[i].l,ops[i].r,ops[i].id))
            {
                cout << "OK" << '\n';
                resume(1,ops[i].l,ops[i].r,ops[i].id);
            }else 
            {
                cout << "FAIL" << '\n';
            }
        }else if(ops[i].type == 3)
        {
            int x = query(1,ops[i].p);
            if(tr[x].st == blocked)
                cout << tr[x].id << ' ' << tr[x].val << '\n';
            else 
                cout << 0 << ' ' << 0 << '\n';
        }
    }
}