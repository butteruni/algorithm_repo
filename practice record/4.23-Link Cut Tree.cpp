//洛谷P3690
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,m;
struct Node
{
    int s[2], p, v;
    int sum,rev; 
}tr[N];
int stk[N];
void pushrev(int x)
{
    swap(tr[x].s[0],tr[x].s[1]);
    tr[x].rev ^= 1;   
}
void pushup(int x)
{
    tr[x].sum = tr[tr[x].s[0]].sum ^ tr[tr[x].s[1]].sum ^ tr[x].v;
}
void pushdown(int x)
{
    if(tr[x].rev)
    {
        pushrev(tr[x].s[0]);
        pushrev(tr[x].s[1]);
        tr[x].rev = 0;
    }
}
bool is_root(int x)
{
    return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
}
void rotate(int x)
{
    int y = tr[x].p,z = tr[y].p;
    int k = tr[y].s[1] == x;
    if(!is_root(y))
    {
        tr[z].s[tr[z].s[1] == y] = x;
    }
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1],tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y,tr[y].p = x;
    pushup(y),pushup(x);
}
void splay(int x)
{
    int top = 0, r = x;
    stk[++top] = r;
    while(!is_root(r))
    {
        stk[++top] = r = tr[r].p;
    }
    while(top)
    {
        pushdown(stk[top--]);
    }
    while(!is_root(x))
    {
        int y = tr[x].p,z = tr[y].p;
        if(!is_root(y))
        {
            if((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
            {
                rotate(x);
            }else  
            {
                rotate(y);
            }
        }
        rotate(x);
    }
}
void access(int x) //建立一条根到x的路径，并将x变为splay根节点
{
    int z = x;
    for(int y = 0;x;y = x,x = tr[x].p)
    {
        splay(x);
        tr[x].s[1] = y;
        pushup(x);
    }
    splay(z);
}
void make_root(int x) //将x变成原树的根节点
{
    access(x);
    pushrev(x);
}
int find_root(int x) //找到x所在树的根节点,再将根节点旋转到splay根节点
{
    access(x);
    while(tr[x].s[0])
    {
        pushdown(x);
        x = tr[x].s[0];
    }
    splay(x);
    return x;
}
void split(int x,int y)//给x和y之间的路径建立一个splay，其根节点是y
{
    make_root(x);
    access(y);
}
void link(int x,int y) //若x和y不连通，加入一条x和y之间的边
{
    make_root(x);
    if(find_root(y) != x)
    {
        tr[x].p = y;
    }
}
void cut(int x,int y)//若x和y之间存在边，则删除该边
{
    make_root(x);
    if(find_root(y) == x && tr[y].p == x && !tr[y].s[0])
    {
        tr[x].s[1] = tr[y].p = 0;
        pushup(x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> tr[i].v;
    }
    while(m--)
    {
        int op,x,y;
        cin >> op >> x >> y;
        if(op == 0)
        {
            split(x,y);
            cout << tr[y].sum << '\n';
        }else if(op == 1)
        {
            link(x, y);
        }else if(op == 2)
        {
            cut(x, y);
        }else 
        {
            splay(x);
            tr[x].v = y;
            pushup(x);
        }
    }
    return 0;
}