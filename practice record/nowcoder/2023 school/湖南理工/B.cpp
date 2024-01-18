#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n;
    cin >> n;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3 = n - x1 + 1,y3 = n - y1 + 1;
    ll ans = abs(x1 - x2) + abs(y2 - y1);
//     cout << ans << " ";
    ans = min(ans,abs(x2 - x3) + abs(y2 - y3) + 1);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}