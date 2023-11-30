#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 3e3 + 10;

ll n, k;
ll dp[MAXN][MAXN][2]; // 第三维表示是否只拿一部分 1是只拿一部分，0是拿满
ll p[MAXN];
vector<ll> w[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    ll sum = 0;
    for(ll i = 1; i <= n; ++i)
    {
        cin >> p[i];
        sum += p[i];
        w[i].resize(p[i] + 1);
        for(ll j = 1; j <= p[i]; ++j)
        {
            cin >> w[i][j];
        }
    }
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j <= k;++j)
        {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            if(j >= p[i])
            {
                dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - p[i]][0] + w[i][p[i]]);
                dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - p[i]][1] + w[i][p[i]]);
            }
            for(int pos = 1;pos <= p[i];++pos)
            {
                if(j < pos)
                    break;
                dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - pos][0] + w[i][pos]);
            }
        }
    }
    if(sum <= k)
    {
        cout << dp[n][sum][0] << '\n';
    }else 
    {
        cout << max(dp[n][k][1],dp[n][k][0]) << '\n';
    }
    return 0;
}