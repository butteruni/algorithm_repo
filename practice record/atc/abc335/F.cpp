#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
const ll mod = 998244353;
ll a[N];
ll cnt[N];
ll dp[N];
int n;
// ll dfs(int u)
// {
//     if(cnt[u] != 0)
//     {
//         return cnt[u];
//     }
//     cnt[u] = 1;
//     int st = u + a[u];
//     while(st <= n)
//     {
//         cnt[u] = (cnt[u] + dfs(st)) %mod;
//         st += a[u];
//     } 
//     return cnt[u];
// }
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    dp[1] = 1;
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = i + a[i];j <= n;j += a[i])
        {
            dp[j] = (dp[j] + dp[i]) % mod;
            if(a[i] == a[j])
            {
                dp[j] = (dp[i] + dp[j]) % mod;
                ans = (ans - dp[i] % mod);
                break;
            }
        }
    }
    for(int i = 1;i <= n;++i)
        ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
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