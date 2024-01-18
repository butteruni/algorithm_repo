#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll a[N];
ll aft[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    aft[n + 1] = 0;
    for(int i = n;i >= 1;--i)
    {
        aft[i] = a[i];
        aft[i] += aft[i + 1];
        // cout << aft[i] << " ";
    }
    ll ans = 0;
    ll idx = 1;
    for(int i = 1;i <= n;++i)
    {
        ans += a[i] * idx;
        if(aft[i + 1] > 0)
        {
            idx++;
            // cout << i << " " << aft[i + 1] << " ";
        }
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