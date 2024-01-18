#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 3e5 + 10;
int sz[N];
int p[N];
vector<int>e;
int find(int u)
{
    return p[u] == u ? u : p[u] = find(p[u]);
}
void solve()
{   
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i < n;++i)
    {
        int u,v;
        cin >> u >> v;
        if(u > v)
            swap(u,v);
        if(u == 1)
        {
            e.push_back(v);
            continue;
        }
        else 
        {
            int pu = find(u);
            int pv = find(v);
            p[pu] = pv;
            sz[pv] += sz[pu];
        }
    }
    int ans = 0;
    ll sum = 0;
    for(auto x:e)
    {
        int px = find(x);
        ans = max(ans,sz[px]);
        sum += sz[px];
    }
    ans = sum - ans;

    cout << ans + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}