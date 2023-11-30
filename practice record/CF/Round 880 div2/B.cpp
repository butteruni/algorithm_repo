#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long ll;
int a[N];
int cnt[N];
ll n,k,g;
ll get(ll x)
{
    ll r = x % g;
    if(r >= g / 2)
        return x + (g - r);
    else 
        return x - r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;

    cin >> t;
    while(t--)
    {
        cin >> n >> k >> g;
        ll ans = min((g - 1) / 2 * n,k * g);
        ll res = (k * g - ans ) % g;
        if(res > 0)
        {
            ans -= (g - 1) / 2;
            if(2 * ((res + (g - 1) / 2) % g) < g)
            {
                ans += ((res + (g - 1) / 2) % g);
            }else 
            {
                ans -= g - ((res + (g - 1) / 2) % g);
            }
        }
        cout << ans << '\n';
    }
}