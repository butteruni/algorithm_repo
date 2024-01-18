#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 5e5 + 10;
int in[N];
void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i < n;++i)
    {
        int u,v;
        cin >> u >> v;
        in[u]++,in[v]++;
    }
    for(int i = 1;i <= n;++i)
    {
        
    }
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