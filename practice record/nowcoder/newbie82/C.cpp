#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
const ll mod = 998244353;
const int N = 2e5 + 10;
ll dp[N][5];
ll ans[N];
ll qpow(ll a, ll b)
{
    if (b <= 0)
        return 1;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll st = 26;
    ll sum = 0;
    ll add = 0;
    dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        ans[i] = (ans[i - 1] * 26ll + dp[i - 1][2]) % mod;
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][2]) * 25ll + dp[i - 1][1] * 24ll) % mod;
        dp[i][1] = (0ll + dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][2] = dp[i - 1][1];
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}