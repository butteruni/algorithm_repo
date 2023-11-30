#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll d;
    cin >> d;
    ll ans = 1e18;
    for(ll i = 0;i * i <= d;++i)
    {
        ll res = d - i * i;
        res = sqrt(res);
        ans = min(ans,min(abs(res * res + i * i - d),
        abs((res + 1) * (res + 1) + i * i - d)));
        
    }
    cout << ans << '\n';
}