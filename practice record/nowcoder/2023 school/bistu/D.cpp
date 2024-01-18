#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e3 + 10;
ll a[N][N];
ll b[N][N];
ll dp[N][N]; // 走到第i列，得到的长度为j的序列最后一个数的大小
void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j) // 转置后方便排序
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
    for(int i = 0;i <= m;++i)  //初始状态
        dp[i][0] = 0;
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= i;++j)
        {
            ll pre = dp[i - 1][j - 1];
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
            dp[i][j] = min(dp[i][j],dp[i - 1][j]); // 这一列不取数
            dp[i][j] = min(dp[i][j],cur); // 这一列取数
        }
    }
    ll ans = 0;
    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= i;++j)
        {
            if(dp[i][j] <= 1e9)
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