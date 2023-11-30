#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
int e[N << 1],ne[N << 1],w[N << 1],idx;
int h[N];
int dis[N],cnt[N];
bool vis[N];
int n,m;
void add(int a,int b,int c)
{
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}
bool spfa()
{
    memset(dis,0x3f,sizeof(dis));
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
            if(dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) 
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i = 1;i <= n;++i)
    {
        add(0,i,0);
    }
    for(int i = 1;i <= m;++i)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int a,b,c;
            cin >> a >> b >> c;
            add(a,b,-c);
        }else if(type == 2)
        {
            int a,b,c;
            cin >> a >> b >> c;
            add(b,a,c);
        }else 
        {
            int a,b;
            cin >> a >> b;
            add(a,b,0);
            add(b,a,0);
        }
    }
    if(spfa())
    {
        cout << "Yes\n";
    }else 
    {
        cout << "No\n";
    }
}