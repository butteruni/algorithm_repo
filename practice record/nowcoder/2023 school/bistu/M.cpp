#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ll x;
        cin >> x;
        ans ^= x;
    }
    if(n & 1)
    {
        cout << 0 << '\n';
    }else 
    {
        cout << ans << '\n';
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