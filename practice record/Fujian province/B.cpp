#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e5+10;
const int M=2e5+10;
struct Edge
{
    int u,v,w,next;
}e[M<<1];
int head[N],dist[N],cnt,len[N];
int n,m;
int T;
bool vis[N];
set<int>st[N];
queue<int>q;
void add(int u,int v,int w)
{
    ++cnt;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
    return;
}
bool spfa()
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=0x3f3f3f3f;
        st[i].clear();
        len[i]=0;
    }
    dist[n]=0;
    q.push(n);
    vis[n]=true;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].v;
            if (dist[v] > dist[u] + e[i].w)
            {
                dist[v] = dist[u] + e[i].w;
                len[v] = len[u] + 1;
                st[v].clear();
                st[v].insert(u);
                if (len[v] >= n+1) return true;       // 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
            else if(dist[v] == dist[u] + e[i].w)
            {
                st[v].insert(u);
            }
        }
    }
    return false;
}

void clear(queue<int>&Q)
{
    queue<int>temp;
    swap(temp,Q);
    return;
}

int sg[N];

int SG(int u)
{
    if(sg[u]!=-1)return sg[u];
    vector<int>p;
    for(auto x:st[u])
    {
        p.push_back(SG(x));
    }
    sort(p.begin(),p.end());
    unique(p.begin(),p.end());
    int i=0;
    for(;i<p.size()&&i==p[i];i++);
    return sg[u]=i;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)    
    {
        cnt=0;
        clear(q);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            head[i]=-1;
            sg[i]=-1;
            vis[i]=false;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        spfa();
        sg[n]=0;
        // cout<<SG(1)<<"\n";
        if(SG(1))cout<<"Little M is the winner.\n";
        else cout<<"Little I is the winner.\n";
    }
    return 0; 
}
