#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e7 + 10;
ll cnt[N];
void solve()
{
    ll n;
    cin >> n;
    ll tmp = n;
    ll ans = 1;
    while(tmp)
    {
        ll r = tmp % 10;
        ans *= cnt[r];
        tmp /= 10;
    }
    cout << ans << '\n';
}
int main()
{
    for(int i = 0;i <= 9;++i)
    {
        for(int j = 0;j <= 9;++j)
        {
            for(int k = 0;k <= 9;++k)
            {
                cnt[i + j + k]++;
            }
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}