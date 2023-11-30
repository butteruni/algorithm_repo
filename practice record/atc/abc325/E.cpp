#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const int N = 3001000;
ll d[1010][1010];
ll dp1[1010][1010];
ll dp2[1010][1010];
ll n, a, b, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> a >> b >> c;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> d[i][j];
            dp1[i][j] = d[i][j] * a;
            dp2[i][j] = dp2[i][j] * b + c;
        }
    }
    for (int k = 1; k <= n; k++)
    { 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp1[i][j] > dp1[i][k] + dp1[k][j])
                {
                    dp1[i][j] = dp1[i][k] + dp1[k][j]; 
                }
                if (dp2[i][j] > dp2[i][k] + dp2[k][j])
                {
                    dp2[i][j] = dp2[i][k] + dp2[k][j]; 
                }
            }
        }
    }

    ll ans = 1e18;
    for(int i = 1;i <= n;++i)
    {
        ans = min(ans,dp1[1][i] + dp2[i][n]);
    }
    cout << ans << '\n';
}
