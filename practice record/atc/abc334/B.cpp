#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    ll ans = 0;
    r -= a,l -= a;
    ll rr = (r%m + m) % m;
    ll lr = (l%m + m) % m;
    ans = (r - rr) / m - (l - 1 - lr) / m; 
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