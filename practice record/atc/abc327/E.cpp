#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
double pp[N];
double pre[N];
double p[N];
double dp[5050][5050];
int id[N];
bool cmp(int x,int y)
{
    return p[x] > p[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    pp[0] = 1.0;
    for(int i = 1;i <= n;++i)
    {
        pp[i] = pp[i - 1] * 0.9;
        cin >> p[i];
    }
    pre[0] = 1;
    for(int i = 1;i <= n;++i)
    {
        pre[i] += pre[i - 1] + pp[i];
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j <= n;++j)
        {
            dp[i][j] = -1e18;
        }
    }
    for(int i = n;i >= 1 ;--i)
    {
        if(i == n)
        {
            dp[n][0] = 0;
            dp[n][1] = p[i];
        }else
        {
            for(int j = 0;j + i <= n + 1;++j)
            {
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - 1] + p[i] * pp[j - 1]);
            }
        }
    }
    double ans = -1e18;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j <= n;++j)
        {
            if(j != 0)
                ans = max(ans,dp[i][j] / pre[j - 1] - 1200 / sqrt(double(j)));
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";
}