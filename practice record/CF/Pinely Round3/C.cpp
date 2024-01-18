#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
typedef pair<ll, ll> PLL;
ll l[N], r[N], c[N];
ll gap[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> l[i];
    for (int i = 1; i <= n; ++i)
        cin >> r[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    sort(c + 1, c + 1 + n);
    stack<int> s;
    int p = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (l[p] < r[i] && p <= n)
        {
            s.push(l[p]);
            ++p;
        }
        gap[i] = r[i] - s.top();
        s.pop();
    }
    sort(gap + 1,gap + 1 + n);
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ans += gap[i] * c[n - i + 1];
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}