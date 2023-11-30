#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

ll dis[N];
bool vis[N];
int n,m;
struct node
{
    int ed,dis,id;
    node (ll a,ll b,ll c = 0):ed(a),dis(b),id(c){}
    bool operator < (const node b)const {
        return dis > b.dis;
    } 
};
vector<node>e[N];
void dijkstra()
{
    // ll dis[2000010];
    priority_queue<node>q;
    for(ll i = 0;i <= n;++i)
    {
        dis[i] = INF;
    }
    dis[1] = 0;
    vis[1] = 0;
    q.push(node(1,0));
    while(!q.empty())
    {       
        auto tmp = q.top();
        q.pop();
        if(vis[tmp.ed])
            continue;
        for(auto x:e[tmp.ed])
        {
            if((x.dis != tmp.id) + tmp.dis < dis[x.ed])
            {
                dis[x.ed] = (x.dis != tmp.id) + tmp.dis;
                q.push(node(x.ed,dis[x.ed],x.dis));
            }
        }
    }   


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin >> n >> m)
    {
        for(int i = 1;i <= n;++i)
            e[i].clear();
        for(int i = 1;i <= m;++i)
        {
            ll x,y,z;
            cin >> x >> y >> z;
            e[x].push_back(node(y,z,0));
            e[y].push_back(node(x,z,0));
        }
        dijkstra();
        if(dis[n] == INF)
        {
            cout << -1 << '\n';
        }else 
        {
            cout << dis[n] << '\n';
        }

    }
}   