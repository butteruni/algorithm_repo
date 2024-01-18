#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
const int N = 1e6 + 10;
ll p[N];
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll res = n;
    for(int i = 0;i < n;++i)
        cin >> p[i];
    vector<int> s{-1};
    for (int i = 0; i < 2 * n; i++)
    {
        while (s.size() > 1 && p[i % n] < p[s.back() % n])
        {
            int x = s.back();
            s.pop_back();
            res -= 1ll * p[x % n] * (x - s.back());
        }
        res += 1ll * p[i % n] * (i - s.back());
        s.push_back(i);
        if (i >= n)
        {
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
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