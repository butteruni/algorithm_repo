#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,t;
int a[N];
int dp[N];
int cnt[N];
int mx[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll ans = 0;
        memset(cnt,0,sizeof(cnt));
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        memset(mx,0x3f3f3f,sizeof(mx));
        for(int i = 1;i <= n;++i)
        {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i],i - mx[a[i]]);
            mx[a[i]] = min(mx[a[i]],-dp[i - 1] + (i - 1));
        }
        cout << dp[n] << '\n';
    }
}