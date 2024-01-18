#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll p[N];
ll x[N];
map<ll,ll>mp;
void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> p[i];
    for(int i = 1;i <= m;++i)
        cin >> x[i];
    sort(x + 1,x + 1 + m);
    mp.clear();
    x[m + 1] = 1e18;
    x[0] = -1e18;
    for(int i = 1;i <= n;++i)
    {
        int loca = (i - 1) * 100;
        int t = lower_bound(x,x + 2 + m,loca) - x;
        int r = t,l = t - 1;
        ll dis = min(x[r] - loca,loca - x[l]);
        mp[loca - dis] += p[i];
        mp[loca + dis] -= p[i];
    }
    ll ans = 0,st = 0;
    for(auto [x,y]:mp)
    {
        st += y;
        ans = max(ans,st);
    }
    cout << ans << '\n';
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