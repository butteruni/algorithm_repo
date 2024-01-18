#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
typedef pair<ll,ll>PLL;
ll gcd(ll x,ll y)
{
    if(x == 0 || y == 0)
        return max(x,y);
    return gcd(y,x % y);
}
void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    ll sum = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];

    }
    sort(a.begin(),a.end());
    if((a[0] <= k && a[n - 1] > k) || 
    (a[0] < k && a[n - 1] >= k))
    {
        cout << "-1\n";
    }else 
    {
        if(a[0] == k && a[n - 1] == k)
        {
            cout << 0 << '\n';
            return;
        }
        ll d = 0;
        for(int i = 0;i < n;++i)
        {
            a[i] -= k;
            if(a[i] < 0)
                a[i] *= - 1;
            d = gcd(d,a[i]);
        }
        // cout << d << " ";
        assert(d != 0);
        ll ans = 0;
        for(int i = 0;i < n;++i)
            ans += (a[i] / d) - 1;
        cout << ans << '\n';
    }
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