#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll a[N];
ll gap[N];
ll n,k;
bool check(ll len)
{
    ll res = 1e18;
    for(int i = 1;i <= n - len + 1;++i)
    {
       if(i == 1)
            res = min(res,gap[n - 1] - gap[len]);
        if(i == n - len + 1)
            res = min(res,gap[n - len - 1]);
        else 
            res = min(res,gap[n - 1] - gap[i + len - 1] + gap[i - 2] + abs(a[i + len] - a[i - 1]) );
        
    }
    // cout << res << " " << len << '\n';
    return res <= k;
}
void solve()
{
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i < n;++i)
    {
        gap[i] = abs(a[i] - a[i + 1]);
    }
    for(int i = 1;i < n;++i)
        gap[i] += gap[i - 1];
    ll l = 0,r = n - 1;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid;
        }else 
        {
            l = mid + 1;
        }
    }
    cout << n - r << '\n';
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