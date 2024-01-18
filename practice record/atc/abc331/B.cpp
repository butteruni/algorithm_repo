#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 300;
ll dp[N];
void solve()
{
    ll n,s,m,l;
    cin >> n >> s >> m >> l;
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i <= n;++i)
    {
        dp[i] = min(dp[max(0,i - 6)] + s,dp[i]);
        dp[i] = min(dp[max(0,i - 8)] + m,dp[i]);
        dp[i] = min(dp[max(0,i - 12)] + l,dp[i]);
    }
    cout << dp[n] << '\n';
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