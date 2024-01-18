#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1010;
ll a[N][N];
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cin >> a[i][j];
            if(i % 2 == j % 2)
            {
                ans += a[i][j];
                a[i][n + 1] += a[i][j];
                a[n + 1][j] += a[i][j];
            }else 
            {
                ans -= a[i][j];
                a[i][n + 1] -= a[i][j];
                a[n + 1][j] -= a[i][j];
            }
        }
    }
    ll add = -1e18;
    for(int i = 1;i <= n;++i)
    {
        add = max(add,abs(a[i][n + 1]));
    }
    cout << ans + add << '\n';
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}