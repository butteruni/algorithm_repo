#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 16;
double w[N];
double dp[1 << N][N];
void solve()
{
    ll d,n;
    cin >> n >> d;
    double x = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> w[i];
        x += w[i];
    }
    // sort(w + 1,w + 1 + n,greater());

    x /= d;
    for(int i = 0;i < (1 << n);++i)
    {
        double st = 0;
        for(int j = 0;j < n;++j)
        {
            if((i >> j) & 1)
                st += w[j + 1];
        }
        dp[i][1] = (st - x) * (st - x);
        for(int j = 2;j <= d;++j)
        {
            dp[i][j] = dp[i][j - 1] + x * x;
            ll cur = i;
            while(cur > 0)
            {
                dp[i][j] = min(dp[i][j],dp[i - cur][j - 1] + dp[cur][1]);
                cur = (cur - 1) & i;
            }
        }
    }
    cout << fixed << setprecision(12) << (dp[(1 << n) - 1][d] / d) << '\n';

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