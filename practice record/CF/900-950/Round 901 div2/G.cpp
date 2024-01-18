#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double dp[3030][3030];
const long long inf = 1e18;
void print(double val)
{
    cout << fixed << setprecision(12) << val << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i <= n;++i)
    {
        for(int j = 0;j <= m;++j)
            dp[i][j] = 1e18;
    }
    dp[0][0] = 0.0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j <= m;++j)
        {
            for(int k = 1;j + k * (n - i + 1) <= m;++k)
            {
                dp[i][j + k] = min(dp[i][j + k],dp[i - 1][j] + 1.0 * j / k);
            }
        }
    }
    print(2.0 * dp[n][m] + 1.0 * n);
}