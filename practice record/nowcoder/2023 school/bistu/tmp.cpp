#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e3 + 10;
ll a[N][N];
ll b[N][N];
ll dp[N][N];
void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    for(int i = 1;i <= m;++i)
    {
        sort(b[i] + 1,b[i] + 1 + n);
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i = 0;i <= n;++i)
        dp[i][0] = 0;
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            ll pre = dp[i - 1][j - 1];
            // cout << pre << " ";
            if(b[i][n] <= pre)
            {
                continue;
            }
            ll l = 1,r = n;
            while(l < r)
            {
                ll mid = (l + r) >> 1;
                // cout << mid << endl;
                if(b[i][mid] > pre)
                {
                    r = mid;
                }else 
                {
                    l = mid + 1;
                }
            }
            ll cur = b[i][r];
            dp[i][j] = min(dp[i][j],cur);
        }
    }

    ll ans = 0;
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            if(dp[i][j] != 0x3f3f3f)
            {
                ans = max(ans,(ll)j);
            }
        }
    }
    cout << ans << '\n';
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