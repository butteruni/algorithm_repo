#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
double dp[N][2][2];
void solve()
{
    int n;
    cin >> n;
    double x;int y;
    cin >> x >> y;
    x /= 100.0;
    vector<double>a(n + 1);
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        dp[i][0][0] = a[i];
        dp[i][0][0] += dp[i - 1][0][0];
    }
    double ans = 1e18;
    for(int i = 1;i <= n;++i)
    {
        dp[i][1][0] = min(dp[i - 1][0][0] + a[i] * x,dp[i - 1][1][0] + a[i]);
        dp[i][0][1] = min(dp[i - 1][0][0] + max(0.0,a[i] - y),dp[i - 1][0][1] + a[i]);
        dp[i][1][1] = min(dp[i - 1][1][1] + a[i],min(dp[i - 1][0][1] + a[i] * x,dp[i - 1][1][0] + max(0.0,a[i] - y)));
        // cout << dp[i][0][0] << " " << dp[i][1][0] << " " << dp[i][0][1] << " " << dp[i][1][1] << '\n';
    }
    ans = min(dp[n][1][0],min(dp[n][1][1],dp[n][0][1]));
    cout << fixed << setprecision(10) << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}