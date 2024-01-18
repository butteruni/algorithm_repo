#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 40;
ll dp[N][N];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    memset(dp,0,sizeof(dp));
    dp[0][0]= 1;
    bool ok = 0;
    for(int i = 1;i <= n;++i)
    {
        if(s[i] == 'J')
        {
            for(int j = 0;j <= n;++j)
            {
                dp[i][j] += dp[i - 1][j]; // 挡
                dp[i][j + 1] += dp[i - 1][j]; // 集
            }
        }
        if(s[i] == 'D')
        {
            for(int j = 0;j <= n;++j)
            {
                dp[i][j] += dp[i - 1][j]; // 挡
                dp[i][j + 1] += dp[i - 1][j]; // 集
            }
        }
        if(s[i] == 'B')
        {
            for(int j = 0;j <= n;++j)
            {
                dp[i][j] += dp[i - 1][j];
                // if(j > 1)
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= 30;++i)
    {
        ans += dp[n - 1][i];
    }
    if(s[n] == 'B' || s[n] == 'D')
        ans = 0;
    cout << ans << '\n';
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