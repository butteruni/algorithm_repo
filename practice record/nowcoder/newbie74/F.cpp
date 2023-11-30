#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 2e5 + 10;
int n,m;
int p[N];
int k;
vector<int> po[N];
bool vis[N];
int num = 0;
vector<pair<ll,PII> > links;
int findr(int x)
{
    if(x == p[x])
        return x;
    else 
        return p[x] = findr(p[x]);
}
bool check(ll cost)
{
    memset(vis,0,sizeof(vis));
    for(int i = 0;i <= n;++i)
        p[i] = i;
    for(int i = 0;i < links.size();++i)
    {
        auto [x,y] = links[i].second;
        if(x > y)
            swap(x,y);
        if(links[i].first > cost)
            break;
        int nx = findr(x),ny = findr(y);
        if(nx != ny)
        {
            p[nx] = p[ny];
        }
        vis[x] = 1;vis[y] = 1;
    }
    for(int i = 1;i <= k;++i)
    {
        ll root = 0;
        ll cnt_root = 0;
        for(auto j : po[i])
        {
            if(!vis[j] || cnt_root > 1)
            {
                return 0;
            }
            if(findr(p[j]) != root)
            {
                root = findr(p[j]);
                cnt_root ++;
            }
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    links.resize(m + 1);
    for(int i = 1;i <= m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a++,b++;
        links.push_back({c,{a,b}});
    }
    sort(links.begin(),links.end());
    cin >> k;
    for(int i = 1;i <= k;++i)
    {
        int s;
        cin >> s;
        for(int j = 1;j <= s;++j)
        {
            int x;
            cin >> x;
            x++;
            po[i].push_back(x);
        }
    }
    ll l = 1,r = 1e9 + 10;
    while(l < r)
    {
        ll mid = l + r >> 1;
        if(check(mid))
        {
            r = mid;
        }else 
        {
            l = mid + 1;
        }
    }
    cout << l << endl;

}