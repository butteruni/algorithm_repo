#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
int n;
ll a[N];
ll l[N],r[N];

void solve()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i)
    {
        l[i] = min(l[i - 1] + 1,a[i]);
    }
    for(int i = 1;i <= n;++i)
    {
        r[i] = min(r[i - 1] + 1,a[n - i + 1]);
    }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
        ans = max(ans,min(l[i],r[n - i + 1]));
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