#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1e18;
    for (int i = 2; i <= n; ++i)
    {
        ll x = 1;
        ll y = i;
        ll tmp = i - 2;
        while (2 * y - x <= n)
        {
            ll nx = 2 * y - x;
            x = y;
            y = nx;
            ++tmp;
        }
        if (y < n)
        {
            while (2 * y - x > n)
            {
                ++tmp;
                ++x;
            }
            ll nx = 2 * y - x;
            x = y;
            y = nx;
            ++tmp;
        }
        tmp += n - y;
        tmp += n - 1 - x;
        ans = min(ans, tmp);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}