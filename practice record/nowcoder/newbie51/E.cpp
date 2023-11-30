#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;++i)
    {
        ll x,y;
        cin >> x >> y;
        if(cnt == 0 || x > a[cnt])
        {
            cnt++,
            a[cnt] = x,b[cnt] = y;
        }
        // cin >> a[i] >> b[i];
    }
    ll x;
    cin >> x;
    ll ans = 0;
    for(int i = 1;i <= cnt;++i)
    {
        if(x >= a[i])
            continue;
        ll l = max(1ll,x * b[i]),r = min(a[i] - 1,(x + 1) * b[i] - 1);
        if(i > 1)
            l = max(l,a[i - 1]);
        ans += max(0ll,r - l + 1);
    }
    cout << ans << '\n';
}