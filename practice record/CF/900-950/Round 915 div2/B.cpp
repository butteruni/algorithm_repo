#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
vector<int>e[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        e[i].clear();
    }
    for(int i = 1;i <= n - 1;++i)
    {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll cnt = 0;
    for(int i = 1;i <= n;++i)
    {
        if(e[i].size() == 1)
            cnt++;
    }
    cout << (cnt + 1) / 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}