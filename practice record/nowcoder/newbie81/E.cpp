#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll c[N],h[N];
ll n,m;
ll cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    ll mx = 0;
    ll mn = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> h[i] >> c[i];
        cnt[h[i]]++;
        cnt[c[i] - 1]--;
    }
    for(int i = N - 1;i >= 0;--i)
    {
        cnt[i] += cnt[i + 1];
    }
    ll ans = 0;
    for(ll i = N - 1;i >= 0;--i)
    {
        if(cnt[i] == 0)
            continue;
        if(m > cnt[i])
        {
            m -= cnt[i];
            ans += 2ll * cnt[i] * i - 1;
        }else
        {
            ans += m * i - 1;
        }
    }
    cout << ans << '\n';
}