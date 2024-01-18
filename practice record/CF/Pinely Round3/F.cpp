#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll mod = 998244353;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n + 1,0);
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    bool ok = 1;
    vector<ll>gap(n + 1);
    for(int i = 1;i <= n;++i)
    {
        gap[i] = a[i] - a[i - 1];
        if(gap[i] > 2 || a[i] > i || gap[i] < 0)
            ok = 0;
    }
    if(!ok || a[n] != n)
    {
        cout << 0 << '\n';
        return;
    }else 
    {
        ll ans = 1;
        int cnt = 0; // 还没填的
        for(int i = 1;i <= n;++i)
        {
            cnt++;
            if(gap[i] == 2)
            {
                ans = ans * (i - 1 - a[i - 1]) % mod * (cnt - 1) % mod;
            }else if(gap[i] == 1)
            {
                ans = ans * (i - 1 - a[i - 1] + cnt) % mod;
            }
            cnt -= gap[i];
        }
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