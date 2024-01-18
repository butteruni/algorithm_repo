#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e5 + 10;
ll a[N];
ll b[N];
ll p[70];
ll n,q;
void solve()
{
    cin >> n >> q;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= q;++i)
    {
        ll ans = 0;
        for(int j = 1;j <= n;++j)
            b[j] = a[j];
        ll x;
        cin >> x;
        for(ll j = 60;j >= 0;--j)
        {
            ll need = 0;
            for(ll k = 1;k <= n;++k)
            {
                if((b[k] >> j) & 1)
                    continue;
                need += p[j] - (b[k] % p[j]);
                if(need > x)
                    break;
            }
            // cout << need << " ";
            if(x >= need)
            {
                x -= need;
                ans += p[j];
                for(int k = 1;k <= n;++k)
                {
                    if((b[k] >> j) & 1)
                        continue;
                    b[k] += p[j] - (b[k] % p[j]);
                  
                }
            }
        }
        cout << ans << '\n';
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    for(ll i = 0;i <= 60;++i)
    {
        p[i] = 1ll << i; 
    }
    p[0] = 1;
    while(t--)
    {
        solve();
    }
}