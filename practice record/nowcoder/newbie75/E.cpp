#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
const ll mod = 1e9 + 7;
int a[N];
ll dp[N][N];
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;++i)
        dp[1][i] = 1;
    for(int i = 1;i < n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            ll pre = j * i;
            for(int k = (pre) / (i + 1);(k * (i + 1)) - pre <= m;++k)
            {
                if((k * (i + 1)) - pre <= 0)
                    continue;
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= m;++i)
        ans = (ans + dp[n][i]) % mod;
    cout << ans << endl;
}