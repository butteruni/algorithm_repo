#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll ans = n * k;
    for(ll l = 1,r = 0; l <= n;l = r + 1)
    {
        if(k / l != 0)
        {
            r = min(k / (k / l),n);
        }
        else 
        {
            r = n;
        }
        ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    cout << ans;
}