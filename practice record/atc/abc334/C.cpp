#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
const int N = 2e5 + 10;
ll a[N];
ll pre[N];
ll suf[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= k;++i)
        cin >> a[i];
    for (int i = 2; i <= k + 1; i++)
    {
        pre[i] = pre[i - 1];
        if (i % 2 == 1)
            pre[i] += a[i - 1] - a[i - 2];
    }
    for (int i = k; i >= 1; i--)
    {
        suf[i] = suf[i + 1];
        if ((k - i) % 2 == 1)
            suf[i] += a[i + 1] - a[i];
    }
    ll ans = 1e9;
    for (int i = 1; i <= k + 1; i += 2)
    {
        ans = min(ans, pre[i] + suf[i]);
    }
    cout << ans << endl;
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