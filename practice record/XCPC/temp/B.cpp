#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10,M = 3e5 + 10;
int h[N],e[M<<1],ne[M<<1],idx,w[M<<1];
int tmph[N];
int dis[N],cnt[N];
bool vis[N];
int n,k,m1,m2;
int tmpidx;
void add(int a,int b,int c)
{
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

int l1[M],r1[M],c1[M];
int l2[M],r2[M],c2[M];

bool spfa()
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=0x3f3f3f3f;
        vis[i]=false;
        cnt[i]=0;
    }
    dis[0] = 0;
    queue<int>q;
    vis[0] = true;
    q.push(0);
    while(q.size())
    {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for(int i = h[t];i != -1;i = ne[i])
        {
            int j = e[i];
            if(dis[t] + w[i] < dis[j])
            {
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (dis[j] < 0)
                    return false;
                if (cnt[j] >= n + 1) 
                    return false;
                if (!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    return true;
}

bool check(int val)
{
    memcpy(h,tmph,sizeof(int)*(n+1));
    idx=tmpidx;
    for(int i=1;i<=m2;i++)
    {
        add(l2[i]-1,r2[i],val-c2[i]);
    }
    add(0,n,val);
    add(n,0,-val);
    return spfa();
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        
        idx=0;
        cin>>n>>m1>>m2;
        for(int i=0;i<=n;i++)
        {
            h[i]=-1;
            tmph[i]=-1;
        }
        for(int i=1;i<=m1;i++)
        {
            cin>>l1[i]>>r1[i]>>c1[i];
            add(r1[i],l1[i]-1,-c1[i]);
        }
        for(int i=1;i<=m2;i++)
        {
            cin>>l2[i]>>r2[i]>>c2[i];
        }
        for(int i=1;i<=n;i++)
        {
            add(i-1,i,1);
            add(i,i-1,0);
        }
        tmpidx=idx;
        memcpy(tmph,h,sizeof(int)*(n+1));
        int l=0,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
    }
}
