#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n,m;
int tr[N];
int num[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i=x;i<=m;i+=lowbit(i))
    {
        tr[i]+=v;
    }
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
    {
        res+=tr[i];
    }
    return res;
}
struct Node
{
    int a,b,c,cnt,id;
    bool operator < (const Node& A)const
    {
        if(a!=A.a)
        {
            return a<A.a;
        }
        if(b!=A.b)
        {
            return b<A.b;
        }
        return c<A.c;
    }
    bool operator == (const Node &A)const
    {
        return a==A.a&&b==A.b&&c==A.c;
    }
}ls[N];
bool cmp(Node A,Node B)
{
    return A.b<B.b||A.b==B.b&&A.c<B.c;
}
int ans[N];
void cdq(int l,int r)
{
    // cout<<l<<"---"<<r<<"\n";
    assert(l <= r);
    if(r==l)
    {
        ans[ls[l].id]+=ls[l].cnt-1;
        return;
    }
    int mid=l+r>>1;
    cdq(l,mid);cdq(mid+1,r);
    sort(ls+l,ls+mid+1,cmp);
    sort(ls+mid+1,ls+r+1,cmp);
    int i=l,j=mid+1;
    for(;j<=r;j++)
    {
        for(;i<=mid&&ls[i].b<=ls[j].b;i++)
        {
            add(ls[i].c,ls[i].cnt);
        }               
        ans[ls[j].id]+=sum(ls[j].c);
    }
    for(int k=l;k<i;k++)
    {
        add(ls[k].c,-ls[k].cnt);
    }
}
int main()
{
    // freopen("P3810_2.in","r",stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ls[i].a>>ls[i].b>>ls[i].c;
        ls[i].cnt=1;
    }
    sort(ls+1,ls+n+1);
    int idx=1;
    ls[1].id=1;
    for(int i=2;i<=n;i++)
    {
        if(ls[i]==ls[idx])
        {
            ls[idx].cnt++;
        }
        else
        {
            ls[++idx]=ls[i];
            ls[idx].id=idx;
        }
    }
    cdq(1,idx);
    for(int i=1;i<=idx;i++)
    {
        num[ans[ls[i].id]]+=ls[i].cnt;
    }
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<"\n";
    }
    return 0;
}
