#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll a[N],b[N];
ll dp[N];
ll cnt[N];
void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
        cin >> b[i];
    for(int i = 1;i <= n;++i)
    {
        b[i] = max(b[i],b[i - 1]);
        a[i] += a[i - 1];
    }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        if(i > k)
            break;
        ll cur_ans = a[i];
        ll res = k - i;
        cur_ans = cur_ans + res * b[i];
        ans = max(ans,cur_ans);
    }
    cout << ans << '\n';

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}